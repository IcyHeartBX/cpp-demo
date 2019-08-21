/*
 * CSckFactoryImpl1.cpp
 *
 *  Created on: 2017年6月28日
 *      Author: tangpengxiang
 */

#include "CSckFactoryImpl1.h"
#include <iostream>
using namespace std;

CSckFactoryImpl1::CSckFactoryImpl1():p(NULL),len(0)
{

}

CSckFactoryImpl1::~CSckFactoryImpl1()
{

}

/**
 * Socket初始化
 */
int CSckFactoryImpl1::SocketInit()
{
	p = NULL;
	len = 0;
	return 0;
}
/**
 * Socket发送报文
 */
int CSckFactoryImpl1::SocketSend(unsigned char * buf,int buflen)
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
int CSckFactoryImpl1::SocketRecv(unsigned char * buf,int * buflen)
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
int CSckFactoryImpl1::SocketDestory()
{
	if(NULL != p)
	{
		free(p);
		p = NULL;
		len = 0;
	}
	return 0;
}

