//
//  Tree.c
//  DataStruct
//
//  Created by Duntech on 2018/6/28.
//  Copyright © 2018年 hu. All rights reserved.
//

#include "Tree.h"
#include <stdlib.h>


void createBinaryTree(Tree tree){
    
    tree = (Tree )malloc(sizeof(Tree));
    
}


void printTreeElement(Tree tree){
    
    printf("current tree data is: %d",tree -> data);
}

//先序遍历
void preOrderTraversal(Tree tree){
    
    if (tree) {
        printTreeElement(tree);
        preorderTraversal(tree -> leftChild);       //访问节点的左孩子
        preorderTraversal(tree -> rightChild);      //访问节点的右孩子
    }
    return;
}

//中序遍历
void inOrderTraversal(Tree tree){
    
    if (tree) {
        inOrderTraversal(tree -> leftChild);    //遍历左子树
        printTreeElement(tree);
        inOrderTraversal(tree -> rightChild);   //遍历右子树
    }
    return;
}

//后序遍历
void postOrderTraversal(Tree tree){
    
    if (tree) {
        postOrderTraversal(tree -> leftChild);
        postOrderTraversal(tree -> rightChild);
        printTreeElement(tree);
    }
    return;
}
