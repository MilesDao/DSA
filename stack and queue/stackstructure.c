// //stack operation
// - check if a stack is empty
// - check if a stack has maximum capacity
// - peek at top stack item 
// - create and destroy strack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct{
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *createStack(int capcacity){
    if (capcacity<=0) return NULL;
    
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack -> collection = (int*)malloc(sizeof(int) * capcacity);
    if(stack -> collection == NULL) {
        free(stack);
        return NULL;
    }
    stack ->capacity = capcacity;
    stack ->size = 0;

    return stack;
}

void destroyStack(Stack *stack){
    free(stack ->collection);
    free(stack);
}

int is_full(Stack *stack){
    if(stack->capacity == stack ->size) return 1;
    return 0;
}
int is_empty(Stack *stack){
    if(stack->size == 0) return 1;
    return 0;
}
bool push(Stack *stack, int item){
    if(is_full(stack)) return false;
    stack ->collection[stack ->size] = item;
    stack->size++;
    return true;
}

bool peek(Stack *stack,int *item){
    if( is_empty(stack)) return false;
    *item = stack->collection[stack->size -1];
    return true;
}   
bool pop(Stack *stack , int *item){
    if( is_empty(stack )) return false;
    stack->size --;// pointer 
    *item = stack->collection[stack ->size];// thay doi tu phan nay
    return true;
}
int main(){
    Stack *stack= createStack(5);
    if(stack == NULL) printf("Error create stack\n");
    if(is_empty(stack)){
        printf("stack is empty\n");
    }

    printf("===============================\n");
    push(stack, 2);
    printf("Stack size: %d\n", stack->size);
    push(stack , 7);
    push(stack , 9);
    push(stack , 10);
    push(stack, 5);
    if(is_full(stack)) printf("stack is full\n");
    printf("Stack size: %d\n", stack->size);
    push(stack, 3);
    printf("Stack size: %d\n", stack->size);   
    int peekval=0;
    peek(stack,&peekval);
    printf("peekval: %d\n", peekval);
    printf("===============================\n");
    int popval = 0;
    pop(stack , &popval);
    printf("pop value: %d\n", popval);
    printf("Stack size: %d\n", stack->size); 
    return 0;


}
