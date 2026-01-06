#include <stdio.h>
#define CAPACITY 100
struct _Queue
{
    int front;
    int back;
    int data[CAPACITY];
};
typedef struct _Queue Queue;
void init(Queue *q)
{
    q->back = 0;
    q->front = 0;
}
int isEmpty(Queue *q)
{
    return q->back == 0;
}
int length(Queue *q)
{
    int l = q->back - q->front;
    return l;
}

int enqueue(Queue *q, int val)
{
    if (length(q) == CAPACITY)
    {
        printf("is Full");
        return 0;
    }
    if (isEmpty(q))
    {
        q->data[0] = val;
    }
    else
    {
        int idx = q->back;
        q->data[idx] = val;
    }
    q->back++;
    return 1;
}
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    if (length(q) > 1)
    {
        for (int i = 1; i < length(q); i++)
        {
            q->data[i - 1] = q->data[i];
        }
        q->back = q->back - 1;
        return 1;
    }
}
void display(Queue *q)
{
    for (int i = 0; i < length(q); i++)
    {
        printf("%d ", q->data[i]);
    }
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
    enqueue(&q, 6);
    printf("%d ", length(&q));
    printf("\n");
    display(&q);
    printf("\n");
    dequeue(&q);
    display(&q);
    printf("\n%d ", length(&q));
    return 0;
}