#include <iostream>
using namespace std;

void main()
{
	bool b1 = true;
	//����ռ���ڴ��С��1���ֽ��ڴ�
	cout<<"sizeof(bool)��"<<sizeof(bool)<<endl;

	//bool����Ҫô��1��Ҫô��0û������ֵ
	b1 = 10;
	cout<<"b1:"<<b1<<endl;

	b1 =-10;
	cout<<"b1:"<<b1<<endl;

	b1 = false;
	cout<<"b1:"<<b1<<endl;

	system("pause");
}