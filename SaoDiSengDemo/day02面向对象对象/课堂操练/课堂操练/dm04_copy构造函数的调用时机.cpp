#include <iostream>
using namespace std;

class Test
{
public:
	Test();
	Test(int a,int b);
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

Test::~Test()
{
	cout<<"��������"<<endl;
}

Test::Test(int a,int b) 
{
	cout<<"�вι��캯��"<<endl;
	m_a =a;
	m_b = b;
}
Test::Test(const Test & obj)
{
	cout<<"�������캯��"<<endl;
	m_a = obj.m_a;
	m_b = obj.m_b;
}


void Test::print()
{
	cout<<"a:"<<m_a<<",b:"<<m_b<<endl;
}
//1��copy���캯������һ������ȥ��ʼ������һ������
void main()
{
	Test t1(2,3);
	Test t0(1,1);
	//��һ��copy����ĵ���ʱ��
	Test t2 = t1;
	t2.print();

	//�ڶ���copy����ĵ���ʱ��
	Test t3(t1);
	t3.print();


	t0 = t1; //t1��ֵ��t0    ��ֵ�ͳ�ʼ����������ͬ�ĸ���������ﲻ�����copy���캯��
	system("pause");
}