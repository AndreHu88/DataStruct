//
//  BinaryTree.c
//  DataStruct
//
//  Created by Jack on 2018/6/24.
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

int top = -1;       //表示栈顶元素所在的位置

void createBinaryTree(BTree *tree){
    
    /**
              1
           2    3
         4  5  6  7
     */
    
    //创建二叉树
    (*tree) = (BTree )malloc(sizeof(BTree));
    (*tree) -> data = 1;
    
    (*tree) -> leftChild = (BTree )malloc(sizeof(BTree));
    (*tree) -> rightChild = (BTree )malloc(sizeof(BTree));
    (*tree) -> leftChild -> data = 2;
    
    (*tree) -> leftChild -> leftChild = (BTree )malloc(sizeof(BTree));
    (*tree) -> leftChild -> rightChild = (BTree )malloc(sizeof(BTree));
    (*tree) -> rightChild -> leftChild  = (BTree )malloc(sizeof(BTree));
    (*tree) -> rightChild -> rightChild = (BTree )malloc(sizeof(BTree));

    (*tree) -> leftChild -> leftChild -> data = 4;
    (*tree) -> leftChild -> leftChild -> leftChild = NULL;
    (*tree) -> leftChild -> leftChild -> rightChild = NULL;
    
    (*tree) -> leftChild -> rightChild -> data = 5;
    (*tree) -> leftChild -> rightChild -> leftChild = NULL;
    (*tree) -> leftChild -> rightChild -> rightChild = NULL;
    
    (*tree) -> rightChild -> data = 3;
    
    (*tree) -> rightChild -> leftChild -> data = 6;
    (*tree) -> rightChild -> leftChild -> leftChild = NULL;
    (*tree) -> rightChild -> leftChild -> rightChild = NULL;
    
    (*tree) -> rightChild -> rightChild -> data = 7;
    (*tree) -> rightChild -> rightChild -> leftChild = NULL;
    (*tree) -> rightChild -> rightChild -> rightChild = NULL;
}

void printTreeElement(BTree tree){
    
    printf("%d\t",tree -> data);
}

//先序遍历
void preOrderTraversal(BTree tree){
    
    if (tree) {
        printTreeElement(tree);
        preOrderTraversal(tree -> leftChild);       //访问节点的左孩子
        preOrderTraversal(tree -> rightChild);      //访问节点的右孩子
    }
    return;
}

//中序遍历
void inOrderTraversal(BTree tree){
    
    if (tree) {
        inOrderTraversal(tree -> leftChild);    //遍历左子树
        printTreeElement(tree);
        inOrderTraversal(tree -> rightChild);   //遍历右子树
    }
    return;
}

//后序遍历
void postOrderTraversal(BTree tree){
    
    if (tree) {
        postOrderTraversal(tree -> leftChild);
        postOrderTraversal(tree -> rightChild);
        printTreeElement(tree);
    }
    return;
}


#pragma mark - 非递归方式遍历二叉树
void push(BinaryTree **stack, BinaryTree *elem){
    
    stack[++top] = elem;
}

void pop(){
    
    if (top == -1) {
        return;
    }
    top--;
}

BinaryTree* getTopElement(BinaryTree **stack){
    
    return stack[top];
}

//先序遍历
void preOrderNotTraversal(BTree tree){
    
    BinaryTree *stack[20];
    BinaryTree *temp;
    push(stack, tree);  //将根节点压栈
    while (top != -1) {
        
        temp = getTopElement(stack);  //取栈顶元素
        pop();                        //出栈
        while (temp) {
            printTreeElement(temp);
            //如果该节点有右子树，将右子树压栈
            if (temp -> rightChild) {
                push(stack, temp -> rightChild);
            }
            //先遍历左子树，直到左子树为NULL时，跳出while循环，然后遍历右子树
            temp = temp -> leftChild;
        }
    }
    
}

//中序遍历
void inOrderNotTraversal(BTree tree){
    
    BinaryTree *stack[20];
    BinaryTree *temp;
    push(stack, tree);
    //top不等于-1,说明栈内不为空
    while (top != -1) {
        
        while ((temp = getTopElement(stack)) && temp != NULL) {
            //将节点的左子树进栈
            push(stack, temp -> leftChild);
        }
        //跳出循环，将栈顶元素出栈
        pop();
        if (top != -1) {
            temp = getTopElement(stack);
            pop();
            printTreeElement(temp);
            //将节点的右孩子压栈
            push(stack, temp -> rightChild);
        }
    }
}

//后序遍历
void postOrderNotTraversal(BTree tree){
    
    BinaryTree *stack[20];
    BinaryTree *temp;
    push(stack, tree);
    //top不等于-1,说明栈内不为空
    while (top != -1) {
        
    }
}
