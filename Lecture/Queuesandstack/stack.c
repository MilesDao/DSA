#include <stdio.h>
#define CAPACITY 100

struct _Stack
{
    int data[CAPACITY];
    int top;
};
typedef struct _Stack Stack;

void init(Stack *st)
{
    st->top = -1;
}

int isEmpty(Stack *st)
{
    return st->top == -1;
}
int isFull(Stack *st)
{
    return st->top == CAPACITY - 1;
}
int size(Stack *st)
{
    return st->top + 1;
}
void push(Stack *st, int val)
{
    if (isFull(st))
    {
        printf("Stack Overflow");
        return;
    }
    st->top++;
    st->data[st->top] = val;
}
void pop(Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack underflow");
        return;
    }
    st->top--;
}
void display(Stack *st)
{
    for (int i = 0; i < size(st); i++)
    {
        printf("%d ", st->data[i]);
    }
}
int main()
{
    Stack st;
    init(&st);
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);

    display(&st);
    printf("\n%d ", size(&st));
    printf("\n");
    pop(&st);
    display(&st);
    printf("\n%d ", size(&st));
    return 0;
}