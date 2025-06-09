#pragma once

#include "user.hpp"
// 需要存储用户群关系表中的额外信息
class GroupUser : public User
{
public:
    std::string getGrouprole() const
    {
        return grouprole_;
    }
    void setGrouprole(std::string grouprole)
    {
        grouprole_ = grouprole;
    }

private:
    std::string grouprole_; // creator、normal
};