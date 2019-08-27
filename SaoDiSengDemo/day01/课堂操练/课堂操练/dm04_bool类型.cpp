#include <iostream>
using namespace std;

void main()
{
	bool b1 = true;
	//测试占用内存大小，1个字节内存
	cout<<"sizeof(bool)："<<sizeof(bool)<<endl;

	//bool变量要么是1，要么是0没有其他值
	b1 = 10;
	cout<<"b1:"<<b1<<endl;

	b1 =-10;
	cout<<"b1:"<<b1<<endl;

	b1 = false;
	cout<<"b1:"<<b1<<endl;

	system("pause");
}