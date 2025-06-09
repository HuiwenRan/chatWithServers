#include "friendmodel.hpp"
#include "db.hpp"
#include "json.hpp"
#include <vector>

using json = nlohmann::json;

bool FriendModel::insert(int userid, int friendid)
{
    char sql[1024] = {0};
    sprintf(sql, "INSERT INTO friend (userid, friendid) VALUES (%d, %d)", userid, friendid);
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}
bool FriendModel::remove(int userid, int friendid)
{
    char sql[1024] = {0};
    sprintf(sql, "DELETE FROM friend WHERE userid=%d AND friendid=%d", userid, friendid);
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}
std::vector<json> FriendModel::query(int userid)
{
    char sql[1024] = {0};
    // 从user表中查询friend表中userid对应的friendid
    sprintf(sql, "select id,name,state from user join friend on user.id = friend.friendid and friend.userid = %d", userid);
    MySQL mysql;
    std::vector<json> result;

    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != NULL)
            {
                json j;
                j["id"] = atoi(row[0]);
                j["name"] = row[1];
                j["state"] = row[2];
                result.emplace_back(j);
            }
        }
    }
    return result;
}