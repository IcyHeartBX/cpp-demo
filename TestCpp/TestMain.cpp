//============================================================================
// Name        : TestCpp.cpp
// Author      : pix
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "OperatorDemo.h"
#include "My_Array.h"
#include "My_String.h"
#include "test_extends_construct.h"


void test_char(const char * str);
int main(void)
{
	puts("Hello World!!!");
//	Test_Operator();
//	Test_Operator_Print();
//  Test_Array();
//	Test_String();
//	test_char("abc");
	test_extends_construct();

	return EXIT_SUCCESS;
}


void test_char(const char * str)
{
	printf("str length:%d\n",strlen(str));
}
