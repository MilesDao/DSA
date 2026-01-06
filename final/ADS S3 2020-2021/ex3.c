/*Question 3: (4 pts)
 Write a program to solve the Problem using Linked List ADT with necessary functions
and Linked List principle. (4 pts)
Note: Each element in the array is presented as a node in the Linked List data structure.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *pnext;
} Node;

typedef struct
{
    int size;
    Node *pHead;
} List;

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
void insertFirst(List *l, Node *pnew)
{
    pnew->pnext = l->pHead;
    l->pHead = pnew;
    l->size++;
}
void insert(List *l, Node *ptr, Node *pnew)
{
    pnew->pnext = ptr->pnext;
    ptr->pnext = pnew;
    l->size++;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void display(List *l)
{
    Node *p = l->pHead;
    while (p != NULL)
    {
        Node *q = p->pnext;
        while (q != NULL)
        {
            if (gcd(p->data, q->data) == 1)
            {
                printf("(%d, %d); ", p->data, q->data);
            }
            q = q->pnext;
        }
        p = p->pnext;
    }
}

int main()
{
    List l;
    init(&l);
    Node *n1 = initNode(2);
    Node *n2 = initNode(10);
    Node *n3 = initNode(27);
    Node *n4 = initNode(13);
    Node *n5 = initNode(90);
    Node *n6 = initNode(45);
    Node *n7 = initNode(5);
    Node *n8 = initNode(26);
    Node *n9 = initNode(49);
    Node *n10 = initNode(50);

    insertFirst(&l, n1);
    insert(&l, n1, n2);
    insert(&l, n2, n3);
    insert(&l, n3, n4);
    insert(&l, n4, n5);
    insert(&l, n5, n6);
    insert(&l, n6, n7);
    insert(&l, n7, n8);
    insert(&l, n8, n9);
    insert(&l, n9, n10);
    display(&l);
    return 0;
}