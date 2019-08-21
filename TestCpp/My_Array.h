/*
 * My_Array.h
 *自定义数组类
 *  Created on: 2017年2月23日
 *      Author: pixboly
 */

#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/**
 * 给数组类增加 ==(相等)   != (不相等) []下标功能
 */
class Array
{
public:
	Array(int length = 0);
	~Array();
	Array(const Array & obj);
public:
	// 可以运算符重载实现 a1[index] = value;
	void SetData(int index,int value);
	// 运算符重载 a1[index];
	int GetData(int index);
	int Length();
	friend ostream & operator<<(ostream & out,Array & obj);
	Array & operator=(const Array & obj);
	int & operator[](int i);
	bool operator==(Array & obj);
	bool operator!=(Array & obj);
private:
	int m_length;
	int * m_space;
};

// 重载<<输出操作符
ostream & operator<<(ostream & out,Array & obj);

void Test_Array(void);


#endif /* MY_ARRAY_H_ */
