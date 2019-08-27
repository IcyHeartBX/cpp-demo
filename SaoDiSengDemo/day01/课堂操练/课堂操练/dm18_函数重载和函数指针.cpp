#include <iostream>
using namespace std;

void myfunc(int a)
{
	printf("a:%d\n",a);
}


void myfunc(char * p)
{
	printf("p:%s\n",p);
}

void myfunc(int a,int b)
{

	printf("a:%d,b:%d\n",a,b);
}

void myfunc(char * p1,char * p2)
{

	printf("p1:%s,p2:%d\n",p1,p2);
}
//函数指针
//声明定义一个函数类型
typedef void (MYFUNC) (int a,int b);
//MYFUNC * myfuncp = NULL; //定义一个函数指针，这个指针指向一个函数的入口地址
//2、定义一个函数指针类型
typedef void (* MYFUNCP) (int a,int b);
//MYFUNCP myfuncp2 = NULL; //通过函数指针类型，定义函数指针
//定义一个函数指针变量
void (* MYFUNCP2) (int a,int b);


void main()
{
	MYFUNCP fp = NULL;  
	fp = myfunc;
	fp(1,2);
	system("pause");
}