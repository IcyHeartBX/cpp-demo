//
//  main.cpp
//  TestMySqlXcode
//
//  Created by PixBoly on 2018/1/16.
//  Copyright © 2018年 pix. All rights reserved.
//

#include <iostream>
#include "MyDB.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    MyDB db;
    db.initDB("localhost", "root", "123456", "test");
    db.exeSQL("select * from user");
    return 0;
}
