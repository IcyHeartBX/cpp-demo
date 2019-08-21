/*
 * test_extends_construct.cpp
 *
 *  Created on: 2017年3月16日
 *      Author: Administrator
 */

#include "test_extends_construct.h"

#include <iostream>
using namespace std;


Parent::Parent(int a,int b)
{
	this->a = a;
	this->b = b;
	cout<<"FUNC Parent::Parent(int a,int b)\n";
}

void Parent::printP()
{
	cout<<"FUNC Parent::printP()\n";
}

Parent::Parent(const Parent & obj)
{
	cout<<"FUNC Parent::Parent(const Parent & obj)\n";
	this->a = obj.a;
	this->b = obj.b;
}

Parent::~Parent()
{
	cout<<"FUNC Parent::~Parent()\n";
}

Child::Child(int a,int b,int c):Parent(a,b)
{
	cout<<"FUNC Child::Child(int a,int b,int c)\n";
	this->c = c;
}

void Child::printC()
{
	cout<<"FUNC Child::printC()\n";
}

Child::~Child()
{
	cout<<"Child::~Child()\n";
}
void test_extends_construct()
{
	Child c1(1,2,3);
}
