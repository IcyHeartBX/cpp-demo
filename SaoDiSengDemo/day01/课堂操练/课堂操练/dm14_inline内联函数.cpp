#include <iostream>
using namespace std;


inline void printA()
{
	int a = 10;
	cout<< "a:" << a<<endl;
}
void main()
{
	printA();
	/*Ïàµ±ÓÚ
	{
		int a = 10;
		cout<< "a:" << a<<endl;
	}
	*/
	system("pause");
}