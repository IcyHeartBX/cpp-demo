#include <iostream>
using namespace std;

//1���ļ���iostream û�������׼��std,������Ҫ�����ֹ���д�롣
//2�������дusing namespace std;��Ҫ�ֹ�дstd::cout,std::endl;
void main31()
{
	std::cout<<"hello..."<<std::endl;
	system("pause");
}

//3�����������ռ�
namespace NSA
{
	int a = 10;
}

namespace NSB
{
	int a = 20;
	namespace NSC	//Ƕ�׶���
	{
		struct Teacher
		{
			char name[20];
			int age;
		};
	}
}

//4��ʹ�������ռ�
void main()
{
	using namespace NSA;
	cout<<a<<endl;
	cout<<NSB::a<<endl;
	//��ʾдȫ
	NSB::NSC::Teacher t1;
	t1.age = 30;

	system("pause");
}