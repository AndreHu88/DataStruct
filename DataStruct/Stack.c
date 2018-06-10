//
//  Stack.c
//  DataStruct
//
//  Created by 胡勇 on 2018/6/10.
//  Copyright © 2018年 hu. All rights reserved.
//

#include "Stack.h"

#pragma mark - 顺序栈
void initStack(stackP stack){
    
    //初始化stack
    stack -> top = -1;
}

int isEmptyStack(stackP stack){
    
    return stack -> top == -1;
}

int isFullStack(stackP stack){
    
    return stack -> top == StackSize -1;
}

void pushStack(stackP stack, char elem){
    
    if (isFullStack(stack)) {
        printf("stack overfolw\n");
    }
    else{
        stack -> top += 1;
        stack -> data[stack -> top] = elem;
    }
}

char popStack(stackP stack){
    
    if (isEmptyStack(stack)) {
        printf("stack is empty\n");
        exit(0);
    }
    //返回栈顶元素减一
    return stack ->data[stack ->top - 1];
}

char getStackTop(stackP stack){
    
    if (isEmptyStack(stack)) {
        printf("stack is empty\n");
        exit(0);
    }
    return stack -> data[stack -> top];
}

#pragma mark - 链式栈
int isEmptyLinkStack(linkStack stack){
    
    return stack == NULL;
}

linkStack pushLinkStack(linkStack stack, char elem){
    
    linkStack p = (linkStack)malloc(sizeof(linkStack));
    p -> data = elem;
    p -> next = stack;      //将新节点插入栈顶
    stack = p;              //将栈指向新的栈顶
    return stack;
}

linkStack popLinkStack(linkStack stack){
    
    if (isEmptyLinkStack(stack)) {
        printf("stack is empty\n");
        return NULL;
    }
    
    linkStack p = stack;
    stack = stack -> next;
    printf("退栈元素:%c\n",p -> data);
    if (stack) {
        printf("栈顶元素:%c\n",stack->data);
    }
    else{
        printf("栈已空");
    }
    free(p);
    return stack;
}

char getLinkStackTop(linkStack stack);
