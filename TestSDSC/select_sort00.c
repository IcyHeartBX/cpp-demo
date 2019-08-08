//
// Created by pixboly on 2018/11/22.
//

#include "select_sort00.h"

#include <stdio.h>
#include <stdlib.h>
void test_select_sort00(void) {
    int intarr[10] = {11,22,4,2,54,33,43,64,3,443};

    //排序
    int i,j;
    int len = sizeof(intarr) /  sizeof(intarr[0]);

    // 排序前打印
    test_print_arr00(intarr,len);
    for(i = 0; i < len; i++) {
        for(j = i + 1; j < len; j++) {
            int tmp = intarr[i];
            if(intarr[i] > intarr[j]) {
                intarr[i] = intarr[j];
                intarr[j] = tmp;
            }
        }
    }
    printf("\n");
    test_print_arr00(intarr,sizeof(intarr) / sizeof(intarr[0]));
}

void test_print_arr00(int * arr,int len) {
    if(NULL == arr || 0 >= len) {
        return ;
    }
    for(int i = 0; i < len; i++) {
        printf("%d ",*(arr + i));
    }
}

