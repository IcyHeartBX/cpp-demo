#include <iostream>
using namespace std;

class Test
{
public:
	Test();
	Test(int a,int b);
	Test(int a);
	//Copy���캯��,�ö����ʼ������
	Test(const Test & obj);
	~Test();

public:
	void print();

private:
	int m_a;
	int m_b;
};

Test::Test()
{
	cout<<"�޲ι��캯��"<<endl;
}

Test::Test(int a,int b)
{
	cout<<"�вι��캯��"<<endl;
	m_a = a;
	m_b = b;
}

Test::Test(int a)
{
	m_a = a;
}

Test::Test(const Test & obj)
{
	cout<<"copy���캯��"<<endl;
}

Test::~Test()
{
}

void Test::print()
{

}

void testClass()
{
	//�޲�
	Test t1; //�޲ι��캯������
	//Test t1();		//�������������޲ι��캯��

	//�в�
	//���ŷ�
	Test t2(2,4); //���ŷ������вι��캯��
	//�Ⱥ�=��
	//����Ҫע�⣬�������õ���һ�������Ĺ��캯�������ܵ���2������������
	Test t22 =(3,5);	
	Test t222 = 5;
	//ֱ�ӵ��ù��캯��,���������һ����������
	Test t3 = Test(1,2);

	Test t4 = t2;

}

void main()
{
	testClass();
	system("pause");
}