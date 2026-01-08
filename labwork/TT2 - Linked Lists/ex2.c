
/*
Exercise 2: Assume that a railway train has N railroad cars attached together
such as car1, car2, car3, ..., carN . A train can be considered as a list and each car
corresponds to a node in this list.
1
❼ Each car carries a maximum capacity of passengers (int type) and has an id
(char type). Both variables are user-defined values.
❼ Each car is reserved by a number of passengers (int type) (which should be
less than its capacity). If there are any cars that don’t have any passengers,
they should be removed from the train.
❼ It is possible to add new cars to the train.
❼ A function is available to display all cars’ information or the length of the
train.
Implement a program in C/C++ using Linked List to manage the train and test all
functions.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int capacity;
    int passengers;
    char id;
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
Node *initNode(int id, int capacity, int passengers)
{
    if (capacity < passengers)
    {
        printf("error");
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->id = id;
    tmp->capacity = capacity;
    tmp->passengers = passengers;
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

void remover(List *l)
{
    if (l->pHead == NULL) // kiem tra list rong
        return;

    Node *p = l->pHead;
    if (p->passengers == 0)
    {
        l->pHead = p->pnext;
        free(p);
        l->size--;
    }
    Node *q = p;
    p = p->pnext;
    while (p != NULL && p->passengers != 0)
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
        printf("capacity: %d, id: %c, passengers: %d \n", p->capacity, p->id, p->passengers);
        p = p->pnext;
    }
}
int main()
{
    List l;
    init(&l);
    Node *n1 = initNode('A', 50, 0);
    Node *n2 = initNode('B', 20, 10);
    Node *n3 = initNode('C', 80, 60);
    Node *n4 = initNode('D', 70, 0);

    insertFirst(n1, &l);
    insert(n2, n1, &l);
    insert(n3, n2, &l);
    insert(n4, n3, &l);
    printf("========================\n");
    printf("length: %d\n", length(&l));
    display(&l);

    printf("========================\n");
    remover(&l);
    printf("length: %d\n", length(&l));
    display(&l);
    printf("========================\n");
    Node *n5 = initNode('E', 100, 90);
    Node *n6 = initNode('F', 200, 100);
    insert(n5, n3, &l);
    insert(n6, n5, &l);
    printf("length: %d\n", length(&l));
    display(&l);
    printf("========================\n");

    remover(&l);
    printf("length: %d\n", length(&l));
    display(&l);
    return 0;
}
