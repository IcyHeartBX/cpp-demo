//
//  cfg_opt.h
//  SDSCfgDemo
//
//  Created by PixBoly on 2017/12/8.
//  Copyright © 2017年 pix. All rights reserved.
//

#ifndef cfg_opt_h
#define cfg_opt_h

#include <stdio.h>

#ifdef  __cplusplus
extern "C" {
#endif
    
    //获取配置项
    int GetCfgItem(const char * pFileName /*in*/,const char * pKey /*int*/,char * value /*in out*/,int * pValueLen/*out*/);
    
    //写配置项
    int WriteCfgItem(const char * pFileName /*in*/,const char * pItemName /*in*/,const char * pItemValue/*in*/,int itemValueLen/*in*/);
    
    
#ifdef  __cplusplus
}
#endif

#endif /* cfg_opt_h */
