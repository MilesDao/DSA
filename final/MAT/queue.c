#include<stdio.h>
#define MAX 100

typedef struct{
    int data[MAX];
    int top;
} Stack;

void init(Stack *s){
    s->top = -1;
}
int isEmpty(Stack *s){
    return (s->top == -1);
}
int isFull(Stack *s){
    return (s->top == MAX -1);
}
void push(Stack *s, int x){
    if(isFull(s)){
        printf("Stack overflow\n");
        return;
    }
    s->data[++s->top] = x;
}
int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[s->top--];
}
int top(Stack *s){
    if(isEmpty(s)) return -1;
    return s->data[s->top];
}
int size(Stack *s){
    return s->top +1;
}
int main(){
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    int removed = pop(&s);
    printf("Popped: %d\n", removed);

    printf("New top: %d\n", top(&s));
    printf("New size: %d\n", size(&s));

    // Pop remaining
    pop(&s);
    pop(&s);
    
    // Try popping from empty stack
    pop(&s);

    return 0;
}
//init
//isEmpty
//isFull
//push
//pop
//top
//size