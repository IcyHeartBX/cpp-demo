#include <iostream>
using namespace std;

void myPrint(int i = 10)
{
	cout << "i = " << i << endl;
}

//����������д�Ĭ�ϲ����ģ��в���Ĭ�ϲ����ģ����뽫����Ĭ�ϲ�����д��ǰ��
void myPrint2(int j,int i = 10,int k = 20)
{
	cout << "i = " << i << endl;
}

void mainĬ�ϲ���()
{
	//����д������ʹ����д�ģ�����д����Ĭ��
	myPrint(20);
	myPrint();
}

///////////ռλ����

//������ռλ��������������ʱ����д������
void func1(int a, int b, int)
{
	cout << "a:" << a << ",b:" << b << endl;
}


void mainռλ����()
{
	//func1(2, 3);
	func1(2, 3, 4);
}


/////////Ĭ�ϲ�����ռλ����

//���Ĭ�ϲ�����ռλ������һ��д2��3���������ܵ�������
void func2(int a, int b, int = 0)
{
	cout << "a:" << a << ",b:"<<b << endl;
}

void main()
{
	func2(2, 3);
	func2(2, 3, 4);
}
