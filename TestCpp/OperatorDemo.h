/*
 * OperatorDemo.h
 *
 *  Created on: 2017年2月22日
 *      Author: pixboly
 */

#ifndef OPERATORDEMO_H_
#define OPERATORDEMO_H_
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int a = 1,int b = 1);
public:
	void Print(void);
	friend Complex operator+(Complex & c1,Complex & c2);
	Complex operator-(Complex & c);
	friend Complex & operator++(Complex & c1);
	friend Complex operator--(Complex & c,int);
	friend ostream & operator<<(ostream & out,Complex & c);

private:
	int a;
	int b;
};

void Test_Operator(void);
void Test_Operator_Print(void);
Complex operator+(Complex & c1,Complex & c2);
Complex & operator++(Complex & c1);
Complex operator--(Complex & c,int);
ostream & operator<<(ostream & out,Complex & c);

#endif /* OPERATORDEMO_H_ */
