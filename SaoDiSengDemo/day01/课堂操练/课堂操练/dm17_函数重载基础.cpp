#include <iostream>
using namespace std;

void myPrint(int a)
{
	printf("a:%d\n", a);
}

void myPrint(int a,int b)
{
	printf("a:%d,b:%d\n", a,b);
}

void myPrint(char * p)
{
	printf("p:%s\n", p);
}

void main����()
{
	myPrint(19);
	myPrint("hello...");
	myPrint(19, 20);

}

//�������غʹ�Ĭ�ϲ����ĺ���
void func1(int a)
{
	printf("a:%d \ n");
}

void func1(int a, int b = 0)
{

}

void main()
{
	//func1(1); ����ʧ�ܣ�����������ԣ�
	system("pause");
}

