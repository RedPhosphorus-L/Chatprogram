#include "offlinemessagemodel.hpp"
#include "db.h"
#include <iostream>
using namespace std;;

void OfflineMsgModel::insert(int userid, string msg)
{
    char sql[1024] = {0};
    sprintf(sql, "insert into offlinemessage values('%d','%s')", userid, msg.c_str());

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}

void OfflineMsgModel::remove(int userid)
{

    char sql[1024] = {0};
    sprintf(sql, "delete from offlinemessage where userid=%d", userid);

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}

vector<string> OfflineMsgModel::query(int userid)
{
    char sql[1024] = {0};
    sprintf(sql, "select message from offlinemessage where userid = %d", userid);

    MySQL mysql;
    vector<string> vec;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            //把userid用户的所有离线消息放入vec中返回;
            while((mysql_fetch_row(res))!=nullptr)
            {
                string data=row[0];
                cout<<data<<endl;
                vec.push_back(data);
            }

            mysql_free_result(res);
            return vec;
        }
    }
    return vec;

}