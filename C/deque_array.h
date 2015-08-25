#pragma once 
#ifndef deque_array_h
#define deque_array_h
#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MAX_SIZE 10
#define MIN_SIZE 2
typedef struct s_deque* Deque; 
typedef enum which WHICH;
struct s_deque {
    int size;
    int capacity;
    int front;
    int rear;
    ElementType *array;
};
enum which{
    PUSH,
    POP,
    INJECT,
    EJECT
};

int SetPointer(Deque deque, WHICH which);
#endif
