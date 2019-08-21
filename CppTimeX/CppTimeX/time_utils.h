//
//  Header.h
//  CppTmeX
//
//  Created by PixBoly on 2018/1/27.
//  Copyright © 2018年 pix. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 取得yyyy-MM-dd HH:mm:ss 字符串
 * @param dst 字符串指针
 * @param timestamp 秒时间戳
 */
int get_time_string(char * dst,time_t timestamp) {
    int ret = 0;
    if(NULL == dst) {
        ret = -1;
        return ret;
    }
    // 把 now 转换为字符串形式
    tm *ltm = localtime(&timestamp);
    strftime(dst, 100, "%F %T",ltm);
    return ret;
}
    
long system_current_timemillis() {
    timeval time;
    gettimeofday(&time,NULL);
    return time.tv_sec * 1000 + time.tv_usec / 1000;
}

#ifdef __cplusplus
}
#endif

#endif /* Header_h */
