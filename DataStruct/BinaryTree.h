//
//  BinaryTree.h
//  DataStruct
//
//  Created by 胡勇 on 2018/6/24.
//  Copyright © 2018年 hu. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    
    int data;      //数据域
    struct BinaryTreeNode *leftChild;       //左子树
    struct BinaryTreeNode *rightChild;      //右子树
} BinaryTree;


typedef BinaryTree *BTree;
void createBinaryTree(BTree tree);


#endif /* BinaryTree_h */
