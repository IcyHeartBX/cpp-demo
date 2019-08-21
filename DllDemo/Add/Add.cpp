/*
 *  Add.cpp
 *  Add
 *
 *  Created by 唐鹏翔 on 2017/7/7.
 *
 *
 */

#include <iostream>
#include "Add.hpp"
#include "AddPriv.hpp"

void Add::HelloWorld(const char * s)
{
    AddPriv *theObj = new AddPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void AddPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

int Add::Sum(int a,int b)
{
    return a + b;
};

