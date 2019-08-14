//
//  cfg_opt.c
//  SDSCfgDemo
//
//  Created by PixBoly on 2017/12/8.
//  Copyright © 2017年 pix. All rights reserved.
//

#include "cfg_opt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE                    2048
#define MAP_SEPARATOR               "="
#define COMMENT_SEPARATOR_1         "#"         //注释分隔符1
#define COMMENT_SEPARATOR_2         "//"        //注释分隔符2


// 去掉字符串前后空格
int string_trim_space(const char * str,char * newstring){
    int ret = 0;
    char * p = str;
    int start,end;
    int strcount ;
    // 安全检查
    if(NULL == str || NULL == newstring) {
        ret = -1;
        printf("FUNC string_trim_space(),NullPointerException\n");
        goto END;
    }
    start = 0;
    end = strlen(str);
    if(end <= start){
        ret = -2;
        printf("FUNC string_trim_space(),string xception\n");
        goto END;
    }
    while(isspace(p[start]) && p[start] != '\0'){
        start++;
    }
    
    while(isspace(p[end]) && p[end] != '\0'){
        end--;
    }
    
    strcount = end - start;
    strncpy(newstring,str + start ,strcount);
    newstring[strcount]= '\0';
    
    
END:
    return ret;
}

/**
 读取配置文件流程
 1、循环读取文件中的每一行
 2、跳过注释行
 3、判断是否符合配置项规则
 4、判断=号前key是否与输入key相同
 5、找到符合项返回
 
 **/

//获取配置项
int GetCfgItem(const char * pFileName /*in*/,const char * pKey /*int*/,char * value /*in out*/,int * pValueLen/*out*/)
{
    int ret = 0 ;
    FILE * fp = NULL;
    // 文件中一行数据
    char line_str[MAX_LINE] = {0};
    // 文件中一行数据去掉前后空格符
    char line_str_nospace[MAX_LINE] = {0};
    char * p_line;
    // 文件中=号前key值
    char key_str[MAX_LINE] = {0};
    char key_str_nospace[MAX_LINE] = {0};
    char value_str[MAX_LINE] = {0};
    
    // 安全检查
    if(NULL == pFileName || NULL == pKey || NULL == value || NULL == pValueLen){
        ret = -1;
        printf("FUNC GetCfgItem(),NullPointer error:%d\n",ret);
        goto END;
    }
    // 传入key去空格处理
    char pKeyNoSpace[MAX_LINE] = {0};
    string_trim_space(pKey, pKeyNoSpace);
    fp = fopen(pFileName, "r");
    if(NULL == fp){
        ret = -2;
        printf("FUNC GetCfgItem(),open file error:%d\n",ret);
        goto END;
    }
    
    // 逐行读数据
    while(!feof(fp)) {
        // 置位数据
        memset(line_str,0,MAX_LINE);
        p_line = fgets(line_str,MAX_LINE,fp);
        if(NULL != p_line){ // 有数据
            printf("FUNC GetCfgItem(),line_str:%s\n",line_str);
            memset(line_str_nospace, 0, MAX_LINE);
            // 去掉前后空格
            string_trim_space(line_str, line_str_nospace);
            
            // 注释行跳过1
            char * pCommentStart = strstr(line_str_nospace, COMMENT_SEPARATOR_1);
            if(NULL != pCommentStart && pCommentStart == line_str_nospace) {
                continue;
            }
            // 注释行跳过2
            pCommentStart = strstr(line_str_nospace, COMMENT_SEPARATOR_2);
            if(NULL != pCommentStart && pCommentStart == line_str_nospace) {
                continue;
            }
            
            // 是否包含key
            char * pKeyStart = strstr(line_str_nospace,pKeyNoSpace);
            if(NULL == pKeyStart) { // 没有key，不符合
                continue;
            }
            // 是否包含分隔符=
            char * pSeparatorStart = strstr(line_str_nospace,MAP_SEPARATOR);
            if(NULL == pSeparatorStart) { // 没有分隔符=
                continue;
            }
            // 取除=号前值
            memcpy(key_str, pKeyStart, pSeparatorStart - pKeyStart);
            // 去空格
            string_trim_space(key_str, key_str_nospace);
            // 比较key值是否相同
            if(strcmp(pKeyNoSpace, key_str_nospace) != 0) {
                continue;
            }
            // 取出=号后的内容
            memcpy(value_str, pSeparatorStart + 1,strlen(line_str_nospace) - (pKeyStart - line_str_nospace) + 1);
            // 最后加1，是结束符
            // 取出value的左右空格
            string_trim_space(value_str, value);
            * pValueLen = strlen(value);
            // 返回value跳出
            break;
         }
        
    }
END:
    if(NULL != fp)
    {
        fclose(fp);
    }
    return ret ;
}

//写配置项
//实现流程
//循环读每一行，检查key配置项是否存在，若存在则修改对应value值
//若不存在，文件末尾添加“key=value”
// 难点如何修改文件流中的值
int WriteCfgItem(const char * pFileName /*in*/,const char * pItemName /*in*/,const char * pItemValue/*in*/,int itemValueLen/*in*/)
{
    int ret = 0 ;
    int iTag = 0,length = 0;
    FILE * fp = NULL;
    char lineBuff[MAX_LINE] = {0};
    char line_str_nospace[MAX_LINE] = {0};
    char * pTmp = NULL, * pBegin = NULL , * pEnd = NULL;
    char fileBuff[1024 * 8] = {0};
    char pKeyNoSpace[MAX_LINE] = {0};
    // 文件中=号前key值
    char key_str[MAX_LINE] = {0};
    char key_str_nospace[MAX_LINE] = {0};
    
    // 安全检查
    if(NULL == pFileName || NULL == pItemName || NULL == pItemValue) {
        ret = -1;
        printf("FUNC WriteCfgItem(),NullPointerException,ret:%d\n",ret);
        goto END;
    }
    // 传入key去空格处理
    string_trim_space(pItemName, pKeyNoSpace);
    
    // 这里采取的策略是，配置文件不存在，那么就创建一个
    
    // 打开文件
    fp = fopen(pFileName, "r+"); // 读写方法
    
    if(NULL == fp){     // 文件不存在
        fp = fopen(pFileName, "w+t");       // 创建文件
        if(NULL == fp) {
            ret = -2;
            printf("FUNC WriteCfgItem(),file don't exist and create error,ret:%d\n",ret);
            goto END;
        }
    }
    
    // 获取文件长度,先把指针移到文件末尾，再获取长度
    fseek(fp, 0L, SEEK_END);
    length = ftell(fp);
    
    // 把指针移动到文件的开头
    fseek(fp, 0L, SEEK_SET);
    
    // 判断文件长度是否超过了我们的预设缓存区
    if(length > 1024 * 8) {
        ret = -3;
        printf("FUNC WriteCfgItem(),file size > 8k,dont support,ret:%d\n",ret);
        goto END;
    }
    
    // 循环读取每一行
    while(!feof(fp)) {
        pTmp = fgets(lineBuff, MAX_LINE, fp);
        if(NULL == pTmp) {
            continue;
        }
        memset(line_str_nospace, 0, MAX_LINE);
        // 去掉前后空格
        string_trim_space(lineBuff, line_str_nospace);
        
        // 注释行跳过1
        char * pCommentStart = strstr(line_str_nospace, COMMENT_SEPARATOR_1);
        if(NULL != pCommentStart && pCommentStart == line_str_nospace) {
            strcat(fileBuff, lineBuff);
            continue;
        }
        // 注释行跳过2
        pCommentStart = strstr(line_str_nospace, COMMENT_SEPARATOR_2);
        if(NULL != pCommentStart && pCommentStart == line_str_nospace) {
            strcat(fileBuff, lineBuff);
            continue;
        }
        
        // 关键字是否在本行
        pTmp = strstr(lineBuff, pItemName);
        if(NULL == pTmp) {  // 关键字不再在本行
            strcat(fileBuff, lineBuff);
            continue;
        }
        else {  // 在本行
            // 是否key相同
            // 是否包含key
            char * pKeyStart = strstr(line_str_nospace,pKeyNoSpace);
            if(NULL == pKeyStart) { // 没有key，不符合
                strcat(fileBuff, lineBuff);
                continue;
            }
            // 是否包含分隔符=
            char * pSeparatorStart = strstr(line_str_nospace,MAP_SEPARATOR);
            if(NULL == pSeparatorStart) { // 没有分隔符=
                strcat(fileBuff, lineBuff);
                continue;
            }
            // 取除=号前值
            memcpy(key_str, pKeyStart, pSeparatorStart - pKeyStart);
            // 去空格
            string_trim_space(key_str, key_str_nospace);
            // 比较key值是否相同
            if(strcmp(pKeyNoSpace, key_str_nospace) != 0) {
                strcat(fileBuff, lineBuff);
                continue;
            }
            memset(lineBuff, 0, MAX_LINE);
            sprintf(lineBuff, "%s=%s\n",pItemName,pItemValue);
            strcat(fileBuff, lineBuff);
            iTag = 1;
        }
    }
    // 若关键字不存在
    if(0 == iTag) {
        fprintf(fp, "%s=%s\n",pItemName,pItemValue);
    }
    else { // 关键在存在，重新创建文件
        if(fp != NULL) {
            fclose(fp);
            fp = NULL;
        }
        fp = fopen(pFileName, "w+t");
        if(NULL == fp) {
            ret = -4;
            printf("FUNC WriteCfgItem(),create file error,ret:%d\n",ret);
            goto END;
        }
        fputs(fileBuff, fp);
    }
    
    
END:
    if(NULL != fp) {
        fclose(fp);
    }
    return ret ;
}
