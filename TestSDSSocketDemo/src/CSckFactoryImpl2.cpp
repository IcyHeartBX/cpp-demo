/*
 * CSckFactoryImpl2.cpp
 *
 *  Created on: 2017年6月28日
 *      Author: tangpengxiang
 */

#include "CSckFactoryImpl2.h"
#include <iostream>
using namespace std;

CSckFactoryImpl2::CSckFactoryImpl2():p(NULL),len(0)
{

}

CSckFactoryImpl2::~CSckFactoryImpl2()
{

}

/**
 * Socket初始化
 */
int CSckFactoryImpl2::SocketInit()
{
	printf("FUNC CSckFactoryImpl2::SocketInit()\n");
	p = NULL;
	len = 0;
	return 0;
}
/**
 * Socket发送报文
 */
int CSckFactoryImpl2::SocketSend(unsigned char * buf,int buflen)
{
	p = (unsigned char *)malloc(sizeof(unsigned char) * buflen);
	if(NULL == p)
	{
		return -1;
	}
	memcpy(p,buf,buflen);
	this->len = buflen;
	return 0;
}
/**
 * Socket 接收报文
 */
int CSckFactoryImpl2::SocketRecv(unsigned char * buf,int * buflen)
{
	if(NULL == buf || NULL == buflen)
	{
		return -1;
	}
	*buflen = this->len;
	memcpy(buf,this->p,this->len);
	return 0;
}
/**
 * Socket销毁
 */
int CSckFactoryImpl2::SocketDestory()
{
	if(NULL != p)
	{
		free(p);
		p = NULL;
		len = 0;
	}
	return 0;
}

