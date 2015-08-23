#pragma once
#ifndef stack_array_h
#define stack_array_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10
#define MIN_SIZE 3
#define ElementType int
struct StackStruct{
    int capacity;
    int top;
    ElementType *array;
};
typedef struct StackStruct* Stack;

void Error(const char * string){
    printf("%s\n", string);
    exit(-1);
}

Stack BuildStack(int size){
    if (size < MIN_SIZE || size > MAX_SIZE) {
        Error("the size of the Stack wrong!");            
    }
    Stack stack = NULL;
    stack = malloc(sizeof(struct StackStruct));
    if (stack == NULL) {
        Error("cant alloc stack!");
    }
    stack->capacity = size;
    stack->top = -1;
    stack->array = malloc(sizeof(ElementType)*size);
    if (stack->array == NULL) {
        Error("cant alloc stack->array");
    }
    return stack;
}
void DestroyStack(Stack stack){
    if (stack == NULL) {
        Error("the stack not exits!");
    }
    free(stack->array);
    free(stack);
    stack = NULL;
    printf("stack was freed\n");
}

int IsEmpty(Stack stack){
    return stack->top==-1;
}
int IsFull(Stack stack){
    return (stack->top) == (stack->capacity-1);
}
ElementType Pop(Stack stack){
    if(stack == NULL )
        Error("the stack not exits");
    if (IsEmpty(stack)){
        printf("the stack is full!\n");
        Error("thereis nothing to pop!");
    }
    return stack->array[stack->top--];
}
void Push(Stack stack, ElementType node){
    if(stack == NULL  )
        Error("the stack not exits");
    if(IsFull(stack)){
        printf("the stack is full!\n");
        return ;
    }
    stack->array[++stack->top] = node;
    return ;
}
void ShowStack(Stack stack){
    if(stack == NULL  )
        Error("the stack not exits");
    if (IsEmpty(stack)) {
        return ;
    }
    int i = 0;
    for(;i<stack->top+1;i++){// dont forget the array[0]
        printf("%d\n", stack->array[i]);
    }
}
#endif


