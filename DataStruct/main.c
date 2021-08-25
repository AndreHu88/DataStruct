//
//  main.c
//  DataStruct
//
//  Created by Jack on 2018/6/9.
//  Copyright © 2018年 hu. All rights reserved.
//


#include "LinkList.h"
#include "DLLinkList.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Sort.h"

void testLinkList(void) {
    
    printf("单向链表操作\n");
    char arr[] = {'a','b','c','d','e'};
    ListNode *list = createLinkList(arr, 5);
    printLinkList(list);
    
    ListNode *listRear = createLinkListRear(arr, 5);
    printLinkList(listRear);
    
    printLinkList(insertElement(listRear, 5, 'f'));
    printLinkList(amendElement(listRear, 2, 'z'));
    printLinkList(deleteElement(listRear, 2));
}

void testDoubleLinkList(void) {
    
    printf("双向链表\n");
    DLNode *head = NULL;
    head = initDlLinkList(head);
    printDLLinkList(head);
    printDLLinkList(insertDLLinkList(head, 6, 'f'));
    printDLLinkList(deleteDLLinkList(head, 'B'));
}

void testLinkStack(void) {
    
    printf("链式栈\n");
    linkStack stack = NULL;
    stack = pushLinkStack(stack, 'a');
    stack = pushLinkStack(stack, 'b');
    stack = pushLinkStack(stack, 'c');
    stack = pushLinkStack(stack, 'd');
    popLinkStack(stack);
}

void testBinaryTree(void) {
    
    printf("二叉树\n");
    BTree binaryTree;
    createBinaryTree(&binaryTree);
    printf("\n先序遍历二叉树\n");
    preOrderTraversal(binaryTree);
    printf("\n中序遍历二叉树\n");
    inOrderTraversal(binaryTree);
    printf("\n后序遍历二叉树\n");
    postOrderTraversal(binaryTree);
    
    printf("\n非递归先序遍历二叉树\n");
    preOrderNotTraversal(binaryTree);
    printf("\n非递归中序遍历二叉树\n");
    inOrderNotTraversal(binaryTree);
}

void testSort(void) {
    
    printf("\n快速排序算法\n");
    printf("排序前\n");
    int arr[6] = {32, 12,7, 78, 23, 45};
    int arrayLength = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrayLength; i++) {
        printf("%d\t", arr[i]);
    }
    
    quickSort(arr, 0, arrayLength - 1);
    printf("\n排序后\n");

    for (int i = 0; i < arrayLength; i++) {
        printf("%d\t", arr[i]);
    }
    
}

int main(int argc, const char * argv[]) {
    
    
//    testLinkList();
//    testDoubleLinkList();
//    testLinkStack();
//    testBinaryTree();
    
  
    ///快速排序
    testSort();
    
    return 0;
}


