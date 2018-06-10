//
//  Queue.c
//  DataStruct
//
//  Created by 胡勇 on 2018/6/10.
//  Copyright © 2018年 hu. All rights reserved.
//

#include "Queue.h"

void initCircleQueue(CircleQueue *queue){
    
    queue -> front = queue -> rear = 0;
}

int isEmptyQueue(CircleQueue *queue){
    
    return queue -> front == queue -> rear;
}

int isFullQueue(CircleQueue *queue){
    
    return (queue -> rear + 1) % QueueSize == queue -> front;
}

void enQueue(CircleQueue *queue, char elem){
    
    if (isFullQueue(queue)) {
        printf("queue overFlow\n");
    }
    else{
        
        queue -> data[queue -> rear] = elem;
        queue -> rear = (queue -> rear + 1) % QueueSize;    //循环的意义下+1
    }

}

char deQueue(CircleQueue *queue){
    
    char data;
    if (isEmptyQueue(queue)) {
        printf("queue is empty\n");
        return ' ';
    }
    else{
        data = queue -> data[queue -> front];
        //头指针+1
        queue -> front = (queue -> front + 1) % QueueSize;
        return data;
    }
}

char getQueueFront(CircleQueue *queue){
    
    if (isEmptyQueue(queue)) {
        printf("queue is empty\n");
        return ' ';
    }
    else{
        return queue -> data[queue -> front];
    }
}
