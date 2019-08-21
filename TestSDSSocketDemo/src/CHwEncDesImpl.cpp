/*
 * CHwEncDesImpl.cpp
 *
 *  Created on: 2017年6月29日
 *      Author: tangpengxiang
 */

#include "CHwEncDesImpl.h"
#include "des.h"
#include <iostream>
using namespace std;

CHwEncDesImpl::CHwEncDesImpl() {
	// TODO Auto-generated constructor stub

}

CHwEncDesImpl::~CHwEncDesImpl() {
	// TODO Auto-generated destructor stub
}

int CHwEncDesImpl::EncData(unsigned char * plain,int plainlen,unsigned char * cryptdata,int * cryptlen)
{
	printf("FUNC CHwEncDesImpl::EncData(),RUN,plain;%s,plainlen:%d,cryptdata:%s,cryptlen:%p\n",plain,plainlen,cryptdata,cryptlen);
	int ret = 0;
	ret = DesEnc(plain,plainlen,cryptdata,cryptlen);
	if(0 != ret)
	{
		printf("FUNC DesEnc(),Error,ret:%d\n",ret);
	}
	return ret;
}
int CHwEncDesImpl::DesData(unsigned char * cryptdata,int cryptlen,unsigned char * plain,int * plainlen)
{
	printf("FUNC CHwEncDesImpl::DesData(),RUN\n");
	int ret = 0;
	ret = DesDec(cryptdata,cryptlen,plain,plainlen);
	if(0 != ret)
	{
		printf("FUNC DesDec(),ERROR,ret:%d\n",ret);
		return ret;
	}
	return 0;
}
