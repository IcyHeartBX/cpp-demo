/******************************************************
 *
 *  des.c
 *  common des......
 *
 ******************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"

#define KEY  "DES"

int DesEnc(
		unsigned char *pInData,
		int            nInDataLen,
		unsigned char *pOutData,
		int           *pOutDataLen)
{
	char * key = KEY;
	memcpy(pOutData,pInData,nInDataLen);
	memcpy(pOutData + nInDataLen,key,sizeof(key));
	*pOutDataLen = nInDataLen + sizeof(key);
	return 0;
}

//�û�ʹ�ú���des����
int DesDec(
	   unsigned char *pInData,
	   int            nInDataLen,
	   unsigned char *pOutData,
	   int           *pOutDataLen)
{
	char * key = KEY;
	memcpy(pOutData,pInData,nInDataLen - sizeof(key));
	*pOutDataLen = nInDataLen - sizeof(key);
	return 0;
}


