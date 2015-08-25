#pragma once
#ifndef queue_array_h
#define queue_array_h
#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MAX_SIZE 10
#define MIN_SIZE 2
#define true 1
#define false 0
#define QUEUE_FRONT 0
#define QUEUE_REAR 1
struct queue{
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *array;
};
typedef struct queue* Queue;
void Error(const char* string){
    printf("%s\n", string);
    exit(-1);
}
Queue BuildQueue(int capacity){
    if (capacity > MAX_SIZE || capacity < MIN_SIZE) {
        Error("the capacity out of range!");
    }
    Queue queue = malloc(sizeof(struct queue));
    if (queue == NULL) {
        Error("cant alloc the queue");
    }
    queue->capacity = capacity;
    queue->front=1;
    queue->rear=0;
    queue->size=0;
    queue->array= malloc(capacity*sizeof(ElementType));
    if (queue->array == NULL) {
        Error("cant alloc the queue");
    }
    return queue;
}
void DestroyQueue(Queue queue){
    if(queue == NULL)
        Error("queue not exits");
    free(queue->array);
    queue->array = NULL;
    free(queue);
    queue = NULL;
}
int IsEmpty(Queue queue){
    if(queue == NULL)
        Error("queue not exits");
    return queue->size == 0;
}
int IsFull(Queue queue){
    if(queue == NULL)
        Error("queue not exits");
    return queue->size == queue->capacity; 
}
int SetPointer(Queue queue, int WHICH){
   if (queue == NULL) {
       Error("queue not exits");
   } 
   else {
       switch (WHICH) {
           case QUEUE_REAR:
               if(queue->rear == queue->capacity -1)
                   queue->rear = 0;
               else
                   ++queue->rear;
               return queue->rear;
               break;
           case QUEUE_FRONT:
               if(queue->front == queue->capacity -1)
                   queue->front = 0;
               else
                   ++queue->front;
               return queue->front;
               break;
       }
   } 
}
void Enqueue(Queue queue, ElementType element){
    if (queue == NULL) 
        Error("queue not exits");
    if ( IsFull(queue))
        Error("queue is full");
    queue->array[SetPointer(queue,QUEUE_REAR)]= element; 
    queue->size++;
}
ElementType Dequeue(Queue queue){
    if (queue == NULL) 
        Error("queue not exits!");
    if(IsEmpty(queue))
        Error("nothing to dequeue!");
    ElementType tmp ;
    tmp = queue->array[queue->front];
    SetPointer(queue,QUEUE_FRONT); 
    queue->size--;
    return tmp;
}
void ShowQueue(Queue queue){
    if (queue == NULL) 
        Error("queue not exits");
    if(IsEmpty(queue)){
        printf("nothing to show\n");
        return;
    }
    int i = 0;
    //int front = queue->front;
    //int rear= queue->rear;
    printf("the front is %d\nthe rear is %d\n",queue->front, queue->rear );
    if(queue->rear < queue->front){
        for(i = queue->front; i < queue->capacity;i++)
           printf("%d \n", queue->array[i]); 
        for(i = 0; i < queue->rear + 1;i++)
           printf("%d \n", queue->array[i]); 
    }
    else{
        for (i = queue->front; i < queue->rear + 1 ;i++ ) {
           printf("%d \n", queue->array[i]); 
        } 
        return;
    }
}
#endif
