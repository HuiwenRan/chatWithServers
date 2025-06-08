#include "usermodel.hpp"

bool UserModel::addUser(User &user)
{
    // 组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "insert into user(name, password, state) values('%s','%s','%s')", user.get_name().c_str(), user.get_password().c_str(), user.get_state().c_str());
    // 执行sql语句
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            user.set_id(mysql_insert_id(mysql.getConn()));
            return true;
        }
    }
    return false;
}

bool UserModel::queryUser(User &user)
{
    char sql[1024] = {0};
    sprintf(sql, "select * from user where id = %d", user.get_id());
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res)
        {
            MYSQL_ROW row = mysql_fetch_row(res);
            user.set_name(row[1]);
            user.set_password(row[2]);
            user.set_state(row[3]);
            mysql_free_result(res);
            return true;
        }
    }
    return false;
}

bool UserModel::deleteUser(User &user)
{
    return true;
}
bool UserModel::updateState(User &user)
{
    char sql[1024] = {0};
    sprintf(sql, "update user set state = '%s' where id = %d", user.get_state().c_str(), user.get_id());

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

void UserModel::resetState()
{
    char sql[1024] = {0};
    sprintf(sql, "update user set state = 'offline' where state = 'online'");
    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}