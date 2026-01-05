// Stack structure
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
void push(Stack *s , int x){
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
    if(isEmpty(s)){
        return -1;
    }
    return s->data[s->top];
}
int size(Stack *s){
    return s->top +1;
}
int main(){

    Stack s;
    init(&s);
    push(&s, 3);
    push(&s, 9);
    push(&s, 5);

    printf("size: %d\n", size(&s));
    printf("Top : %d\n", top(&s));
    printf("Pop: %d\n", pop(&s));
    printf("size: %d\n", size(&s));
    return 0;
}
//init 
//isEmpty
//isFull
//push
//pop
//top
//size

