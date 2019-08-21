/*
 * CSckFactoryImpl1.h
 *
 *  Created on: 2017年6月28日
 *      Author: tangpengxiang
 */

#ifndef SRC_CSCKFACTORYIMPL2_H_
#define SRC_CSCKFACTORYIMPL2_H_

#include "CSocketProtocol.h"

class CSckFactoryImpl2 : public CSocketProtocol{
public:
	CSckFactoryImpl2();
	virtual ~CSckFactoryImpl2();
	/**
	 * Socket初始化
	 */
	virtual int SocketInit();
	/**
	 * Socket发送报文
	 */
	virtual int SocketSend(unsigned char * buf,int buflen);
	/**
	 * Socket 接收报文
	 */
	virtual int SocketRecv(unsigned char * buf,int * buflen);
	/**
	 * Socket销毁
	 */
	virtual int SocketDestory();
private:
	unsigned char * p;
	int len;
};

#endif /* SRC_CSCKFACTORYIMPL1_H_ */
