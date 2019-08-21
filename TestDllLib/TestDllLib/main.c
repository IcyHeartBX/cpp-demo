//
//  main.cpp
//  TestDllLib
//
//  Created by 唐鹏翔 on 2017/7/7.
//  Copyright © 2017年 pix. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "socketclientlib.h"

int main(int argc, const char * argv[]) {
    void * handle = NULL;
    unsigned char in[1024] = {0};
    unsigned char out[1024] = {0};
    int inlen;
    int outlen = 0;
    int ret = 0;
    
    strcpy((char *)in,"helloworld");
    inlen = 5;
    ret =  cltSocketInit(&handle);
    
    ret =  cltSocketSend(handle,in,inlen);
    
    ret =  cltSocketRev(handle,out,&outlen);
    
    ret =  cltSocketDestory(handle);
    
    return 0;
}
