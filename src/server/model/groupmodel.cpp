#include "groupmodel.hpp"
#include "db.hpp"
#include "group.hpp"

#include <iostream>

bool GroupModel::createGroup(Group &group)
{
    char sql[1024] = {0};
    sprintf(sql, "INSERT INTO allgroup (groupname, groupdesc) VALUES ('%s', '%s')",
            group.GetName().c_str(), group.GetDescription().c_str());
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            group.SetId(mysql_insert_id(mysql.getConn()));
            return true;
        }
    }
    return false;
}
bool GroupModel::addGroup(int userid, int groupid, std::string role)
{
    char sql[1024] = {0};
    sprintf(sql, "INSERT INTO groupuser (userid, groupid, grouprole) VALUES (%d, %d, '%s')",
            userid, groupid, role.c_str());
    MySQL mysql;
    if (mysql.connect())
    {
        return mysql.update(sql);
    }
    return false;
}
// 查询用户所在群聊
std::vector<Group> GroupModel::queryGroups(int userid)
{
    std::vector<Group> groups;
    char sql[1024] = {0};
    sprintf(sql,
            "SELECT id,groupname,groupdesc FROM allgroup join groupuser on allgroup.id = groupuser.groupid and groupuser.userid = %d ", userid);
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)))
            {
                Group group;
                group.SetId(atoi(row[0]));
                group.SetName(std::string(row[1]));
                group.SetDescription(std::string(row[2]));
                groups.push_back(group);
            }
            mysql_free_result(res);
        }
    }
    for (Group &group : groups)
    {
        sprintf(sql, "select a.id,a.name,a.state,b.grouprole from user a \
            inner join groupuser b on b.userid = a.id where b.groupid=%d",
                group.GetId());
        MYSQL_RES *res = mysql.query(sql);
        if (res)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)))
            {
                GroupUser user;
                user.set_id(atoi(row[0]));
                user.set_name(std::string(row[1]));
                user.set_state(row[2]);
                user.setGrouprole(std::string(row[3]));
                group.AddUser(user);
            }
            mysql_free_result(res);
        }
    }
    return groups;
}
// 查询群聊中所有用户，用于发送消息
std::vector<int> GroupModel::queryGroupUsers(int userid, int groupid)
{
    std::vector<int> users;
    char sql[1024] = {0};
    sprintf(sql, "SELECT userid FROM groupuser WHERE groupid = %d and userid != %d", groupid, userid);
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)))
            {
                users.push_back(atoi(
                    row[0])); // 这里假定userid是整型，如果不是则需要根据实际情况调整
            }
        }
        mysql_free_result(res);
    }
    return users;
}