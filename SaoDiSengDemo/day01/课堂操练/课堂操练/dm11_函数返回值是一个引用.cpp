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



//������Ϊ�������ͣ�������Ϊ�������õĳ�ʼֵ
void main1101()
{
	int a1 = getAA1();
	int a2 = getAA2();
	int & a3 = getAA2();

	printf("a1:%d,a2:%d,a3:%d\n",a1,a2,a3);

	system("pause");
}

//������static��ȫ�ֱ���
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
//��������ֵ

//���ر�����ֵ
int g1()
{
	static int c ;
	c++;
	return c ;
}
//���ر�������
int & g2()
{
	static int c ;
	c++;
	printf("c:%d\n",c);
	return c ;
}

void main()
{
	//g1() = 100; �����������Ϊ��ֵ
	g2() = 100;
	g2();
	int c = g2();
	system("pause");
}