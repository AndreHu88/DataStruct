//
//  Search.c
//  DataStruct
//
//  Created by Jack on 2019/8/13.
//  Copyright © 2019 hu. All rights reserved.
//

#include "Search.h"


/**
    普通的查找
    1. 需遍历整个数组，效率太低
    2. 这样一个数据查找最少需要1次，那么最多需要n次，平均下来可以看成是（1+n）/2，差不多是n的一半。
    3. 我们把这种比较次数和n成正比的算法复杂度记为o（n）
 */
int find(int array[], int length, int value) {
    
    if (array == NULL || length == 0) {
        return -1;
    }
    
    for (int index = 0; index < length; index++) {
        
        if (array[index] == value) {
            return index;
        }
    }
    return -1;
}

/**
     二分法查找
     1. 有序数组
     2. 高效查找
     3. 时间复杂度  log（n + 1）/ log（2）
 */
int binary_search(int array[], int length, int value) {
    
    if (array == NULL || length == 0) {
        return -1;
    }
    
    int start = 0;
    int end = length - 1;
    while (start <= end) {
        
        int middle = start + (end - start) / 2;
        if (array[middle] == value) {
            return middle;
        }
        else if (array[middle] < value) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }
    return -1;
}

/**
     指针类型查找
     1. 二叉树排序
     2. 非叶子节点至少一边的分支非NULL
     3. 叶子节点左右分支都为NULL
     4. 每一个节点记录一个数据，同时左分支的数据都小于右分支的数据
 */
const Node *find_data(const Node * pNode, int data) {
    
    if (pNode == NULL) {
        return NULL;
    }
    
    if (pNode -> data == data) {
        return pNode;
    }
    else if (pNode -> data > data) {
        return find_data(pNode -> left, data);
    }
    else {
        return find_data(pNode -> right, data);
    }
}


LinkNode *hash_find(LinkNode *array[], int mod , int data) {
    
    int index = data % mod;
    if (array[index] == NULL) {
        return NULL;
    }
    
    LinkNode *pLinkNode = array[index];
    while (pLinkNode) {
        if (pLinkNode -> data == data) {
            return pLinkNode;
        }
        pLinkNode = pLinkNode -> next;
    }
    return pLinkNode;
}
