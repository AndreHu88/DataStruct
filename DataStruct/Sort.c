//
//  Sort.c
//  DataStruct
//
//  Created by Jack on 2021/7/8.
//  Copyright © 2021 hu. All rights reserved.

//

#include "Sort.h"

/**
 (1)定义两个变量low和high，将low、high分别设置为要进行排序的序列的起始元素和最后一个元素的下标。第一次，low和high的取值分别为0和n-1，接下来的每次取值由划分得到的序列起始元素和最后一个元素的下标来决定。
 
 (2)定义一个变量key，接下来以key的取值为基准将数组A划分为左右两个部分，通 常，key值为要进行排序序列的第一个元素值。第一次的取值为A[0]，以后毎次取值由要划 分序列的起始元素决定。
 
 (3)从high所指向的数组元素开始向左扫描，扫描的同时将下标为high的数组元素依次与划分基准值key进行比较操作，直到high不大于low或找到第一个小于基准值key的数组元素，然后将该值赋值给low所指向的数组元素，同时将low右移一个位置。
 
 (4)如果low依然小于high，那么由low所指向的数组元素开始向右扫描，扫描的同时将下标为low的数组元素值依次与划分的基准值key进行比较操作，直到low不小于high或找到第一个大于基准值key的数组元素，然后将该值赋给high所指向的数组元素，同时将high左移一个位置。

 (5)重复步骤(3)
 
 (4)，直到low的植不小于high为止，这时成功划分后得到的左右两部分分别为A[low……pos-1]和A[pos+1……high]，其中，pos下标所对应的数组元素的值就是进行划分的基准值key，所以在划分结束时还要将下标为pos的数组元素赋值 为 key。

 (6)将划分得到的左右两部分A[low……pos-1]和A[pos+1……high]继续采用以上操作步骤进行划分，直到得到有序序列为止。
 */
int partition(int arr[], int low, int high) {
    
    ///分治进行划分的基准
    int key = arr[low];
    while (low < high) {
        
        while (low < high && arr[high] > key) {
            /// high向左扫描
            high--;
        }
        
        if (low < high) {
         
            arr[low++] = arr[high];
        }
        
        while(low < high && arr[low] <= key ) {
            /// low右移
            low++;
        }
    
        if(low < high) {

            arr[high--] = arr[low];
        }
                   
    }
    
    arr[low] = key;
    return low;
}

void quickSort(int arr[], int start, int end) {
    
    int pos;
    if (start < end){
        
        pos = partition(arr, start, end);
        quickSort(arr, start, pos - 1);
        quickSort(arr, pos + 1, end);
    }
    return;
}

