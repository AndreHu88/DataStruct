//
//  main.c
//  DataStruct
//
//  Created by 胡勇 on 2018/6/9.
//  Copyright © 2018年 hu. All rights reserved.
//


#include "LinkList.h"
#include "DLLinkList.h"
#include "Stack.h"
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    
    
    printf("Hello, World!\n");
    printf("单向链表操作\n");
    char arr[] = {'a','b','c','d','e'};
    ListNode *list = createLinkList(arr, 5);
    printLinkList(list);
    
    ListNode *listRear = createLinkListRear(arr, 5);
    printLinkList(listRear);
    
    printLinkList(insertElement(listRear, 5, 'f'));
    printLinkList(amendElement(listRear, 2, 'z'));
    printLinkList(deleteElement(listRear, 2));
    
    printf("双向链表\n");
    DLNode *head = NULL;
    head = initDlLinkList(head);
    printDLLinkList(head);
    printDLLinkList(insertDLLinkList(head, 6, 'f'));
    printDLLinkList(deleteDLLinkList(head, 'B'));
    
    printf("链式栈\n");
    linkStack stack = NULL;
    stack = pushLinkStack(stack, 'a');
    stack = pushLinkStack(stack, 'b');
    stack = pushLinkStack(stack, 'c');
    stack = pushLinkStack(stack, 'd');
    popLinkStack(stack);
    
    printf("二叉树\n");
    BTree binaryTree;
    createBinaryTree(&binaryTree);
    printf("\n先序遍历二叉树\n");
    preOrderTraversal(binaryTree);
    printf("\n中序遍历二叉树\n");
    inOrderTraversal(binaryTree);
    printf("\n后序遍历二叉树\n");
    postOrderTraversal(binaryTree);
    return 0;
}
