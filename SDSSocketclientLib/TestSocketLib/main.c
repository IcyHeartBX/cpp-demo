//
//  main.cpp
//  TestSocketLib
//
//  Created by 唐鹏翔 on 2017/7/7.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "socketclientlib.h"

int HW_EncData(unsigned char * inlen,int len,unsigned char * out,int *outlen)
{
    printf("FUNC HW_EncData(),RUN...\n");
    strcpy(out, "123456789");
    *outlen = 9;
    return 0;
}

int main()
{
    int		ret = 0;
    void	*handle = NULL;
    
    char buf[128]; /*in*/
    int buflen = 3;/*in*/
    
    char outbuf[128]; /*in*/
    int outbuflen = 3;/*in*/
    strcpy(buf, "dsssssssssdswdfafd");
    
    ret = cltSocketInit(&handle /*out*/);
    if (ret != 0)
    {
        printf("func cltSocketInit() err:%d \n", ret);
        return ret;
    }
    
    //øÕªß∂À∑¢±®Œƒ
//    ret =  cltSocketSend(handle /*in*/, buf /*in*/, buflen /*in*/);
    ret = cltSocketSendAndEnc(handle,buf,buflen,HW_EncData);
    if (ret != 0)
    {
        printf("func cltSocketSend() err:%d \n", ret);
        return ret;
    }
    
    //øÕªß∂À ’±®Œƒ
    ret =  cltSocketRev(handle /*in*/, outbuf /*in*/, &outbuflen /*in out*/);
    if (ret != 0)
    {
        printf("func cltSocketRev() err:%d \n", ret);
        return ret;
    }
    
    
    //øÕªß∂À Õ∑≈◊ ‘¥
    cltSocketDestory(handle/*in*/);
    
    return ret ;
}


int main01()
{
    int		ret = 0;
    void	*handle = NULL;
    
    char buf[128]; /*in*/
    int buflen = 3;/*in*/
    
    char outbuf[128]; /*in*/
    int outbuflen = 3;/*in*/
    strcpy(buf, "dsssssssssdswdfafd");
    
    ret = cltSocketInit(&handle /*out*/);
    if (ret != 0)
    {
        printf("func cltSocketInit() err:%d \n", ret);
        return ret;
    }
    
    //øÕªß∂À∑¢±®Œƒ
    ret =  cltSocketSend(handle /*in*/, buf /*in*/, buflen /*in*/);
    if (ret != 0)
    {
        printf("func cltSocketSend() err:%d \n", ret);
        return ret;
    }
    
    //øÕªß∂À ’±®Œƒ
    ret =  cltSocketRev(handle /*in*/, outbuf /*in*/, &outbuflen /*in out*/);
    if (ret != 0)
    {
        printf("func cltSocketRev() err:%d \n", ret);
        return ret;
    }
    
    
    //øÕªß∂À Õ∑≈◊ ‘¥
    cltSocketDestory(handle/*in*/);
    
    return ret ;
}


int main02()
{
    int		ret = 0;
    void	*handle = NULL;
    
    char buf[128]; /*in*/
    int buflen = 3;/*in*/
    
    //char outbuf[128]; /*in*/ outbuf //≥£¡ø÷∏’Î
    //int outbuflen = 3;/*in*/
    
    char	*pout = NULL;
    int		poutlen = 0;
    strcpy(buf, "dsssssssssdswdfafd");
    
    ret = cltSocketInit2(&handle);
    
    //buflen = -133332;
    
    
    //øÕªß∂À∑¢±®Œƒ
    ret = cltSocketSend2(handle, buf,  buflen);
    if (ret != 0)
    {
        return ret;
    }
    
    //øÕªß∂À ’±®Œƒ
    ret = cltSocketRev2(handle, &pout, &poutlen);  //‘⁄∂ØÃ¨ø‚¿Ô√Ê∑÷≈‰ƒ⁄¥Ê¡À...
    if (ret != 0)
    {
        return ret;
    }
    /*
     if (pout != NULL)
     {
     free(pout);
     }
     */
    cltSocketRev2_Free(&pout); //±‹√‚“∞÷∏’Î  ∞—outbufÀ˘÷∏œÚµƒƒ⁄¥Ê Õ∑≈,Õ¨ ±∞—outbuf±‰¡ø∏≥÷µNULL
    
    //ret = cltSocketRev2_Free(&pout);
    //øÕªß∂À Õ∑≈◊ ‘¥
    
    cltSocketDestory2(&handle);
    return 0;
}
