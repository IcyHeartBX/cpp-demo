#include <iostream>
using namespace std;

void main01()
{
	int a = 10;
	int & b = a;
	const int c = 20;

	printf("&a:%p,&b:%p\n",&a,&b); //a和b是用一个内存空间的门牌号

	system("pause");
}


//引用占内存空间吗
struct Teacher
{
	char name[64];		//64
	int age;			//4
	int & a;  //引用占内存空间吗？
	int & b;
};

void main02()
{
	printf("sizeof(Teacher):%d\n",sizeof(Teacher));
	system("pause");
}

void modifyA(int & a1)
{
	a1 = 5;
}

void modifyA2(int * const a1)
{
	*a1 = 200;  //通过指针简介修改实参的值
}
void main()
{
	int a = 10;
	modifyA(a); //调用这个函数，不用再取地址，编译器在内部自己完成。
	printf("a:%d\n",a);
	modifyA2(&a); //如果是指针，需要手工取地址
	printf("a:%d\n",a);
	system("pause");
}