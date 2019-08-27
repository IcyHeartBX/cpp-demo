#include <iostream>
using namespace std;

//常引用的知识架构
void main1301()
{
	//普通引用
	int a = 10;
	int & b = a;
	printf("b:%d\n",b);
	//常引用
	int x = 20;
	//常引用，让变量引用只读属性，不能通过y去修改x
	const int & y = x;	

	//常引用的初始化，分为两种情况
	//1、用变量初始化常应用
	{
		int x1 = 30;
		const int & y1 = x1;  //用x1变量去初始化常引用
	}
	//2、用字面量初始化常引用
	{
		const int  a = 40; // C++编译器把a放到符号表中了
		//int & b = 41;		//普通引用引用一个字面量，字面量没有内存地址
							//引用就是给内存取别名，没有内存怎么取别名？
		const int & c = 42; //C++编译器会给m分配一个内存，并取别名c
	}

	//
	system("pause");
}

struct Teacher 
{
	char name[64];
	int age;
};

void printTeacher(const Teacher & t)
{
	//常引用让变量拥有只读属性
	//t.age = 44;
	cout<<"age:"<<t.age<<endl;
}

void main()
{
	Teacher t1;
	t1.age = 33;
	printTeacher(t1);
	system("pause");
}