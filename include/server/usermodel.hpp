#pragma once
// 专门用于操作User类
#include "user.hpp"
#include "db.hpp"

#include <iostream>

class UserModel
{
public:
    bool addUser(User &user);
    bool deleteUser(User &user);
    bool updateState(User &user);
    void resetState();
    bool queryUser(User &user);
};