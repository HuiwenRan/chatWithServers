#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <string>
#include <functional>
#include <iostream>

#include "json.hpp"
#include "public.hpp"
#include "chatservice.hpp"

using json = nlohmann::json;

class ChatServer
{
public:
    ChatServer(muduo::net::EventLoop *loop,
               const muduo::net::InetAddress &listenAddr,
               const std::string &nameArg)
        : server_(loop, listenAddr, nameArg)
    {
        server_.setConnectionCallback(bind(&ChatServer::connectionCallback, this, std::placeholders::_1));
        server_.setMessageCallback(bind(&ChatServer::messageCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

        server_.setThreadNum(4); // 容易忘记
    }
    void start();

private:
    void connectionCallback(const muduo::net::TcpConnectionPtr &);
    void messageCallback(const muduo::net::TcpConnectionPtr &,
                         muduo::net::Buffer *,
                         muduo::Timestamp);

private:
    muduo::net::TcpServer server_;
};

void ChatServer::start()
{
    server_.start();
}

void ChatServer::connectionCallback(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        conn->shutdown();
    }
}

void ChatServer::messageCallback(const muduo::net::TcpConnectionPtr &conn,
                                 muduo::net::Buffer *buffer,
                                 muduo::Timestamp time)
{
    std::string buf = buffer->retrieveAllAsString();

    try
    {
        // 尝试解析JSON，可能抛出异常
        json j = json::parse(buf);

        // 获取消息处理函数
        auto msgHandler = ChatService::getInstance().getHandler(j["msgid"].get<EnMsgType>());
        msgHandler(conn, j, time);
    }
    catch (const json::parse_error &e)
    {
        // 处理JSON解析错误
        std::cerr << "JSON解析错误: " << e.what() << std::endl;
        conn->shutdown(); // 关闭连接
    }
    catch (const std::out_of_range &e)
    {
        // 处理msgid不存在的情况
        std::cerr << "消息类型不存在: " << e.what() << std::endl;
        conn->shutdown();
    }
    catch (const std::exception &e)
    {
        // 处理其他标准异常
        std::cerr << "标准异常: " << e.what() << std::endl;
        conn->shutdown();
    }
    catch (...)
    {
        // 处理所有其他未知异常
        std::cerr << "未知异常" << std::endl;
        conn->shutdown();
    }
}

#endif