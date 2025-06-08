#pragma once

#include <string>
#include <vector>
#include <mysql/mysql.h>

class OfflineMsgModel
{
public:
    void insert(int id, std::string msg);
    void remove(int id);
    std::vector<std::string> query(int id);
};