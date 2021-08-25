//
//  LinkList.c
//  DataStruct
//
//  Created by Jack on 2018/6/9.
//  Copyright © 2018年 hu. All rights reserved.
//

#include "LinkList.h"

ListNode *p;                //定义一个指向节点的指针变量
ListNode header;            //指向单链表的头指针

//头插法插入数据
linkList createLinkList(char *arc ,int length){
    
    linkList head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p = NULL;
    
    //最初状态下，head头指针没有任何结点 插入第一个元素，就相当于创建结点
    head -> data = arc[0];
    head -> next = NULL;
    
    for (int i = 0; i < length; i++) {
        
        p = (ListNode *)malloc(sizeof(ListNode));
        p -> data = arc[i];
        //插入元素时，首先将插入位置后的链表链接到新结点上
        p -> next = head;
        head = p;
    }
    
    return head;
}

//有头结点链表的插入
linkList createLinkListWithHeader(char *arc, int length){
    
    linkList head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p = NULL;
    head -> data = 'h';
    head -> next = NULL;
    
    for (int i = 0; i < length; i++) {
        
        p = (ListNode *)malloc(sizeof(ListNode));
        p -> data = arc[i];
        //插入元素时，首先将插入位置后的链表链接到新结点上
        p -> next = head -> next;
        //将新节点插在头结点之后的位置
        head -> next = p;
    }
    return head;
}

linkList createLinkListRear(char *arc, int length){
    
    linkList head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p = NULL;
    head -> data = 'h';
    head -> next = NULL;
    
    //尾指针初始化指向头指针
    linkList temp = head;
    for (int i = 0; i < length; i++) {
        
        p = (ListNode *)malloc(sizeof(ListNode));
        p -> data = arc[i];
        //插入元素时，首先将插入位置后的链表链接到新结点上
        p -> next = NULL;
        //将新节点插在尾部
        temp -> next = p;
        temp = p;
    }
    
    if (temp != NULL) {
        
        temp -> next = NULL;
    }
    return head;
}

linkList getNode(linkList head, int i){
    
    //head为带头结点的单链表的头指针，i为要查找的序号
    linkList p = head -> next;
    int j = 1;
    while (p != NULL && j < i) {
        
        p = p -> next;
        ++j;
    }
    
    if (j == i) {
        return p;
    }
    return NULL;
}

linkList getNodeValue(linkList head, char value){
    
    linkList p = head -> next;
    while (p && p -> data != value) {
        
        p = p -> next;
    }
    return p;
}

linkList amendElement(linkList p, int amendLocation, char newElement){
    
    linkList temp = p;
    //遍历之前temp指向首元结点
    temp = temp -> next;
    //遍历到被修改结点
    for (int i = 0; i < amendLocation; i++) {
        
        temp = temp -> next;
    }
    temp -> data = newElement;
    return p;
}

linkList insertElement(linkList p, int insertLocation, char newElement){
    
    //创建temp结点
    linkList temp = p;
    for (int i = 0; i < insertLocation; i++) {
        
        if (temp == NULL) {
            
            printf("insert location error\n");
            return p;
        }
        temp = temp -> next;
    }
    
    linkList node = (linkList)malloc(sizeof(linkList));
    node -> data = newElement;
    node -> next = temp -> next;
    temp -> next = node;
    return p;
}

linkList deleteElement(linkList p, int deleteLocation){
    
    linkList temp = p;
    for (int i = 0; i < deleteLocation; i++) {
        temp = temp -> next;
    }

    linkList delNode = temp -> next;        //将被删除的结点
    temp -> next = delNode -> next;
    free(delNode);
    return p;
}

void printLinkList(ListNode *node){
    
    while (node) {
        
        printf("%c  ",node -> data);
        node = node -> next;
    }
    printf("\n");
}
