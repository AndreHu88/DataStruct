//
//  Tree.h
//  DataStruct
//
//  Created by Duntech on 2018/6/28.
//  Copyright © 2018年 hu. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>

typedef int ElementType;

typedef struct treeNode {
    
    ElementType data;
    struct treeNode *leftChild, *rightChild;
} BinaryTree;

typedef BinaryTree* Tree;

void createBinaryTree(Tree tree);
void printTreeElement(Tree tree);
//先序遍历
void preOrderTraversal(Tree tree);
//中序遍历
void inOrderTraversal(Tree tree);


#endif /* Tree_h */
