#include "deque.h"
void Error(const char* string){
    printf("%s\n", string);
    exit(-1);
}

Deque BuildDeque(int capacity){
   if (capacity > MAX_SIZE || capacity < MIN_SIZE) {
      Error("the capacity out of range!"); 
   } else {
      Deque deque = malloc(sizeof(struct s_deque));
      if (deque == NULL) {
          Error("can't alloc mem for deque!");
      } else {
          deque->capacity = capacity;
          deque->array = malloc(capacity*sizeof(ElementType));
          deque->size = 0;
          deque->rear = 0;
          deque->front = 1;
      }
   } 
}

void DestroyDeque(Deque deque){
    if (deque == NULL) {
        Error("deque not exits");
    } else {
        free(deque->array);
        free(deque);
        deque = NULL;
    }
}

int IsEmpty(Deque deque){
    if(deque == NULL)
        Error("the deque not exits!");
    return deque->size == 0;
}

int IsFull(Deque deque){
    if(deque == NULL)
        Error("the deque not exits!");
    return deque->size == deque->capacity;
}
int SetPointer(Deque deque, WHICH which){
    if(deque == NULL)
        Error("the deque not exits!");
    switch (which) {
        case PUSH://Push is to add element at the begin of the deque
                 if (deque->front == 0) {
                     deque->front = deque->capacity - 1;
                 } else {
                    deque->front--; 
                 }
                 return deque->front;
                     break;
        case POP://POP is to remove element at the begin of the deque
                 if (deque->front == deque->capacity - 1) {
                     deque->front = 0;
                 } else {
                    deque->front++;
                 }
                 return deque->front;
                     break;
        case INJECT://INJECT is to add element at the end of the deque
                 if (deque->rear == deque->capacity - 1) {
                     deque->rear = 0;
                 } else {
                    deque->rear++;
                 }
                 return deque->rear;
                     break;
        case EJECT://EJECT is to remove element at the end of the deque 
                 if (deque->rear == 0) {
                     deque->front = deque->capacity - 1;
                 } else {
                    deque->rear--; 
                 }
                 return deque->rear;
                     break;
    }
}

void Push(Deque deque, ElementType element){
    if(deque == NULL)
        Error("the deque not exits!");
    if(IsFull(deque))
        Error("the deque is full!");
    SetPointer(deque, PUSH);
    deque->array[deque->front] = element;
    deque->size++;
}
ElementType Pop(Deque deque){
    if(deque == NULL)
        Error("the deque not exits!");
    if(IsEmpty(deque))
        Error("the deque is empty!");
    ElementType tmp = deque->front;
    SetPointer(deque, POP);
    deque->size--;
    return tmp;
}
void Inject(Deque deque, ElementType element){
    if(deque == NULL)
        Error("the deque not exits!");
    if(IsFull(deque))
        Error("the deque is full!");
    SetPointer(deque, INJECT);
    deque->array[deque->rear] = element;
    deque->size++;
}

ElementType Eject(Deque deque){
    if(deque == NULL)
        Error("the deque not exits!");
    if(IsEmpty(deque))
        Error("the deque is empty!");
    ElementType tmp = deque->rear;
    SetPointer(deque, POP);
    deque->size--;
    return tmp;
}

void ShowDeque(Deque deque){
    if(deque == NULL)
        Error("the deque not exits!");
    if(IsEmpty(deque))
        Error("the deque is empty!");
    int i = 0;
    printf("the size is %d,the front is %d,the rear is %d\n", deque->size, deque->front, deque->rear);
    if(deque->rear < deque->front){
        for(i = deque->front; i < deque->capacity; i++){
            printf("%d \n", deque->array[i]);        
        }
        for(i = 0;i < deque->rear + 1;i++){
            printf("%d \n", deque->array[i]);        
        }
    }
    else {
        for(i = deque->front; i < deque->rear + 1; i++){
            printf("%d \n", deque->array[i]);        
        }
    }
}
int main(int argc, char const* argv[])
{
    Deque deque = NULL;
    deque = BuildDeque(5);
    Push(deque, 1); 
    Push(deque, 2); 
    Push(deque, 3); 
    Push(deque, 4); 
    Push(deque, 5); 
    Pop(deque);
    Pop(deque);
    Inject(deque, 5);
    ShowDeque(deque);
    DestroyDeque(deque);  
    return 0;
}
