#include <iostream>
using namespace std;


struct Teacher
{
	char name[64];
	int age;
};

int getTeacher(Teacher ** p)
{
	if(p == NULL)
	{
		return -1;
	}
	Teacher * temp = NULL;
    temp = (Teacher *)malloc(sizeof(Teacher));
	if(temp == NULL)
	{
		return -2;
	}
	//p是实参的地址，*实参的地址，去间接修改实参的值
	* p = temp;
	temp->age = 33;
	return 0;
}

int getTeacher2(Teacher * &myp)
{
	if(myp == NULL)
	{
		return -1;
	}
	//给myp赋值，相当于给main()中的pT1的值
	myp = (Teacher *) malloc(sizeof(Teacher));
	if(myp == NULL)
	{
		return -2;
	}
	myp->age = 44;
	return 0;
}

void FreeTeacher(Teacher * t)
{
	if(t != NULL)
	{
		free(t);
	}
}
void main()
{
	Teacher * pT1 = NULL;
	//1、C语言中的二级指针
	getTeacher(&pT1);
	cout<<"age:"<<pT1->age<<endl;
	FreeTeacher(pT1);
	//2、C++中的引用（指针的引用）
	//引用的本质 简介赋值后两个条件，让C++编译器帮我们做了
	getTeacher2(pT1);
	cout<<"age:"<<pT1->age<<endl;
	FreeTeacher(pT1);
	pT1 = NULL;
	system("pause");
}