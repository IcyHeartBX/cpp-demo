/*
 * HwEncDesImpl.h
 *
 *  Created on: 2017年6月29日
 *      Author: tangpengxiang
 */

#ifndef SRC_CHWENCDESIMPL_H_
#define SRC_CHWENCDESIMPL_H_

#include "CEncDesProtocol.h"

class CHwEncDesImpl: public CEncDesProtocol {
public:
	CHwEncDesImpl();
	virtual ~CHwEncDesImpl();
	virtual int EncData(unsigned char * plain,int plainlen,unsigned char * cryptdata,int * cryptlen);
	virtual int DesData(unsigned char * cryptdata,int cryptlen,unsigned char * plain,int * plainlen);
};

#endif /* SRC_CHWENCDESIMPL_H_ */
