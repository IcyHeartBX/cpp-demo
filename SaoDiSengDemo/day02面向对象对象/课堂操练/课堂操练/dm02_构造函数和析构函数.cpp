#include <iostream>
using namespace std;

class Test
{
public:
	Test();
	~Test();
	void print();

private:
	char * p;
	int a;

};

Test::Test()	//���캯��
{
	//������Գ�ʼ��
	cout<<"���캯��Test()ִ��"<<endl;
	p = (char *)malloc(100);
	memcpy(p,"aaaabbb",10);
	a = 10;
}

Test::~Test()
{
	if(p != NULL)
	{
		free(p);
	}
	a = 0;
	cout<<"��������Test()ִ��"<<endl;
}

void Test::print()
{
	cout<<"p:"<<p<<endl;
	cout<<"a:"<<a<<endl;
}

//������̨�������о���������
void testClass()
{
	//�ȴ����ģ�������
	Test t1,t2;
	t1.print();
	t2.print();
}
void main()
{
	testClass();
	system("pause");
}