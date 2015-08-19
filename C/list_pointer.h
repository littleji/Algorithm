#ifndef list_h
#define list_h
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node Node;
typedef struct node* PtrToNode;
typedef PtrToNode List;
List BuildList(){
    List list=NULL;
    list = malloc(sizeof(Node));
    if(list == NULL)
        return NULL;
    list->data=0;
    list->next=NULL;
    return list;
}
PtrToNode BuildNode(int data){
    PtrToNode newnode=malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void AddNode(List list, PtrToNode node){
    if (list ==NULL || node == NULL) {
        return;
    }
    List tmp=NULL;
    tmp = list;
    while (tmp->next!=NULL) {
        tmp=tmp->next;
    }
    tmp->next=node;
    node->next=NULL;
}
int ListEmpty(List list){
    return list->next==NULL;
}
int IsLast(PtrToNode p){
    return p->next==NULL;
}
PtrToNode FindNode(List list, int to_find){
    if(list == NULL)
        return;
    List tmp=list->next;
    while(tmp!=NULL && tmp->data!=to_find){
        tmp=tmp->next;
    }
    return (tmp==NULL)?NULL:tmp;

}
PtrToNode FindPreciousNode(List list ,int to_find ){
    if(list == NULL)
        return NULL;
    List tmp=list->next;
    PtrToNode pre=NULL;
    while(tmp!= NULL && tmp->data != to_find){
        pre=tmp;
        tmp=tmp->next;
    }
    return (tmp==NULL)?NULL:pre;
}
void DeleteNode(List list, int to_find){
    if(list == NULL)
        return;
    PtrToNode tmp = FindPreciousNode(list, to_find);
    PtrToNode del = NULL;
    if (tmp != NULL) {
        del = tmp->next;
        tmp->next = del->next;
        free(del);
        del=NULL;
    }
}
void ShowAll(List list){
    if(list ==NULL)
        return;
    List tmp=NULL;
    tmp = list->next;
    while(tmp!=NULL){
        printf(" %d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void DeleteList(List list){
    if(list ==NULL)
        return;
    List tmp=list;
    while(list->next!=NULL){
        list = list->next;
        free(tmp);
        tmp=list;
    }
    free(list);
    list=NULL;
}
void InsertNode(List list, PtrToNode node, int data){
    if (list == NULL || node == NULL) {
        return;
    }
    PtrToNode tmp=FindNode(list, data);
    if(tmp==NULL)
        return;
    else {
        node->next=tmp->next;
        tmp->next = node;
    }

}
#endif
