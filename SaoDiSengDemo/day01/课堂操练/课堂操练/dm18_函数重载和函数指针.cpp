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
//����ָ��
//��������һ����������
typedef void (MYFUNC) (int a,int b);
//MYFUNC * myfuncp = NULL; //����һ������ָ�룬���ָ��ָ��һ����������ڵ�ַ
//2������һ������ָ������
typedef void (* MYFUNCP) (int a,int b);
//MYFUNCP myfuncp2 = NULL; //ͨ������ָ�����ͣ����庯��ָ��
//����һ������ָ�����
void (* MYFUNCP2) (int a,int b);


void main()
{
	MYFUNCP fp = NULL;  
	fp = myfunc;
	fp(1,2);
	system("pause");
}