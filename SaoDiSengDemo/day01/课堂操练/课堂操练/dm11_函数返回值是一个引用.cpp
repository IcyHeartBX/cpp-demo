#include <iostream>
using namespace std;


int getAA1()
{
	int a;
	a  = 10;
	return a;
}

int & getAA2()
{
	int a;
	a  = 10;
	return a;
}

int * getAA3()
{
	int a;
	a  = 10;
	return &a;
}



//若返回为引用类型，不能作为其他引用的初始值
void main1101()
{
	int a1 = getAA1();
	int a2 = getAA2();
	int & a3 = getAA2();

	printf("a1:%d,a2:%d,a3:%d\n",a1,a2,a3);

	system("pause");
}

//变量是static或全局变量
int j1()
{
	static int a ;
	a++;
	return a ;
}

int & j2()
{
	static int a ;
	a++;
	return a ;
}

void main1102()
{
	int a1 = j1();
	int a2 = j2();
	int & a3 = j2();
	printf("a1:%d\n",a1);
	printf("a2:%d\n",a2);
	printf("a3:%d\n",a3);
	system("pause");
}


////////////////////////////////////
//函数当左值

//返回变量的值
int g1()
{
	static int c ;
	c++;
	return c ;
}
//返回变量本身
int & g2()
{
	static int c ;
	c++;
	printf("c:%d\n",c);
	return c ;
}

void main()
{
	//g1() = 100; 左操作符必须为左值
	g2() = 100;
	g2();
	int c = g2();
	system("pause");
}