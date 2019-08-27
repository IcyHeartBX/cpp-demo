#include <iostream>
using namespace std;

class Test
{
public:
	Test();
	Test(int a,int b);
	Test(int a);
	//Copy构造函数,用对象初始化对象
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

Test::Test(int a,int b)
{
	cout<<"有参构造函数"<<endl;
	m_a = a;
	m_b = b;
}

Test::Test(int a)
{
	m_a = a;
}

Test::Test(const Test & obj)
{
	cout<<"copy构造函数"<<endl;
}

Test::~Test()
{
}

void Test::print()
{

}

void testClass()
{
	//无参
	Test t1; //无参构造函数调用
	//Test t1();		//不能这样调用无参构造函数

	//有参
	//括号发
	Test t2(2,4); //括号法调用有参构造函数
	//等号=法
	//这里要注意，这样调用的是一个参数的构造函数，不能调用2个参数或更多的
	Test t22 =(3,5);	
	Test t222 = 5;
	//直接调用构造函数,这样会产生一个匿名对象
	Test t3 = Test(1,2);

	Test t4 = t2;

}

void main()
{
	testClass();
	system("pause");
}