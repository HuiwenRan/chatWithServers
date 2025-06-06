#include "chatservice.hpp"
#include <iostream>

ChatService &ChatService::getInstance()
{
    static ChatService instance;
    return instance;
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
            user.set_state("online");
            userModel_.updateUser(user);
            json res;
            res["msgid"] = static_cast<int>(EnMsgType::LOGIN_MSG);
            res["errno"] = 0;
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
