//
//  main.cpp
//  CppTmeX
//
//  Created by PixBoly on 2018/1/27.
//  Copyright © 2018年 pix. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "time_utils.h"
#include <time.h>
#include <sys/time.h>

using namespace std;

void test_get_current_time();
void test_tm_time();
void test_time_utils();
void test_timeval();
void test_timestr();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //test_get_current_time();
    //test_tm_time();
    test_time_utils();
    //test_timeval();
    //test_timestr();
    
    return 0;
}

void test_get_current_time() {
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    // 把 now 转换为字符串形式
    char* dt = ctime(&now);
    cout << "本地日期和时间：" << dt << endl;
    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间："<< dt << endl;
}

void test_tm_time() {
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    
    cout << "1970 到目前经过秒数:" << now << endl;
    
    tm *ltm = localtime(&now);
    
    // 输出 tm 结构的各个组成部分
    cout << "年: "<< 1900 + ltm->tm_year << endl;
    cout << "月: "<< 1 + ltm->tm_mon<< endl;
    cout << "日: "<<  ltm->tm_mday << endl;
    cout << "时间: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
}

void test_time_utils() {
    char timestring[100];
    get_time_string(timestring, time(0));
    cout<<"get_time_stirng:"<<timestring<<endl;
    cout<<"system_current_timemillis:"<<system_current_timemillis()<<endl;
}

void test_timeval() {
    timeval time;
    gettimeofday(&time,NULL);
    cout<<"time.tv_usec:"<<time.tv_usec<<endl;
    cout<<"time.tv_sec:"<<time.tv_sec<<endl;
    long timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
    cout<<"timestamp:"<<timestamp<<endl;
}

void test_timestr() {
    char tbuf[100];
    time_t t;
    t = time(0);
    tm * ptm = localtime(&t);
    strftime(tbuf, 100, "%F %T",ptm);
    cout<<"tbuf:"<<tbuf<<",len:"<<strlen(tbuf)<<endl;
}

