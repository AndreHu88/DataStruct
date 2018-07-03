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
#include "Stack.h"

typedef int ElementType;

typedef struct BinaryTreeNode {
    
    ElementType data;      //数据域
    struct BinaryTreeNode *leftChild;       //左子树
    struct BinaryTreeNode *rightChild;      //右子树
} BinaryTree;

typedef BinaryTree *BTree;

//创建二叉树
void createBinaryTree(BTree *tree);
//输出节点的数值
void printTreeElement(BTree tree);
//先序遍历
void preOrderTraversal(BTree tree);
//中序遍历
void inOrderTraversal(BTree tree);
//后序遍历
void postOrderTraversal(BTree tree);

//先序遍历
void preOrderNotTraversal(BTree tree);
//中序遍历
void inOrderNotTraversal(BTree tree);
//后序遍历
void postOrderNotTraversal(BTree tree);

#endif /* BinaryTree_h */
