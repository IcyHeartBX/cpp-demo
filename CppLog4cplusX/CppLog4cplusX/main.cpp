//
//  main.cpp
//  CppLog4cppX
//
//  Created by PixBoly on 2018/1/28.
//  Copyright © 2018年 pix. All rights reserved.
//

#include <iostream>
#include "LogUtil.h"
#include "file1.h"
#define LOG_FILE "/Users/tangpengxiang/logs/logsTest.log"
int main(int argc, const char * argv[]) {
    LogUtils::init(LOG_FILE);
    LOG4CPLUS_DEBUG(LogUtils::GetLogger(), "11111111111111"<<"123");
    file1main();
    
    int num = 5;
    return 0;
}
