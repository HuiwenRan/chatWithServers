#pragma once

#include <string>
#include <vector>

#include "groupuser.hpp"
// 每个类对应每个群
// 成员函数只是对属性的修改，而不是操作数据库，数据库操作在groupmodel中
class Group
{
public:
    Group(int id = -1, std::string groupname = "", std::string groupdesc = "", std::vector<GroupUser> users = {})
        : id(id), groupname(groupname), groupdesc(groupdesc), users(users)
    {
    }
    int GetId() const { return id; }
    void SetId(int id)
    {
        this->id = id;
    }

    std::string GetName() const { return groupname; }
    void SetName(const std::string &name)
    {
        this->groupname = name;
    }

    std::string GetDescription() const { return groupdesc; }
    void SetDescription(const std::string &description)
    {
        this->groupdesc = description;
    }

    std::vector<GroupUser> GetUsers() const { return users; }
    void AddUser(const GroupUser &user)
    {
        users.push_back(user);
    }

private:
    int id;
    std::string groupname;
    std::string groupdesc;
    std::vector<GroupUser> users;
};