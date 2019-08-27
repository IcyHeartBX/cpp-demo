#include <iostream>
using namespace std;

//1、文件中iostream 没有引入标准的std,所以需要我们手工的写入。
//2、如果不写using namespace std;需要手工写std::cout,std::endl;
void main31()
{
	std::cout<<"hello..."<<std::endl;
	system("pause");
}

//3、定义命名空间
namespace NSA
{
	int a = 10;
}

namespace NSB
{
	int a = 20;
	namespace NSC	//嵌套定义
	{
		struct Teacher
		{
			char name[20];
			int age;
		};
	}
}

//4、使用命名空间
void main()
{
	using namespace NSA;
	cout<<a<<endl;
	cout<<NSB::a<<endl;
	//显示写全
	NSB::NSC::Teacher t1;
	t1.age = 30;

	system("pause");
}