/*
Question 3: (4 pts)
 Write a program to solve the Problem using Linked List ADT with necessary functions
and Linked List principle. (4 pts)
Note: Each element in the array is presented as a node in the Linked List data structure.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct _Node
{
    int data;
    struct _Node *pnext;
} Node;

typedef struct _List
{
    int size;
    Node *pHead;
} List;

// init and create Node

void init(List *l)
{
    l->size = 0;
    l->pHead = NULL;
}
Node *initNode(int val)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = val;
    tmp->pnext = NULL;
    return tmp;
}
int isEmpty(List *l)
{
    return l->size == 0;
}
int length(List *l)
{
    return l->size;
}
void insertFirst(Node *pnew, List *l)
{
    pnew->pnext = l->pHead;
    l->pHead = pnew;
    l->size++;
}
void insert(Node *pnew, Node *ptr, List *l)
{
    pnew->pnext = ptr->pnext;
    ptr->pnext = pnew;
    l->size++;
}

void remover(List *l, int val)
{
    if (l->pHead == NULL) // kiem tra list rong
        return;

    Node *p = l->pHead;
    if (p->data == val)
    {
        l->pHead = p->pnext;
        free(p);
        l->size--;
        return;
    }
    Node *q = p;
    p = p->pnext;
    while (p != NULL && p->data != val)
    {
        q = p;
        p = p->pnext;
    }
    if (p != NULL)
    {
        q->pnext = p->pnext;
        l->size--;
        free(p);
    }
}

int isPrime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int isSphenic(int n)
{

    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i) && n % i == 0)
        {
            int power = 0;
            while (n % i == 0)
            {
                n /= i;
                power++;
            }
            if (power > 1)
                return 0;
            cnt++;
        }
    }
    return cnt == 3;
}
void display(List *l)
{
    Node *p = l->pHead;
    while (p != NULL)
    {
        if (isSphenic(p->data))
            printf("%d ", p->data);
        p = p->pnext;
    }
}
int main()
{
    List l;
    init(&l);

    for (int i = 165; i >= 30; i--)
        insertFirst(initNode(i), &l);

    display(&l);
    return 0;
}
