//
//  Search.h
//  DataStruct
//
//  Created by Jack on 2019/8/13.
//  Copyright © 2019 hu. All rights reserved.
//

#ifndef Search_h
#define Search_h

#include <stdio.h>

typedef struct _Node {
    
    int data;
    struct _Node *left;
    struct _Node *right;
    
} Node ;

typedef struct _LinkNode {
    
    int data;
    struct _LinkNode *next;
    
} LinkNode;


#endif /* Search_h */
