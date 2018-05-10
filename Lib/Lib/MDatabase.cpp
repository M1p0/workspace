#include "MDatabase.h"
#include <iostream>
using namespace std;


MDatabase::MDatabase()
{
    Init();
}

MDatabase::~MDatabase()
{
    mysql_close(pConn);
}

int MDatabase::Connect(const char * IP, const char * User, const char * Password, const char * DbName, int Port)
{
    if (!mysql_real_connect(pConn, IP, User, Password, DbName, Port, NULL, 0))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int MDatabase::SetEncoding(const char * Encoding)
{
    char Cmd[512];
    memset(Cmd, 0, 512);
    strcpy(Cmd, "set names ");
    strcat(Cmd, Encoding);
    if (!mysql_query(pConn, Cmd))  //return value==false
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int MDatabase::ExecSQL(const char * SQL, vector<vector<string>> &Result, int &nRow)
{
    if (mysql_query(pConn, SQL))
    {
        return -1;
    }
    else
    {
        MYSQL_RES* Res = mysql_store_result(pConn);
        if (Res == nullptr)
        {
            return 0;
        }
        MYSQL_ROW Row;
        nRow = mysql_num_fields(Res);
        int Current = 0;
        while (Row = mysql_fetch_row(Res))
        {

            for (int i = 0; i < nRow; i++)
            {
                Result[Current].push_back(Row[i]);
            }
            Current++;
        }
        return 0;
    }


}



void MDatabase::Init()
{
    pConn = mysql_init(NULL);
}
