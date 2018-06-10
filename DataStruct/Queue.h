//
//  Queue.h
//  DataStruct
//
//  Created by 胡勇 on 2018/6/10.
//  Copyright © 2018年 hu. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

#define QueueSize   100

typedef struct queue {
    
    char data[QueueSize];
    int front, rear;
} CircleQueue;

void initCircleQueue(CircleQueue *queue);
int isEmptyQueue(CircleQueue *queue);
int isFullQueue(CircleQueue *queue);
void enQueue(CircleQueue *queue, char elem);
char deQueue(CircleQueue *queue);
char getQueueFront(CircleQueue *queue);


#endif /* Queue_h */
