#include <iostream>
using namespace std;

void func1();
void func2();

void main()
{
	func1();
	func2();
}

void func1()
{
	#define a 10
	const int b = 20;
    //#undef a // 卸载宏
}

void func2()
{
	cout<<"a:"<<a<<endl;
	//cout<<"b:"<<b<<endl;  //不能使用

}