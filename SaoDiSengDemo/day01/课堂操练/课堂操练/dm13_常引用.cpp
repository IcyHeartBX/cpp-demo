#include <iostream>
using namespace std;

//�����õ�֪ʶ�ܹ�
void main1301()
{
	//��ͨ����
	int a = 10;
	int & b = a;
	printf("b:%d\n",b);
	//������
	int x = 20;
	//�����ã��ñ�������ֻ�����ԣ�����ͨ��yȥ�޸�x
	const int & y = x;	

	//�����õĳ�ʼ������Ϊ�������
	//1���ñ�����ʼ����Ӧ��
	{
		int x1 = 30;
		const int & y1 = x1;  //��x1����ȥ��ʼ��������
	}
	//2������������ʼ��������
	{
		const int  a = 40; // C++��������a�ŵ����ű�����
		//int & b = 41;		//��ͨ��������һ����������������û���ڴ��ַ
							//���þ��Ǹ��ڴ�ȡ������û���ڴ���ôȡ������
		const int & c = 42; //C++���������m����һ���ڴ棬��ȡ����c
	}

	//
	system("pause");
}

struct Teacher 
{
	char name[64];
	int age;
};

void printTeacher(const Teacher & t)
{
	//�������ñ���ӵ��ֻ������
	//t.age = 44;
	cout<<"age:"<<t.age<<endl;
}

void main()
{
	Teacher t1;
	t1.age = 33;
	printTeacher(t1);
	system("pause");
}