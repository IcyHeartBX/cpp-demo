//============================================================================
// Name        : TestSDSSocketDemo.cpp
// Author      : pix
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CSocketProtocol.h"
#include "CSckFactoryImpl1.h"
#include "CSckFactoryImpl2.h"
#include "CEncDesProtocol.h"
#include "CHwEncDesImpl.h"

class MainOp {
public:
	MainOp()
	{
		this->m_sp = NULL;
		this->m_edp = NULL;
	}
	MainOp(CSocketProtocol * sp,CEncDesProtocol * edp)
	{
		this->m_sp = sp;
		this->m_edp = edp;
	}
	void SetCSocketProtocol(CSocketProtocol * sp)
	{
		this->m_sp = sp;
	}

	void SetCEncDesProtocol(CEncDesProtocol * edp)
	{
		this->m_edp = edp;
	}

	// 模拟调用,面向抽象类编程框架 ---带加解密
	int SckSendAndRecv_EncDes(unsigned char * in, int inlen,unsigned char * out,int * outlen)
	{
		int ret = 0;
		if(NULL == m_sp || NULL == m_edp)
		{
			ret = -1;
			return ret;
		}
		unsigned char data[4096];
		int datalen = 0;
		ret = this->m_sp->SocketInit();
		if(0 != ret)
		{
			printf("FUNC SocketInit(),ERROR,ret:%d\n",ret);
			goto END;
		}
		ret = this->m_edp->EncData(in, inlen, data, &datalen);
		if(0 != ret) {
			printf("FUNC EncData(),ERROR,ret:%d\n",ret);
			goto END;
		}
		ret = this->m_sp->SocketSend(data,datalen);
		if(0 != ret)
		{
			printf("FUNC SocketSend(),ERROR,ret:%d\n",ret);
			goto END;
		}
		ret = this->m_sp->SocketRecv(data,&datalen);
		if(0 != ret)
		{
			printf("FUNC SocketRecv(),ERROR,ret:%d\n",ret);
			goto END;
		}
		ret = this->m_edp->DesData(data, datalen, out, outlen);
		if(0 != ret)
		{
			printf("FUNC DesData(),ERROR,ret:%d\n",ret);
			goto END;
		}

END:
		ret = m_sp->SocketDestory();
		return ret;
	}
private:
	CSocketProtocol * m_sp;
	CEncDesProtocol * m_edp;
};

int main(void) {
	int ret = 0;
	CSocketProtocol * sp = NULL;
	CEncDesProtocol * edp = NULL;
	MainOp * op = NULL;
//	sp = new CSckFactoryImpl1;
	sp = new CSckFactoryImpl2;
	edp = new CHwEncDesImpl;
	op = new MainOp(sp,edp);

	unsigned char inBuf [4096] = {0};
	unsigned char outBuf [4096] = {0};
	int outLen = 0;
	int inLen = 9;
	strcpy((char*)inBuf,"HelloWorld");

	ret = op->SckSendAndRecv_EncDes(inBuf,inLen,outBuf,&outLen);
	if(0 != ret)
	{
		printf("FUNC SckSendAndRecv(),Error,ret:%d\n",ret);
	}
	if(NULL != sp)
	{
		delete sp;	// 如果使用父类指针释放子类内存，应该用虚析构函数
		sp = NULL;
	}
	if(NULL != edp)
	{
		delete edp;
		edp = NULL;
	}
	if(NULL != op)
	{
		delete op;
		op = NULL;
	}
	printf("outBuf:%s\n",outBuf);
	return ret;
}
