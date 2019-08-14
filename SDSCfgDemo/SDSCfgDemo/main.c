//
//  main.c
//  SDSCfgDemo
//
//  Created by PixBoly on 2017/12/7.
//  Copyright © 2017年 pix. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "cfg_opt.h"
#define CFG_FILE_NAME          "/Volumes/Data/dev/code/demo/cpp/SDSCfgDemo/SDSCfgDemo/cfg2.ini"

// 显示菜单
void show_menu() {
    printf("======================================\n");
    printf("1、测试写配置文件\n");
    printf("2、测试读配置文件\n");
    printf("0、退出 \n");
    printf("======================================\n");
}

// 读取配置文件
int get_config(){
    int      ret = 0 ;
    char    key[1024] = {0};
    char    value[1024] = {0};
    int     vlen = 0 ;
    
    //输入key
    printf("请输入key值:\n");
    scanf("%s",key);
    if(0 == strlen(key)<=0){
        printf("key值输入有误，请重新输入:\n");
        scanf("%s",key);
    }
    
    ret = GetCfgItem(CFG_FILE_NAME,key,value,&vlen);
    if(ret != 0)
    {
        printf("FUNC get_config(),GetCfgItem() err:%d\n",ret);
        return ret ;
    }
    printf("value :%s\n",value);
    return ret ;
}

int put_config(){
    int     ret = 0 ;
    char    key[1024] = {0};
    char    value[1024] = {0};
    
    //输入key
    printf("请输入key值:\n");
    scanf("%s",key);
    //输入value
    printf("请输入value值:\n");
    scanf("%s",value);
    
    ret = WriteCfgItem(CFG_FILE_NAME,key,value,sizeof(value));
    if(ret != 0)
    {
        printf("Func WriteCfgItem() err:%d\n");
        return ret ;
    }
    return ret ;
}


int main(int argc, const char * argv[]) {
    int ret = 0 ;
    int chose ;
    
    for (;;)
    {
        //显示菜单
        show_menu() ;
        //选择菜单项
        scanf("%d",&chose);
        switch (chose)
        {
            case 1:		//测试写
                put_config();
                break ;
            case 2:		//测试读
                get_config();
                break ;
            case 0:
                goto END ;
                break ;

        }
    }
END:
    return 0;
}
