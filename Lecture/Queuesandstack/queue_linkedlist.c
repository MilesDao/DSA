#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef struct
{
    Node *pFront, *pBack;
    int size;
} Queue;

void init(Queue *q)
{
    q->size = 0;
    q->pFront = NULL;
    q->pBack = NULL;
}
int isEmpty(Queue *q)
{
    return q->pFront == NULL;
}

void enqueue(Queue *q, int val)
{
    Node *pnew = (Node *)malloc(sizeof(Node));
    pnew->data = val;
    pnew->next = NULL;
    if (q->pFront == NULL)
    {
        q->pFront = q->pBack = pnew;
    }
    else
    {
        q->pBack->next = pnew;
        q->pBack = pnew;
    }

    q->size++;
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
        return;

    Node *p = q->pFront;
    q->pFront = p->next;
    free(p);
    q->size--;

    if (q->pFront == NULL)
        q->pBack = NULL;
}

void display(Queue *q)
{
    Node *p = q->pFront;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Queue q;
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}