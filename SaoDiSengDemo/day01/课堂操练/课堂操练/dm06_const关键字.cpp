#include <iostream>
using namespace std;

struct Teacher
{
	char name[64];
	int age;
};

//ָ����ָ����ڴ�ռ䲻�ܱ��޸�
int optTeacher01(const Teacher * pT)
{
	//pT->age = 100;
	return 0;
}

//ָ����������ܱ��޸�
int optTeacher02( Teacher * const pT)
{
	pT->age = 100;
	//pT = NULL;
	return 0;
}

//�����ܱ��޸�
int optTeacher03( const Teacher * const pT)
{
	//pT->age = 100;
	//pT = NULL;
	cout<<pT->age<<endl;
	return 0;
}

void main()
{
	Teacher t1;
	t1.age = 30;		
	optTeacher03(&t1);

	system("pause");
}