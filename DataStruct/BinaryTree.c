//
//  BinaryTree.c
//  DataStruct
//
//  Created by 胡勇 on 2018/6/24.
//  Copyright © 2018年 hu. All rights reserved.
//
/**
    # 遍历二叉树
    ### 递归思想遍历二叉树
    树是由根节点和子树部分构建而成，对一棵树来说，分三部分。左子树 右子树 根节点
    根据访问结点的时机不同，分三种遍历方式
    - 先访问根节点，在遍历左子树。 先序遍历
    - 先遍历左子树，然后访问根节点，在遍历右子树。 中序遍历
    - 遍历完左右子树，在访问根节点    后序遍历
*/


#include "BinaryTree.h"

void createBinaryTree(BTree tree){
    
    /**
             1
           2  0
         3  0
     */
    
    //创建二叉树
    tree = (BTree )malloc(sizeof(BTree));
    tree -> data = 1;
    tree -> leftChild = (BTree )malloc(sizeof(BTree));
    tree -> leftChild -> data = 2;
    tree -> leftChild -> leftChild = (BTree )malloc(sizeof(BTree));
    tree -> leftChild -> leftChild -> data = 3;
    tree -> leftChild -> leftChild -> leftChild = NULL;
    tree -> leftChild -> leftChild -> rightChild = NULL;
    tree -> leftChild -> rightChild = NULL;
    
    tree -> rightChild = NULL;
    
}
