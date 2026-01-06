#include <stdio.h>
#include <stdlib.h>
/*
Basic operations are often defined
1 init(): create an empty list
2 isEmpty(): check if the list is empty
3 insert(): add new item in a list
4 remove(): remove an item from a list*/
/*

Some other possible operations can be used:
1 length(): return the length of a list
2 search(): search a specific element in a list
3 display(): display a list
4 sort(): sort all items in a list*/

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

void display(List *l)
{
    Node *p = l->pHead;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->pnext;
    }
}

int main()
{
    List l;
    init(&l);

    Node *n1 = initNode(10);
    Node *n2 = initNode(20);
    Node *n3 = initNode(30);
    Node *n4 = initNode(40);

    insertFirst(n1, &l);
    insert(n2, n1, &l);
    insert(n3, n2, &l);
    insert(n4, n3, &l);

    printf("Danh sach ban dau:\n");
    display(&l);
    printf("Size = %d\n", length(&l));

    printf("Xoa node co gia tri 10 (head):\n");
    remover(&l, 10);
    display(&l);
    printf("Size = %d\n", length(&l));

    printf("Xoa node co gia tri 20:\n");
    remover(&l, 20);
    display(&l);
    printf("Size = %d\n\n", length(&l));
    return 0;
}
