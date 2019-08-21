//
//  PthreadJoinDemo.h
//  CppThreadTest
//
//  Created by PixBoly on 2018/1/18.
//  Copyright © 2018年 pix. All rights reserved.
//

#ifndef PthreadJoinDemo_h
#define PthreadJoinDemo_h

#include <iostream>
#include <pthread.h>
using namespace std;

pthread_t p1; // 线程id变量

void * My_Thread(void * args) {
    for (int i = 0 ;i < 100 ;i++) {
        cout<<"FUNC My_Thread(),p1:"<<p1<<endl;
        
    }
    pthread_exit((void *)"I am over!");     // 终止时返回
    return NULL;
}


void PthreadJoinDemoMain() {
    cout<<"FUNC PthreadJoinDemoMain(),RUN..."<<endl;
    void * mythead_ret;
    pthread_create(&t1,NULL,My_Thread,NULL);
    cout<<"FUNC PthreadJoinDemoMain(),join before=========!"<<endl;
    pthread_join(t1,&mythead_ret);
    cout<<"FUNC PthreadJoinDemoMain(),join after==========!"<<endl;
    // mac的sleep
    std::this_thread::sleep_for(std::chrono::milliseconds(1000000));
}

#endif /* PthreadJoinDemo_h */
