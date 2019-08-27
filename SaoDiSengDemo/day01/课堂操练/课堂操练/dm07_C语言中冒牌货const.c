#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	//好像a是一个常量
	const int a = 100;
	int * p = NULL;
	p = (int *)&a;
	*p = 20;
	printf("a = %d\n",a);
	system("pause");
}