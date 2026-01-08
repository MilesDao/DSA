/*
Question 2: (4 pts)
A MinStack is a specialized stack data structure that, in addition to the standard stack operations,
can also return the minimum element currently stored in the stack, all in constant time, O(1).
Your task is to propose a MinStack data structure that supports the following operations:
1. push(x): Insert an element x onto the top of the stack
2. pop(): Remove the element at the top of the stack.
3. top(): Return the current top element of the stack without removing it.
4. getMin(): Return the minimum element in the stack at the current moment.
Note: This function must have a complexity of O(1). DO NOT propose an
algorithm with loops, scan the stack, or use additional libraries.
Hint: pop() removes only the top element, which is not always the minimum.
However, if the popped element is the minimum, the data structure must correctly
update and reveal the new minimum.
Your tasks are:
* Propose a data structure that supports all four operations in O(1) time. (1 pt)
. Explain the process in each function (2 pts).
. Justify the complexity of the proposed functions (1 pt).
Note: A complete implementation in C is not required, pseudo-code is preferable.*/

#include <stdio.h>
#define MAX 100
typedef struct
{
    int data[MAX];
    int top;
} Stack;
typedef struct
{
    int data[MAX];
    int top;
} Min;

void init(Stack *st)
{
    st->top = -1;
}
void initMin(Min *st)
{
    st->top = -1;
}
int isEmpty(Stack *st)
{
    return st->top == -1;
}
void push(Stack *st, Min *m, int val)
{
    if (st->top == MAX - 1)
    {
        return;
    }
    st->data[++st->top] = val;
    if (m->top == -1)
        m->data[++m->top] = val;
    if (st->data[st->top] < m->data[m->top])
    {
        m->data[++m->top] = st->data[st->top];
    }
}
int pop(Min *m)
{
    if (m->top == -1)
        return -1;
    return m->data[m->top--];
}

int main()
{
    Stack st;
    Min m;
    initMin(&m);
    init(&st);
    push(&st, &m, 6);
    push(&st, &m, 2);
    push(&st, &m, 0);
    push(&st, &m, 7);
    push(&st, &m, 1);
    push(&st, &m, 4);

    printf("Min = %d", pop(&m));
    return 0;
}