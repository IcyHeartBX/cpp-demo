/*
 * CEncDesProtocol.h
 *  加解密协议
 *  Created on: 2017年6月29日
 *      Author: tangpengxiang
 */

#ifndef SRC_CENCDESPROTOCOL_H_
#define SRC_CENCDESPROTOCOL_H_

class CEncDesProtocol
{
public:
	virtual ~CEncDesProtocol(){}
	virtual int EncData(unsigned char * plain,int plainlen,unsigned char * cryptdata,int * cryptlen) = 0;
	virtual int DesData(unsigned char * cryptdata,int cryptlen,unsigned char * plain,int * plainlen) = 0;
};

#endif /* SRC_CENCDESPROTOCOL_H_ */
