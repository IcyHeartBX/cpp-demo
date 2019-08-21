/*
 * test_extends_construct.h
 *
 *  Created on: 2017年3月16日
 *      Author: Administrator
 */

#ifndef TEST_EXTENDS_CONSTRUCT_H_
#define TEST_EXTENDS_CONSTRUCT_H_

class Parent
{
public:
	Parent(int a,int b);
	Parent(const Parent & obj);
	~Parent();
public:
	void printP();

private:
	int a;
	int b;

};

class Child : public Parent
{
public:
	Child(int a,int b,int c);
	~Child();
	void printC();
public:
	int c;
};

void test_extends_construct();


#endif /* TEST_EXTENDS_CONSTRUCT_H_ */
