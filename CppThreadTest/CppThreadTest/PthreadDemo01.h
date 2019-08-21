//
//  PthreadDemo01.h
//  CppThreadTest
//
//  Created by PixBoly on 2018/1/17.
//  Copyright © 2018年 pix. All rights reserved.
//

#ifndef PthreadDemo01_h
#define PthreadDemo01_h

// 测试pthread使用
#include <iostream>
#include <pthread.h>
#include <thread>
#include <chrono>
using namespace std;

// 存储线程id
pthread_t t1;

void * My_thread(void * args) { // 线程运行函数
    for (int i = 0;i < 100;i++) {
        cout<<"I am your thread,my Id is "<<t1<<endl;
    }
    return NULL;
}

void PthreadDemo01Main() {
    cout<<"FUNC PthreadDemo01Main(),RUN..."<<endl;
    pthread_create(&t1,NULL,My_thread,NULL);   // 创建缺省线程
    // mac的sleep
    std::this_thread::sleep_for(std::chrono::milliseconds(1000000));
}

#endif /* PthreadDemo01_h */
