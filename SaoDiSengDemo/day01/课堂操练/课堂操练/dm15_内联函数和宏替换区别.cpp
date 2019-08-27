#include <iostream>
using namespace std;

#define MYFUNC(a,b) ((a < b) ? (a) : (b))

inline int myfunc(int a,int b)
{
	return a < b ? a : b;
}

void main()
{
	int a = 1 ;
	int b = 3 ;
	
	int c = MYFUNC(++a,b); 
	//ºêÌæ»»²¢Õ¹¿ª((++a < b) ? (++a) : (b)) a= 3 c =3,b = 3
	//int c = myfunc(++a,b); //a =2, b = 3,c = 2

	printf("a = %d \n",a);
	printf("b = %d \n",b);
	printf("c = %d \n",c);
	
	system("pause");
}