#pragma once

#include <string>
#include <vector>
#include "group.hpp"

// 这里面只与数据库操作相关，每个方法中都有sql
class GroupModel
{
public:
    bool createGroup(Group &group);
    bool addGroup(int userid, int groupid, std::string role);
    // 查询用户所在群聊
    std::vector<Group> queryGroups(int userid);
    // 查询群聊中所有用户，用于发送消息
    std::vector<int> queryGroupUsers(int userid, int groupid);
};