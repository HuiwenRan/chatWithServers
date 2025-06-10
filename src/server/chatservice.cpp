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

    handlerMap_.emplace(EnMsgType::LOGOUT_MSG,
                        std::bind(&ChatService::logoutLogic,
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
    handlerMap_.emplace(EnMsgType::ADDFRIEND_MSG,
                        std::bind(&ChatService::addFriend,
                                  this,
                                  std::placeholders::_1,
                                  std::placeholders::_2,
                                  std::placeholders::_3));
    handlerMap_.emplace(EnMsgType::CREATEGROUP_MSG,
                        std::bind(&ChatService::createGroup,
                                  this,
                                  std::placeholders::_1,
                                  std::placeholders::_2,
                                  std::placeholders::_3));
    handlerMap_.emplace(EnMsgType::JOINGROUP_MSG,
                        std::bind(&ChatService::joinGroup,
                                  this,
                                  std::placeholders::_1,
                                  std::placeholders::_2,
                                  std::placeholders::_3));
    handlerMap_.emplace(EnMsgType::CHATGOURP_MSG,
                        std::bind(&ChatService::chatGroup,
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

void to_json(json &j, const GroupUser &groupuser)
{
    j = json({{"userid", groupuser.get_id()}, {"username", groupuser.get_name()}, {"state", groupuser.get_state()}, {"role", groupuser.getGrouprole()}});
}
void to_json(json &j, const Group &group)
{
    j = json({{"groupname", group.GetName()}, {"groupdesc", group.GetDescription()}, {"id", group.GetId()}, {"users", group.GetUsers()}});
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
            res["info"] = "this user is online";
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
            res["id"] = id;
            res["name"] = user.get_name();
            res["errno"] = 0;
            res["offlinemsg"] = offlineMsgModel_.query(id);
            res["friends"] = friendModel_.query(id);
            res["groups"] = groupModel_.queryGroups(id);
            res["info"] = "login success";
            offlineMsgModel_.remove(id);
            conn->send(res.dump());
        }
    }
    else
    {
        json res;
        res["msgid"] = static_cast<int>(EnMsgType::LOGIN_MSG);
        res["errno"] = -1;
        res["info"] = "password error or user not exist";
        conn->send(res.dump());
    }
}

void ChatService::logoutLogic(const muduo::net::TcpConnectionPtr &conn,
                              json &msg,
                              muduo::Timestamp)
{
    int id = msg["id"].get<int>();
    User user;
    user.set_id(id);
    user.set_state("offline");
    userModel_.updateState(user);
    std::lock_guard<std::mutex> lock(connMapmtx_);
    auto it = connMap_.find(id);
    if (it != connMap_.end())
    {
        connMap_.erase(it);
    }
}

// 处理用户放松消息逻辑
void ChatService::sendMessage(const muduo::net::TcpConnectionPtr &conn,
                              json &msg,
                              muduo::Timestamp)
{
    int toid = msg["toid"].get<int>();
    {
        // 在使用conn时需要加锁
        std::lock_guard<std::mutex> lock(connMapmtx_);
        auto it = connMap_.find(toid);
        if (it != connMap_.end())
        {
            it->second->send(msg.dump());
            return;
        }
    }
    // 说明用户没在线，存入offlineMsg中
    offlineMsgModel_.insert(toid, msg.dump());
}

void ChatService::addFriend(const muduo::net::TcpConnectionPtr &conn,
                            json &msg,
                            muduo::Timestamp)
{
    int userid = msg["id"].get<int>();
    int friendid = msg["friendid"].get<int>();
    if (friendModel_.insert(userid, friendid) && friendModel_.insert(friendid, userid))
    {
        json res;
        res["msgid"] = static_cast<int>(EnMsgType::ADDFRIEND_MSG);
        res["errno"] = 0;
        conn->send(res.dump());
    }
}

// 处理创建群组
void ChatService::createGroup(const muduo::net::TcpConnectionPtr &conn,
                              json &msg,
                              muduo::Timestamp)
{
    int userid = msg["id"].get<int>();
    std::string groupname = msg["groupname"].get<std::string>();
    std::string groupdesc = msg["groupdesc"].get<std::string>();
    Group group;
    group.SetId(userid);
    group.SetName(groupname);
    group.SetDescription(groupdesc);
    if (groupModel_.createGroup(group))
    {
        if (groupModel_.addGroup(userid, group.GetId(), "creator"))
        {
            json res;
            res["msgid"] = static_cast<int>(EnMsgType::CREATEGROUP_MSG);
            res["errno"] = 0;
            res["groupid"] = group.GetId();
            conn->send(res.dump());
        }
    }
}

// 处理加入群组
void ChatService::joinGroup(const muduo::net::TcpConnectionPtr &conn,
                            json &msg,
                            muduo::Timestamp)
{
    int userid = msg["id"].get<int>();
    int groupid = msg["groupid"].get<int>();
    if (groupModel_.addGroup(userid, groupid, "normal"))
    {
        json res;
        res["msgid"] = static_cast<int>(EnMsgType::JOINGROUP_MSG);
        res["errno"] = 0;
        conn->send(res.dump());
    }
}

// 处理群组聊天
void ChatService::chatGroup(const muduo::net::TcpConnectionPtr &conn,
                            json &msg,
                            muduo::Timestamp)
{
    int userid = msg["id"].get<int>();
    int groupid = msg["groupid"].get<int>();
    std::vector<int> receiverIds = groupModel_.queryGroupUsers(userid, groupid);
    for (auto receiverid : receiverIds)
    {
        std::lock_guard<std::mutex> lock(connMapmtx_);
        auto it = connMap_.find(receiverid);
        if (it != connMap_.end())
        {
            it->second->send(msg.dump());
        }
        else
        {
            offlineMsgModel_.insert(receiverid, msg.dump());
        }
    }
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