/*
muduo提供两个主要类
TcpServer：用于编写服务器程序
TcpClient：用于编写客户端程序

epoll+线程池
好处：能够把网络IO的代码和业务代码分开
        用户的连接和断开       用户的可读写事件
*/
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

/*服务器类，基于muduo库开发*/
class ChatServer
{
public:
    // 初始化TcpServer
    ChatServer(muduo::net::EventLoop *loop,
               const muduo::net::InetAddress &listenAddr)
        : _server(loop, listenAddr, "ChatServer")
    {
        // 通过绑定器设置回调函数
        _server.setConnectionCallback(bind(&ChatServer::onConnection,
                                           this, _1));
        _server.setMessageCallback(bind(&ChatServer::onMessage,
                                        this, _1, _2, _3));
        // 设置EventLoop的线程个数
        _server.setThreadNum(10);
    }
    // 启动ChatServer服务
    void start()
    {
        _server.start();
    }

private:
    // TcpServer绑定的回调函数，当有新连接或连接中断时调用
    void onConnection(const muduo::net::TcpConnectionPtr &con);
    // TcpServer绑定的回调函数，当有新数据时调用
    void onMessage(const muduo::net::TcpConnectionPtr &con,
                   muduo::net::Buffer *buf,
                   muduo::Timestamp time);

private:
    muduo::net::TcpServer _server;
};

void ChatServer::onConnection(const muduo::net::TcpConnectionPtr &con)
{
    // 处理连接断开
    if (con->connected())
    {
        cout << "连接建立" << "server IP:port" << con->localAddress().toIpPort() << endl;
        cout << "client IP:port" << con->peerAddress().toIpPort() << endl;
    }
    else
    {
        cout << "连接断开" << "server IP:port" << con->localAddress().toIpPort() << endl;
        cout << "client IP:port" << con->peerAddress().toIpPort() << endl;
    }
}

void ChatServer::onMessage(const muduo::net::TcpConnectionPtr &con,
                           muduo::net::Buffer *buf,
                           muduo::Timestamp time)
{
    // 处理数据的读取和发送
    string msg = buf->retrieveAllAsString();
    cout << "收到消息：" << msg << endl;
    // 返回大写字符串
    string upperMsg = msg;
    for (auto &c : upperMsg)
    {
        if (islower(c))
            c = toupper(c);
    }
    con->send(upperMsg + "\n");
}

int main()
{
    muduo::net::EventLoop loop;
    // 初始化服务器，监听12345端口
    ChatServer server(&loop, muduo::net::InetAddress(12345));
    server.start();
    loop.loop();
    return 0;
}