/*
Write the program to solve Problem 1 using Linked List ADT with necessary functions and
Linked List principle. (8 pts)
Note:
The size of stack is a constant (size = 3) and to use Stack ADT, there should be three steps:
- Step 1: Find and push every prime numbers that constitute a specific sphenic number in the
stack
***
- Step 2: Pop out all numbers found in the stack and calculate the product of these 3 prime
numbers
- Step 3: Display the result in the stack.
 Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify your
answer. (2 pts)*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef struct Stack
{
    int size;
    Node *pTop;
} Stack;
void init(Stack *st)
{
    st->size = 0;
    st->pTop = NULL;
}

int isEmpty(Stack *st)
{
    return st->size == 0;
}

void push(Stack *st, int val)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (tmp == NULL)
        return;

    tmp->next = st->pTop;
    tmp->data = val;
    st->pTop = tmp;
    st->size++;
} // O(1)
int pop(Stack *st)
{
    Node *p = st->pTop;
    if (isEmpty(st))
        return 0;
    int val = p->data;
    st->pTop = p->next;
    st->size--;
    free(p);
    return val;
}
// O(1)

int isSphenic(Stack *st, int n)
{
    int cnt = 0;
    int lastFactor = -1;
    for (int i = 2; i * i <= n; i++) // O(sqrt(n))
    {
        if (n % i == 0)
        {
            n /= i;
            cnt++;
            if (n % i == 0)
            {
                return 0;
            }
            lastFactor = i;
            push(st, i);
        }
    }
    if (n > 1 && lastFactor != n)
    {
        cnt++;
        push(st, n);
    }

    return cnt == 3;
}

void calculation(Stack *st)
{

    if (st->size != 3)
        return;
    int mul = 1;
    while (!isEmpty(st))
    {
        mul *= pop(st);
    }
    push(st, mul);
}
void display(Stack *st)
{
    Node *p = st->pTop;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Stack st;
    init(&st);

    if (isSphenic(&st, 66))
    {
        display(&st);
        calculation(&st);
        printf("Sphenic number = ");
        display(&st);
    }
    else
    {
        printf("Not a sphenic number\n");
    }
    return 0;
} // O(sqrt(n))