//
//  MyDB.hpp
//  TestMySqlXcode
//
//  Created by PixBoly on 2018/1/16.
//  Copyright © 2018年 pix. All rights reserved.
//

#ifndef MyDB_hpp
#define MyDB_hpp

#include<iostream>
#include<string>
#include<mysql.h>
using namespace std;

class MyDB
{
public:
    MyDB();
    ~MyDB();
    bool initDB(string host, string user, string pwd, string db_name);
    bool exeSQL(string sql);
private:
    MYSQL *connection;
    MYSQL_RES *result;
    MYSQL_ROW row;
};


#endif /* MyDB_hpp */
