#include <iostream>
using namespace std;


struct Teacher
{
	char name[64];
	int age;
};

int getTeacher(Teacher ** p)
{
	if(p == NULL)
	{
		return -1;
	}
	Teacher * temp = NULL;
    temp = (Teacher *)malloc(sizeof(Teacher));
	if(temp == NULL)
	{
		return -2;
	}
	//p��ʵ�εĵ�ַ��*ʵ�εĵ�ַ��ȥ����޸�ʵ�ε�ֵ
	* p = temp;
	temp->age = 33;
	return 0;
}

int getTeacher2(Teacher * &myp)
{
	if(myp == NULL)
	{
		return -1;
	}
	//��myp��ֵ���൱�ڸ�main()�е�pT1��ֵ
	myp = (Teacher *) malloc(sizeof(Teacher));
	if(myp == NULL)
	{
		return -2;
	}
	myp->age = 44;
	return 0;
}

void FreeTeacher(Teacher * t)
{
	if(t != NULL)
	{
		free(t);
	}
}
void main()
{
	Teacher * pT1 = NULL;
	//1��C�����еĶ���ָ��
	getTeacher(&pT1);
	cout<<"age:"<<pT1->age<<endl;
	FreeTeacher(pT1);
	//2��C++�е����ã�ָ������ã�
	//���õı��� ��鸳ֵ��������������C++����������������
	getTeacher2(pT1);
	cout<<"age:"<<pT1->age<<endl;
	FreeTeacher(pT1);
	pT1 = NULL;
	system("pause");
}