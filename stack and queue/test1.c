#include<stdio.h>
#include<stdlib.h>


#define capacity 100


typedef struct{
    int data[capacity];
    int top;
} Stack;

void init(Stack *st){
    st->top = -1;
}
int isEmpty(Stack *st){
    return(st->top == -1);
}
int isFull(Stack *st){
    return st->top == capacity -1;
}


void push(Stack *st, int x){
    if(isFull(st)){
        printf("Stack overflow");
        return;
    }
    st->data[++st->top] = x;
}
int pop(Stack *st){
    if(isEmpty(st)){
        printf("Stack underflow");
        return -1;
    }
    return st->data[st->top--];

}
int top(Stack *st){
    if(isEmpty(st)) return -1;
    return st->data[st->top];
}

int size(Stack *st){
    return st->top +1;
}

int main() {
    Stack st;
    init(&st);

    printf("=== STACK TEST ===\n");

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);

    printf("Top element: %d\n", top(&st));
    printf("Size: %d\n", size(&st));

    int removed = pop(&st);
    printf("Popped: %d\n", removed);

    printf("New top: %d\n", top(&st));
    printf("New size: %d\n", size(&st));

    // Pop remaining
    pop(&st);
    pop(&st);
    
    // Try popping from empty stack
    pop(&st);

    return 0;
}