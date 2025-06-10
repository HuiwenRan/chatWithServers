#ifndef CHATSERVICE_H
#define CHATSERVICE_H
#include <unordered_map>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/EventLoop.h>
#include <functional>
#include <mutex>

#include "json.hpp"
#include "public.hpp"
#include "usermodel.hpp"
#include "friendmodel.hpp"
#include "offlinemsgmodel.hpp"
#include "groupmodel.hpp"

using json = nlohmann::json;

// 处理消息的时间回调方法类型
using logicFunc = std::function<void(const muduo::net::TcpConnectionPtr &,
                                     json &,
                                     muduo::Timestamp)>;

// 存储业务代码
class ChatService
{
public:
    static ChatService &getInstance();

    logicFunc getHandler(EnMsgType msgid);
    void clientCloseExcception(const muduo::net::TcpConnectionPtr &conn);
    void reset();

private:
    ChatService();
    // 禁用拷贝和移动
    ChatService(const ChatService &) = delete;
    ChatService &operator=(const ChatService &) = delete;
    ChatService(ChatService &&) = delete;
    ChatService &operator=(ChatService &&) = delete;

    void registerLogic(const muduo::net::TcpConnectionPtr &conn,
                       json &msg,
                       muduo::Timestamp);

    void loginLogic(const muduo::net::TcpConnectionPtr &conn,
                    json &msg,
                    muduo::Timestamp);
    void logoutLogic(const muduo::net::TcpConnectionPtr &conn,
                     json &msg,
                     muduo::Timestamp);
    void sendMessage(const muduo::net::TcpConnectionPtr &conn,
                     json &msg,
                     muduo::Timestamp);
    void addFriend(const muduo::net::TcpConnectionPtr &conn,
                   json &msg,
                   muduo::Timestamp);
    void createGroup(const muduo::net::TcpConnectionPtr &conn,
                     json &msg,
                     muduo::Timestamp);
    void joinGroup(const muduo::net::TcpConnectionPtr &conn,
                   json &msg,
                   muduo::Timestamp);
    void chatGroup(const muduo::net::TcpConnectionPtr &conn,
                   json &msg,
                   muduo::Timestamp);
    std::unordered_map<EnMsgType, logicFunc> handlerMap_;

private:
    std::unordered_map<int, muduo::net::TcpConnectionPtr> connMap_;
    std::mutex connMapmtx_;
    UserModel userModel_;
    OfflineMsgModel offlineMsgModel_;
    FriendModel friendModel_;
    GroupModel groupModel_;
};

#endif