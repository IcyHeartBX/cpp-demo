/*
 *  socketclientlib.h
 *  socketclientlib
 *
 *  Created by 唐鹏翔 on 2017/7/7.
 *
 *
 */

#ifndef socketclientlib_h
#define socketclientlib_h

#ifdef __cplusplus
extern "C" {
#endif

/* The classes below are exported */
#pragma GCC visibility push(default)
    
    
// 完成发送报文的时候进行加解密
//int EncData(unsigned char * inlen,int len,unsigned char * out,int outlen);
//
//int DecData(unsigned char * in,int inlen,unsigned char * out,int outlen);
    
// 定义函数指针类型，通过指针类型来约定厂商去实现加密解密厂商的原型
typedef int (*EncData)(unsigned char * in,int inlen,unsigned char * out,int * outlen);
    
typedef int (*DecData)(unsigned char * in,int inlen,unsigned char * out,int * outlen);
    

int cltSocketInit(void **handle /*out*/);
    
int cltSocketSetEncCallback(void *handle /*in*/,EncData encCallback);

int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/);
int cltSocketSendAndEnc(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/,EncData encCallback);

int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);
int cltSocketRevAndDec(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/,DecData decCallback);

int cltSocketDestory(void *handle/*in*/);


// 第二套Api
int cltSocketInit2(void **handle);

int cltSocketSend2(void *handle, unsigned char *buf,  int buflen);

int cltSocketRev2(void *handle, unsigned char **buf, int *buflen);

int cltSocketRev2_Free(unsigned char **buf);

int cltSocketDestory2(void **handle);



#pragma GCC visibility pop
    
#ifdef __cpluscplus
}
#endif

#endif
