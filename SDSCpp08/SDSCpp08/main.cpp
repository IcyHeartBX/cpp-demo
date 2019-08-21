//
//  main.cpp
//  SDSCpp08
//
//  Created by 唐鹏翔 on 2017/7/5.
//  Copyright © 2017年 pix. All rights reserved.
//

#include <iostream>
using namespace std;
// 数组类型基本语法知识梳理
// 定义数组类型
//int a[10];
// 定义一个指针数组类型
// 定义一个指向数组类型的指针，数组类指针

int main01(int argc, const char * argv[]) {
    
    int a[10];      // a代表数组首元素地址，&a代表整个数组的地址，a + 1 ,&a + 1 步长
    // 定义一个数组类型
    {
        typedef int (myTypeArray)[10];
        myTypeArray myArray;
        myArray[0] = 10;
        std::cout<<myArray[0]<<endl;
    }
    // 定义一个指针数组类型
    {
        typedef int (*PTypeArray)[10];
        PTypeArray myPArray;     // sizeof(int) * length;
        myPArray = &a;
        (*myPArray)[0] = 20;
        cout<<a[0]<<endl;
    }
    // 定义一个指向数组类型的指针，数组类指针
    {
        int (* MyPointer)[10];  //变量 告诉编译器给我分配内存
        MyPointer = &a;
        (*MyPointer)[0] = 40;
        cout<<a[0]<<endl;
    }
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

// 函数指针基本语法知识梳理
// 1、定义一个函数类型
// 2、定义一个函数指针类型
// 3、如何定一个函数指针，（指向一个函数的入口地址）

int add(int a,int b)
{
    return a + b;
}

int main02()
{
    add(1,2);       // 直接调用，函数名就是函数的入口地址
// 1、定义一个函数类型
    {
        typedef int (MyFuncType)(int a,int b);  // 定义函数类型
        MyFuncType * myFunc = &add; // 指向一个函数的入口
        MyFuncType * myFunc2 = add; //也可以不取地址
        myFunc(3,4);    // 间接调用
    }
    // 2、定义一个函数指针类型
    {
        typedef int (*MyPointerFuncType) (int,int); // 函数指针类型 int * a = NULL;
        MyPointerFuncType myPointerFunc = add;
        myPointerFunc(5,6);
    }
    // 3、如何定一个函数指针，（指向一个函数的入口地址）
    {
        int (*MyPointerFunc) (int,int);
        MyPointerFunc = add;
        MyPointerFunc(7,8);
    }
    
    return 0;
}
