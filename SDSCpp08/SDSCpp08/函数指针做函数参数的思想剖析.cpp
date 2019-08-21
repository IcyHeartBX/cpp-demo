//
//  函数指针做函数参数的思想剖析.cpp
//  SDSCpp08
//
//  Created by 唐鹏翔 on 2017/7/5.
//  Copyright © 2017年 pix. All rights reserved.
//
#include <iostream>
using namespace std;

int myAdd(int a,int b)
{
    printf("Func add(),Run...\n");
    return a + b;
}
//定义一个函数指针类型
typedef int (* MyTypeFuncAdd)(int,int);

int MainOp(MyTypeFuncAdd mtfd)  // 先定义类型，再作参数
{
    int c =  mtfd(5,6);
    return c;
}

int MainOp2(int (* mtfd)(int,int))  // 直接定义变量作参数
{
    int c = mtfd(7,8);
    return c;
}


int main()
{
    myAdd(1,2);
    MyTypeFuncAdd myFuncAdd = NULL ;
    myFuncAdd = myAdd;
    myFuncAdd(3,4);
    MainOp(myAdd);
    MainOp2(myAdd);
    cout<<"hello..."<<endl;
    return 0;
}
