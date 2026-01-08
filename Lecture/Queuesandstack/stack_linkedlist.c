#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
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
}
void pop(Stack *st)
{
    Node *p = st->pTop;
    if (isEmpty(st))
        return;

    st->pTop = p->next;
    st->size--;
    free(p);
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
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    display(&st);

    pop(&st);
    display(&st);
    return 0;
}