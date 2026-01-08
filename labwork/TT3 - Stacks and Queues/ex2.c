/*
Exercise 2:
In this problem, we try to implement the navigation system in a web browser to
back/forward a visiting website using a stack for Backward and another for Forward.
Choose one method to implement a Stack data structure (Array-based or Stack using
Linked List) to implement this problem.
❼ A website may contain a url and a title; suppose that we have visited a list of
websites.
❼ The order of visited websites is stored in a Backward stack according to FILO.
❼ If we return to the previous website, we pop the Backward stack and push it
into the Forward stack.
❼ And otherwise, when we forward to the next website, we retrieve the top
website from the Forward stack and push it into the Backward stack.
Write a main function for testing all written functions (init(), display(), push(),
pop(),...)*/

#include <stdio.h>
#define CAPACITY 100

typedef struct
{
    char url[100];
    char title[100];
} Website;
struct _Stack
{
    Website data[CAPACITY];
    int top;
};
typedef struct _Stack Stack;

void init(Stack *st)
{
    st->top = -1;
}

int isEmpty(Stack *st)
{
    return st->top == -1;
}
int isFull(Stack *st)
{
    return st->top == CAPACITY - 1;
}
int size(Stack *st)
{
    return st->top + 1;
}
void push(Stack *st, Website w)
{
    if (isFull(st))
    {
        printf("Stack Overflow");
        return;
    }
    st->top++;
    st->data[st->top] = w;
}
Website pop(Stack *st)
{
    Website empty = {"", ""};
    if (isEmpty(st))
    {
        printf("Stack underflow");
        return empty;
    }

    return st->data[st->top--];
}

void goBack(Stack *fo, Stack *back)
{
    if (back->top == -1)
        return;
    push(fo, pop(back));
}

void goForward(Stack *fo, Stack *back)
{
    if (fo->top == -1)
        return;
    push(back, fo->data[fo->top]);
}
void currentwebsite(Stack *st)
{
    printf("title: %s, url: %s\n", st->data[st->top].title, st->data[st->top].url);
}
int main()
{
    Stack Forward;
    Stack Backward;
    init(&Forward);
    init(&Backward);

    Website w1 = {"google.com", "Google"};
    Website w2 = {"youtube.com", "YouTube"};
    Website w3 = {"github.com", "GitHub"};

    push(&Backward, w1);
    push(&Backward, w2);
    push(&Backward, w3);

    currentwebsite(&Backward);
    goBack(&Forward, &Backward);
    currentwebsite(&Backward);
    goBack(&Forward, &Backward);
    currentwebsite(&Backward);

    goForward(&Forward, &Backward);
    currentwebsite(&Backward);

    return 0;
}