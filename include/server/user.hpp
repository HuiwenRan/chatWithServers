#pragma once
// 数据库user表，id,name,password,state

#include <string>

class User
{
private:
    int id;
    std::string name;
    std::string password;
    std::string state;

public:
    User(int id = -1, std::string name = "", std::string password = "", std::string state = "offline")
    {
        this->id = id;
        this->name = name;
        this->password = password;
        this->state = state;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_name(std::string name)
    {
        this->name = name;
    }
    void set_password(std::string password)
    {
        this->password = password;
    }
    void set_state(std::string state)
    {
        this->state = state;
    }
    int get_id() const
    {
        return id;
    }
    std::string get_name() const
    {
        return name;
    }
    std::string get_password() const
    {
        return password;
    }
    std::string get_state() const
    {
        return state;
    }
};