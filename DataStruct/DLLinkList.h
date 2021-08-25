//
//  DLLinkList.h
//  DataStruct
//
//  Created by Jack on 2018/6/10.
//  Copyright © 2018年 hu. All rights reserved.
//

#ifndef DLLinkList_h
#define DLLinkList_h

#include <stdio.h>
#include <stdlib.h>

//双向链表
typedef struct dlNode {
    
    char data;
    struct dlNode *next, *prior;        //分别有前驱指针和后继指针
} DLNode;

typedef DLNode *DLLinkList;

DLLinkList initDlLinkList(DLLinkList head);
DLLinkList insertDLLinkList(DLLinkList list, int insertLocation, char elem);
DLLinkList deleteDLLinkList(DLLinkList list, char elem);
void printDLLinkList(DLLinkList list);

#endif /* DLLinkList_h */
