#include <stdio.h>
typedef struct
{
    int data[100];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, Stack *minst, int x)
{
    if (s->top == 100 - 1)
    {
        return;
    }
    s->data[++s->top] = x;

    if (minst->top == -1 || x <= minst->data[minst->top])
    {
        minst->data[++minst->top] = x;
    }
}
int pop(Stack *s, Stack *minst)
{
    if (s->top == -1)
    {
        return -1;
    }
    int x = s->data[s->top--];
    if (x == minst->data[minst->top])
    {
        minst->top--;
    };
    return x;
}

int top(Stack *s)
{
    return s->data[s->top];
}
int getMin(Stack *minst)
{
    if (minst->top == -1)
        return -1;
    return minst->data[minst->top];
}
int main()
{
    Stack S, MinS;

    init(&S);
    init(&MinS);

    push(&S, &MinS, 5);
    push(&S, &MinS, 3);
    push(&S, &MinS, 7);
    push(&S, &MinS, 2);

    printf("Top: %d\n", top(&S));       // 2
    printf("Min: %d\n", getMin(&MinS)); // 2

    pop(&S, &MinS);                               // pop 2
    printf("Min after pop: %d\n", getMin(&MinS)); // 3

    pop(&S, &MinS);                               // pop 7
    printf("Min after pop: %d\n", getMin(&MinS)); // 3

    pop(&S, &MinS);                               // pop 3
    printf("Min after pop: %d\n", getMin(&MinS)); // 5

    return 0;
}
