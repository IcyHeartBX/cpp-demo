/*
 * OperatorDemo.cpp
 *
 *  Created on: 2017年2月22日
 *      Author: pixboly
 */

#include "OperatorDemo.h"

Complex::Complex(int a,int b):a(a),b(b)
{
}

void Complex::Complex::Print(void)
{
	cout<<"CLASS Complex,FUNC Print(),"<<a<<" + "<<b<<"i "<< endl;
}

Complex Complex::operator-(Complex & c)
{
	Complex tmp(this->a - c.a,this->b - c.b);
	return tmp;
}



Complex operator+(Complex & c1,Complex & c2)
{
	 	 Complex tmp(c1.a + c2.a,c1.b + c2.b);
	 	 return tmp;
}

// 前置++，++c1
Complex & operator++(Complex & c1)
{
	c1.a++;
	c1.b++;
	return c1;
}

// 后置
Complex operator--(Complex & c,int)
{
	// 先使用，后自减
	Complex tmp = c;
	c.a--;
	c.b--;
	return tmp;
}

// 输出Complex对象
ostream & operator<<(ostream & out,Complex & c)
{
	out<<c.a<< " + "<<c.b<<"i"<<endl;
	return out;
}

void Test_Operator(void)
{
	cout<<"Func Test_Operator(),RUN..."<<endl;
	Complex c1(1,2);
	Complex c2(3,4);
	Complex c3 =  c1 + c2;
	c3.Print();

	Complex c4 = c3 - c1;
	c4.Print();
	// 前置运算符，用全局函数实现
	++c1;
	c1.Print();

	//后置运算符重载，全局函数
	c1--;
	c1.Print();
}

void Test_Operator_Print(void)
{
		Complex c1(1,2);
		// 如果想输出Complex对象，需要对Complex重载左移操作符<<
		//operator<<(ostream & out,Complex & c1)
		cout<<c1<<endl;
		// 输入输出流的操作符重载，必须要使用全局函数，因为无法修改cout的源码
		// cout.operator<<(Complex & c);
}

