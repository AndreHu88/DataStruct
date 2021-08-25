//
//  LinkList.h
//  DataStruct
//
//  Created by Jack on 2018/6/9.
//  Copyright © 2018年 hu. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node {   //节点结构体
    
    char data;
    struct node *next;
} ListNode;


typedef ListNode *linkList;

//头插法 无头结点插入数据
linkList createLinkList(char *arc ,int length);
//头插法 有头结点插入数据
linkList createLinkListWithHeader(char *arc, int length);

//尾插法 有头结点
linkList createLinkListRear(char *arc, int length);
//尾插法 有头结点
linkList createLinkListRearWithHeader(char *arc, int length);

//按节点序号查找
linkList getNode(linkList head, int i);
//按节点值查找
linkList getNodeValue(linkList head, char value);

//修改某个结点的值
linkList amendElement(linkList p, int amendLocation, char newElement);
linkList insertElement(linkList p, int insertLocation, char newElement);
linkList deleteElement(linkList p, int deleteLocation);

void printLinkList(ListNode *node);

#endif /* LinkList_h */
