#include "chatserver.hpp"
#include <iostream>
#include "db.hpp"

int main()
{
    muduo::net::EventLoop loop;
    muduo::net::InetAddress listenAddr(8000);
    ChatServer server(&loop, listenAddr, "ChatServer");
    server.start();
    loop.loop();

    return 0;
}
