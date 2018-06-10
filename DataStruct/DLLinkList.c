//
//  DLLinkList.c
//  DataStruct
//
//  Created by 胡勇 on 2018/6/10.
//  Copyright © 2018年 hu. All rights reserved.
//

#include "DLLinkList.h"

DLLinkList initDlLinkList(DLLinkList head){
    
    head = (DLLinkList)malloc(sizeof(DLLinkList));
    head -> next = NULL;
    head -> prior = NULL;
    
    DLLinkList p, list = head;
    for (int i = 0; i < 5; i++) {
        
        p = (DLLinkList)malloc(sizeof(DLLinkList));
        p -> next = NULL;
        p -> prior = NULL;
        p -> data = 65 + i;
        
        list -> next = p;
        p -> prior = list;
        list = list -> next;
    }
    return head;
}

DLLinkList insertDLLinkList(DLLinkList list, int insertLocation, char elem){
    
    //创建结点
    DLLinkList temp = (DLLinkList)malloc(sizeof(DLLinkList));
    temp -> data = elem;
    temp -> next = NULL;
    temp -> prior = NULL;
    
    //插入到链表头要特殊考虑
    if (insertLocation == 1) {
       
        temp -> next = list;
        list -> prior = temp;
        list = temp;
    }
    else{
        
        DLLinkList body = list;
        for (int i = 0 ; i < insertLocation - 1; i++) {
           body = body -> next;
        }
        
        if (body -> next == NULL) {
            //插入链表尾部
            body -> next = temp;
            temp -> prior = body;
        }
        else{
            
            body -> next -> prior = temp;
            temp -> next = body -> next;
            body -> next = temp;
            temp -> prior = body;
        }
    }
    return list;
}

DLLinkList deleteDLLinkList(DLLinkList list, char elem){
    
    DLLinkList temp = list;
    while (temp) {
        
        if (temp -> data == elem) {
            //如果内容相同，删除结点
            temp -> prior -> next = temp -> next;
            temp -> next -> prior = temp -> prior;
            free(temp);
            return list;
        }
        temp = temp -> next;
    }
    return list;
}

void printDLLinkList(DLLinkList list){
    
    DLLinkList temp = list;
    while (temp) {
        
        if (temp -> next == NULL) {
            
            printf("%c\n",temp -> data);
        }
        else{
            
            printf("%c -> ",temp -> data);
        }
        temp = temp -> next;
    }
}
