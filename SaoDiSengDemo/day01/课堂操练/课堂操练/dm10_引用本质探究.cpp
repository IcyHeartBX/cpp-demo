#include <iostream>
using namespace std;

void main01()
{
	int a = 10;
	int & b = a;
	const int c = 20;

	printf("&a:%p,&b:%p\n",&a,&b); //a��b����һ���ڴ�ռ�����ƺ�

	system("pause");
}


//����ռ�ڴ�ռ���
struct Teacher
{
	char name[64];		//64
	int age;			//4
	int & a;  //����ռ�ڴ�ռ���
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
	*a1 = 200;  //ͨ��ָ�����޸�ʵ�ε�ֵ
}
void main()
{
	int a = 10;
	modifyA(a); //�������������������ȡ��ַ�����������ڲ��Լ���ɡ�
	printf("a:%d\n",a);
	modifyA2(&a); //�����ָ�룬��Ҫ�ֹ�ȡ��ַ
	printf("a:%d\n",a);
	system("pause");
}