/*
 * CSocketProtocol.h
 *
 *  Created on: 2017年6月28日
 *      Author: tangpengxiang
 */

#ifndef SRC_CSOCKETPROTOCOL_H_
#define SRC_CSOCKETPROTOCOL_H_

/**
 * Socket 协议接口定义
 */
class CSocketProtocol
{
public:
	virtual ~CSocketProtocol() {};
	/**
	 * Socket初始化
	 */
	virtual int SocketInit() = 0;
	/**
	 * Socket发送报文
	 */
	virtual int SocketSend(unsigned char * buf,int buflen) = 0;
	/**
	 * Socket 接收报文
	 */
	virtual int SocketRecv(unsigned char * buf,int * buflen) = 0;
	/**
	 * Socket销毁
	 */
	virtual int SocketDestory() = 0;
};


#endif /* SRC_CSOCKETPROTOCOL_H_ */
