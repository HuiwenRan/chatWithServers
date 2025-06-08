#include "chatserver.hpp"
#include <iostream>
#include <signal.h>
#include "db.hpp"
#include "chatservice.hpp"

void resetHandler(int sig)
{
    std::cout << "Caught signal " << sig << ". Exiting." << std::endl;
    ChatService::getInstance().reset();
    exit(0); // default action is to terminate the program
}

int main()
{
    signal(SIGINT, resetHandler);
    muduo::net::EventLoop loop;
    muduo::net::InetAddress listenAddr(8000);
    ChatServer server(&loop, listenAddr, "ChatServer");
    server.start();
    loop.loop();

    return 0;
}
