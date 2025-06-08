#include "offlinemsgmodel.hpp"

#include "db.hpp"

void OfflineMsgModel::insert(int id, std::string msg)
{
    char sql[1024] = {0};
    sprintf(sql, "insert into offlinemessage values(%d,'%s')", id, msg.c_str());

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}
void OfflineMsgModel::remove(int id)
{
    char sql[1024] = {0};
    sprintf(sql, "delete from offlinemessage where userid = %d", id);
    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}
std::vector<std::string> OfflineMsgModel::query(int id)
{
    char sql[1024] = {0};
    sprintf(sql, "select message from offlinemessage where userid = %d", id);
    MySQL mysql;
    std::vector<std::string> result;
    if (mysql.connect())
    {
        MYSQL_RES *msgs = mysql.query(sql);
        if (msgs)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(msgs)))
            {
                result.push_back(std::string(row[0]));
            }
            mysql_free_result(msgs);
        }
    }
    return result;
}