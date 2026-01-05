#include<stdio.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int top;
} Stack;
void init(Stack *s){
    s ->top = -1;
}

//push
int isEmpty(Stack *s){
    return s->top == -1;
}
int isFull(Stack *s){
    return s->top == MAX -1;
}
void push(Stack *s, int x){
    if(isFull(s)){
        printf("StackOverflow\n");
        return;
    }
    s->data[++s->top ] = x;
}
int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}
void display(Stack *s){
    for(int i = s->top; i>=0; i--){
        printf("%d", s->data[i]);
    }
}
int main(){
    Stack s;
    init(&s);

    int n = 8;

    while(n > 0){
        push(&s, n%2);
        n = n/2;
    }
    display(&s);
    printf("\n");

    return 0;
}
//pop
//display