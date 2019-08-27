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
	cout<<"无参构造函数"<<endl;
}

Test::~Test()
{
	cout<<"析构函数"<<endl;
}

Test::Test(int a,int b) 
{
	cout<<"有参构造函数"<<endl;
	m_a =a;
	m_b = b;
}
Test::Test(const Test & obj)
{
	cout<<"拷贝构造函数"<<endl;
	m_a = obj.m_a;
	m_b = obj.m_b;
}


void Test::print()
{
	cout<<"a:"<<m_a<<",b:"<<m_b<<endl;
}
//1、copy构造函数，用一个对象去初始化另外一个对象
void main()
{
	Test t1(2,3);
	Test t0(1,1);
	//第一种copy构造的调用时机
	Test t2 = t1;
	t2.print();

	//第二种copy构造的调用时机
	Test t3(t1);
	t3.print();


	t0 = t1; //t1赋值给t0    赋值和初始化是两个不同的概念，所以这里不会调用copy构造函数
	system("pause");
}