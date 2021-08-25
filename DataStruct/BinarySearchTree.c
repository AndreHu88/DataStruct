//
//  BinarySearchTree.c
//  DataStruct
//
//  Created by Jack on 2021/8/25.
//  Copyright © 2021 hu. All rights reserved.
//

#include "BinarySearchTree.h"

///二叉查找树  查找过程
BinaryTree *searchBinaryTree(myType x, BinaryTree *tree) {
    
    if (tree ==  NULL) {
        return NULL;
    }
    
    if (x < tree -> data) {
        ///小于节点，去左节点查找
        searchBinaryTree(x, tree -> leftChild);
    }
    else if (x > tree -> data) {
        ///大于节点，去右节点查找
        searchBinaryTree(x, tree -> rightChild);
    }
    
    return tree;
}

///二叉查找树 查找最小值
BinaryTree *searchMin(BinaryTree *tree) {
    
    ///遍历左子树 就可以取到最小值
    if (tree ==  NULL) {
        return NULL;
    }
    else if (tree -> leftChild == NULL) {
        return tree;
    }
    else {
        return searchMin(tree);
    }
}

///二叉查找树 查找最大值
BinaryTree *searchMax(BinaryTree *tree) {
    
    ///遍历右子树 就可以取到最大值
    if (tree == NULL) {
        return NULL;
    }
    else if (tree -> rightChild == NULL) {
        return tree;
    }
    else {
        return searchMax(tree);
    }
}

///二叉查找树 插入  根据二叉查找树的性质，如果大于根节点元素，进入右子树，如果小于根节点元素则进入左子树。
BinaryTree *insertElement(BinaryTree *tree, myType element) {
    
    if (tree == NULL) {
        tree = malloc(sizeof(BinaryTree));
        tree -> data = element;
        tree -> leftChild = NULL;
        tree -> rightChild = NULL;
    }
    else if (element > tree -> data) {
        
        insertElement(tree -> rightChild, element);
    }
    else if (element < tree -> data) {
        insertElement(tree -> leftChild, element);
    }
    
    return tree;
}

