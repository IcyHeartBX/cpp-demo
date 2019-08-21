/*
 * My_String.h
 *
 *  Created on: 2017年2月23日
 *      Author: pixboly
 */

#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
/**
 *	C语言中没有字符串，空串
 */
class MyString
{
public:
	MyString(const char * string = "");
	MyString(int len);
	~MyString();
	MyString(const MyString & obj);
public:
	friend ostream & operator<<(ostream & out,MyString & s);
	friend istream & operator>>(istream & in,MyString & s);
	// 重载=操作
	MyString & operator=(MyString & obj) ;
	MyString & operator=(const char * s);
	// 重载==操作
	bool operator==(MyString & obj) const;
	bool operator==(const char * s) const;
	// 重载!=操作
	bool operator!=(MyString & obj) const;
	bool operator!=(const char * s) const;
	// 重载<操作
	int operator<(MyString & obj) const;
	int operator<(const char * s) const;
	// 重载>操作
	int operator>(MyString & obj) const;
	int operator>(const char * s) const;

	// 重载[]操作
	char & operator[](int index);
private:
	char * m_Buff;
	int m_length;
};

// 重载左移操作符<<输出
ostream & operator<<(ostream & out,MyString & s);

void Test_String();

#endif /* MY_STRING_H_ */
