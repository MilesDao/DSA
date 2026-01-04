#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

struct _List
{
    int size;
    int data[CAPACITY];
};
typedef struct _List List;

void init(List *l)
{
    l->size = 0;
}
// static Array-based Lists

int isEmpty(List *l)
{
    return l->size == 0;
}
int length(List *l)
{
    return l->size;
}
void display(List *l)
{
    for (int i = 0; i < length(l); i++)
    {
        printf("%d ", l->data[i]);
    }
}
void add(List *l, int index, int val)
{
    if (length(l) == CAPACITY)
        return;
    if (index < 0 || index > CAPACITY)
        return;

    for (int i = length(l); i >= index; i--)
    {
        l->data[i + 1] = l->data[i];
    }
    l->data[index] = val;
    l->size++;
}

void removed(List *l, int index)
{
    if (length(l) == CAPACITY)
        return;
    if (index < 0 || index > length(l))
        return;
    for (int i = index; i < length(l); i++)
    {
        l->data[i] = l->data[i + 1];
    }
    l->size--;
}
// Dynamic array Lists
typedef struct _listdynamic
{
    int size;
    int capacity;
    int *val;
} List_dynamic;

void init2(List_dynamic *l, int N)
{
    l->size = 0;
    l->capacity = N;
    l->val = (int *)malloc(sizeof(l->capacity));
}
int main()
{
    List l;
    init(&l);
    add(&l, 0, 8);
    add(&l, 1, 13);
    add(&l, 2, 2);
    add(&l, 3, 1);
    add(&l, 4, 30);
    add(&l, 5, 15);
    add(&l, 6, 91);
    add(&l, 7, 24);
    add(&l, 8, 7);
    add(&l, 9, 10);

    display(&l);
    add(&l, 4, 100);
    printf("\n");
    display(&l);

    removed(&l, 4);
    printf("\n");
    display(&l);
    return 0;
}