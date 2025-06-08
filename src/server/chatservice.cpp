#include "chatservice.hpp"
#include <iostream>

ChatService &ChatService::getInstance()
{
    static ChatService instance;
    return instance;
}

void ChatService::reset()
{
    userModel_.resetState();
}

logicFunc ChatService::getHandler(EnMsgType msgid)
{
    // 记录错误日志
    auto it = handlerMap_.find(msgid);
    if (it == handlerMap_.end())
    {
        return [=](const muduo::net::TcpConnectionPtr &conn, json &msg,
                   muduo::Timestamp)
        {
            std::cout << "msgid:" << static_cast<int>(msgid) << "找不到对应的消息处理函数" << std::endl;
        };
    }
    return handlerMap_[msgid];
}

ChatService::ChatService()
{
    handlerMap_.emplace(EnMsgType::LOGIN_MSG,
                        std::bind(&ChatService::loginLogic,
                                  this,
                                  std::placeholders::_1,
                                  std::placeholders::_2,
                                  std::placeholders::_3));

    handlerMap_.emplace(EnMsgType::REG_MSG,
                        std::bind(&ChatService::registerLogic,
                                  this,
                                  std::placeholders::_1,
                                  std::placeholders::_2,
                                  std::placeholders::_3));

    handlerMap_.emplace(EnMsgType::CHAT_MSG,
                        std::bind(&ChatService::sendMessage,
                                  this,
                                  std::placeholders::_1,
                                  std::placeholders::_2,
                                  std::placeholders::_3));
}

// 处理注册操作
void ChatService::registerLogic(const muduo::net::TcpConnectionPtr &conn,
                                json &msg,
                                muduo::Timestamp)
{
    std::string name = msg["name"].get<std::string>();
    std::string password = msg["password"].get<std::string>();
    User user;
    user.set_name(name);
    user.set_password(password);

    bool state = userModel_.addUser(user);
    if (state)
    {
        json res;
        res["msgid"] = static_cast<int>(EnMsgType::REG_MSG);
        res["errno"] = 0;
        res["id"] = user.get_id();
        conn->send(res.dump());
    }
    else
    {
        json res;
        res["msgid"] = static_cast<int>(EnMsgType::REG_MSG);
        res["errno"] = -1;
        conn->send(res.dump());
    }
}

// 处理登录业务
void ChatService::loginLogic(const muduo::net::TcpConnectionPtr &conn,
                             json &msg,
                             muduo::Timestamp)
{
    int id = msg["id"].get<int>();
    std::string password = msg["password"].get<std::string>();

    User user;
    user.set_id(id);

    // 如果用户存在且密码正确且未登录
    if (userModel_.queryUser(user) && user.get_password() == password)
    {
        if (user.get_state() == "online")
        {
            json res;
            res["msgid"] = static_cast<int>(EnMsgType::LOGIN_MSG);
            res["errno"] = -1;
            res["info"] = "用户已在线";
            conn->send(res.dump());
        }
        else
        {
            {
                std::lock_guard<std::mutex> lock(connMapmtx_);
                connMap_.insert(std::make_pair(id, conn));
            }
            user.set_state("online");
            userModel_.updateState(user);
            json res;
            res["msgid"] = static_cast<int>(EnMsgType::LOGIN_MSG);
            res["errno"] = 0;
            res["offlineMsg"] = offlineMsgModel_.query(id);
            res["info"] = "登录成功";
            offlineMsgModel_.remove(id);
            conn->send(res.dump());
        }
    }
    else
    {
        json res;
        res["msgid"] = static_cast<int>(EnMsgType::LOGIN_MSG);
        res["errno"] = -1;
        res["info"] = "密码错误";
        conn->send(res.dump());
    }
}

// 处理用户放松消息逻辑
void ChatService::sendMessage(const muduo::net::TcpConnectionPtr &conn,
                              json &msg,
                              muduo::Timestamp)
{
    int toid = msg["to"].get<int>();
    std::string content = msg["msg"].get<std::string>();
    {
        // 在使用conn时需要加锁
        std::lock_guard<std::mutex> lock(connMapmtx_);
        auto it = connMap_.find(toid);
        if (it != connMap_.end())
        {
            json res;
            res["msgid"] = content;
            it->second->send(res.dump());
            return;
        }
    }
    // 说明用户没在线，存入offlineMsg中
    offlineMsgModel_.insert(toid, content);
}

//  处理用户异常退出
void ChatService::clientCloseExcception(const muduo::net::TcpConnectionPtr &conn)
{
    User user;
    {
        std::lock_guard<std::mutex> lock(connMapmtx_);
        for (auto it = connMap_.begin(); it != connMap_.end(); ++it)
        {
            if (it->second == conn)
            {
                user.set_id(it->first);

                connMap_.erase(it);
                break;
            }
        }
    }
    std::cout << "用户" << user.get_id() << "退出聊天室" << std::endl;
    user.set_state("offline");
    userModel_.updateState(user);
}