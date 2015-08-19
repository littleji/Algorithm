#pragma once
#ifndef list_array_h
#define list_array_h
#include<stdio.h>
#include<stdlib.h>
#define LENGTH 10
struct node {
    int data;
    int next;
};
typedef struct node Node;
typedef int PtrToNode;
typedef Node List[LENGTH];
void Error(const char *string){
    printf("%s\n", string);
    exit(-1);
}
void BuildList(List list){
    if(list == NULL)
        return ;
    int i = 0;
    for(i = 0; i<LENGTH;  ){
        list[i].next = ++i;
        list[i].data = 0;
    }
    list[LENGTH-1].next = 0;
    return ;
}
PtrToNode AllocNode(List list){
    if(list == NULL)
        Error("No avaliable list!");
    PtrToNode p = list[0].next;
    list[0].next = list[p].next;
    return p;
}
void FreeNode(List list,PtrToNode p){
    if(list == NULL)
        Error("No avaliable list!");
    list[p].next = list[0].next;
    list[0].next = p;
}
void ShowList(List list){
    if(list == NULL)
        Error("No avaliable list!");
    PtrToNode tmp = list[0].next;
    int i = 0;
    printf("num\t\tdata\t\tnext\t\t\n");
    for(;i<LENGTH;i++){
        printf("%d\t\t%d\t\t%d\t\t\n", i,list[i].data,list[i].next);
    }
}
void AddNode(List list, int data){
    if(list == NULL)
        Error("No avaliable list!");
    PtrToNode p = AllocNode(list);
    if(p == 0)
        Error("Out of space!");
    list[p].data = data;
}
int IsEmpty(List list){
    if(list == NULL)
        Error("No avaliable list!");
    return list[0].next == 0;
}
void RemoveNode(List list, PtrToNode p){
    list[p].data = 0;
    FreeNode(list, p);
}
#endif

