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
    //#undef a // ж�غ�
}

void func2()
{
	cout<<"a:"<<a<<endl;
	//cout<<"b:"<<b<<endl;  //����ʹ��

}