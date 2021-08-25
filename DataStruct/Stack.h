//
//  Stack.h
//  DataStruct
//
//  Created by Jack on 2018/6/10.
//  Copyright © 2018年 hu. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>

#define StackSize   10
typedef int ElementType;

//顺序栈
typedef struct stack {
    
    ElementType data[StackSize];
    int top;        //栈顶指针
} SeqStack;

//链式栈
typedef struct stackNode{
    
    char data;
    struct stackNode *next;
} StackNode;

typedef SeqStack *stackP;
typedef StackNode *linkStack;

void initStack(stackP stack);
int isEmptyStack(stackP stack);
int isFullStack(stackP stack);
void pushStack(stackP stack, char elem);
char popStack(stackP stack);
char getStackTop(stackP stack);

int isEmptyLinkStack(linkStack stack);
linkStack pushLinkStack(linkStack stack, char elem);
linkStack popLinkStack(linkStack stack);
char getLinkStackTop(linkStack stack);

#endif /* Stack_h */
