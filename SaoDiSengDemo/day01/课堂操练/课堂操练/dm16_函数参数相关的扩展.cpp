#include <iostream>
using namespace std;

void myPrint(int i = 10)
{
	cout << "i = " << i << endl;
}

//如果参数中有带默认参数的，有不带默认参数的，必须将不带默认参数的写在前面
void myPrint2(int j,int i = 10,int k = 20)
{
	cout << "i = " << i << endl;
}

void main默认参数()
{
	//若填写参数，使用填写的，不填写，走默认
	myPrint(20);
	myPrint();
}

///////////占位参数

//函数的占位参数，函数调用时必须写够参数
void func1(int a, int b, int)
{
	cout << "a:" << a << ",b:" << b << endl;
}


void main占位参数()
{
	//func1(2, 3);
	func1(2, 3, 4);
}


/////////默认参数和占位参数

//如果默认参数和占位参数在一起，写2，3个参数都能调用起来
void func2(int a, int b, int = 0)
{
	cout << "a:" << a << ",b:"<<b << endl;
}

void main()
{
	func2(2, 3);
	func2(2, 3, 4);
}
