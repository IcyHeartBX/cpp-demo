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

Test::Test()	//构造函数
{
	//完成属性初始化
	cout<<"构造函数Test()执行"<<endl;
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
	cout<<"析构函数Test()执行"<<endl;
}

void Test::print()
{
	cout<<"p:"<<p<<endl;
	cout<<"a:"<<a<<endl;
}

//创建舞台，方便研究生命周期
void testClass()
{
	//先创建的，后析构
	Test t1,t2;
	t1.print();
	t2.print();
}
void main()
{
	testClass();
	system("pause");
}