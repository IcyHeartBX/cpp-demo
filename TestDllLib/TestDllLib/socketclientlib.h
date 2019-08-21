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
    
    int cltSocketInit(void **handle /*out*/);
    
    int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/);
    
    int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);
    
    int cltSocketDestory(void *handle/*in*/);
    
    
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
