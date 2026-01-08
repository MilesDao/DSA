
/*

Exercise 1: Suppose that we use a List data structure to represent unbounded
integers.
❼ the first element refers to the sign: 1 is positive and -1 is negative.
❼ each element in the list represents one digit of these integers.
Implement and test the program in C/C++ using an Array-based List (Static or
Dynamic) to manage this unbounded integers:
❼ add new digits at any place in an integer.
❼ remove a digit at a specfic position in an integer.
❼ calculate the sum of all digits from an unbounded integer.
❼ display the whole number on the screen.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct
{
    int data[MAX];
    int size;

} List;

void init(List *l)
{
    l->size = 0;
}

void add(List *l, int val)
{
    if (l->size == MAX)
        return;
    l->data[l->size++] = val;
}

void removes(List *l, int index)
{

    if (l->size == 0)
        return;
    for (int i = index; i < l->size; i++)
    {
        l->data[i] = l->data[i + 1];
    }
    l->size--;
}
int sumElement(List *l)
{
    int sum = 0;
    for (int i = 1; i < l->size; i++)
    {
        sum += l->data[i];
    }
    return sum;
}
void display(List *l)
{
    if (l->data[0] == -1)
    {
        printf("-");
        for (int i = 1; i < l->size; i++)
        {
            printf("%d", l->data[i]);
        }
    }
    else
    {
        for (int i = 1; i < l->size; i++)
        {
            printf("%d", l->data[i]);
        }
    }
}
int main()
{
    List l;
    init(&l);
    add(&l, 1);
    add(&l, 1);
    add(&l, 2);
    add(&l, 3);
    add(&l, 4);
    display(&l);
    printf("\n");
    removes(&l, 2);
    display(&l);
    printf("\n");
    printf("sum all element = %d", sumElement(&l));
    return 0;
}