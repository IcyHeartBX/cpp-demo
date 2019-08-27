#include <iostream>
using namespace std;

void main91()
{
	int a = 10;
	int & b = a;
	b = 100;
	printf("a = %d\n",a);
	printf("b = %d\n",b);

}

void main92()
{
	int a = 10;
	int & b = a;	//�൱�� int * const b = &a;
	b = 100;		//�൱�� *b = 100;
}


void main93()
{
	int a = 10;
	//int & c; //���ñ���Ҫ��ʼ��
	int & c = a;
}


//��������������
int myswap(int a ,int b)
{
	int c = a;
	a = b;
	b = c;
	return 0 ;
}

int myswap02(int * a ,int * b)
{
	int c = *a;
	*a = *b;
	*b = c;
	return 0 ;
}

int myswap03(int & a ,int & b)
{
	int c = a;
	a = b;
	b = c;
	return 0 ;
}

void main94()
{
	int a = 10;
	int b = 20;
	myswap(a,b);
	printf("a:%d,b:%d\n",a,b);
	myswap02(&a,&b);
	printf("a:%d,b:%d\n",a,b);
	myswap03(a,b);
	printf("a:%d,b:%d\n",a,b);
	system("pause");
	
}

//��������������������������
struct Teacher
{
	char name[64];
	int age;
};

void printT(Teacher * pT)
{
	printf("Teacher pT->age:%d\n",pT->age);
}

//pT��t1�ı������൱���޸���t1
void printT2(Teacher & pT)
{
	printf("Teacher pT.age:%d\n",pT.age);
	pT.age = 22;
}

//pT��t1����������
void printT3(Teacher pT)
{
	printf("Teacher pT.age:%d\n",pT.age);
	pT.age =33;
}

void main()
{
	Teacher t1 ;
	t1.age = 30;
	printT(&t1);
	printT2(t1); //pT��t1�ı���
	printT3(t1); //pT���β�t1����һ�����ݸ�pT,������ʱ����
	printf("t1.age:%d\n",t1.age);
	system("pause");
}