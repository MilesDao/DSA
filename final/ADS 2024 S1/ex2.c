/*
Question 2: (6 pts)
▪ Write a program to solve the Question 1 using a Stack data structure with necessary
functions. (6 pts)
Note: stacks can be used to reverse the number digits.*/
#include <stdio.h>
#define MAX 100

struct _Stack
{
    int data[MAX];
    int top;
};
typedef struct _Stack Stack;

void init(Stack *s)
{
    s->top = -1;
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}
int length(Stack *s)
{
    return s->top + 1;
}

void push(Stack *s, int val)
{
    if (s->top == MAX - 1)
    {
        return;
    }
    s->top++;
    s->data[s->top] = val;
}
void pop(Stack *s)
{
    if (isEmpty(s))
        return;
    s->top--;
}
int reverse(int n)
{
    Stack s;
    init(&s);
    while (n > 0)
    {
        push(&s, n % 10);
        n /= 10;
    } // O(log(n))

    int rev = 0;
    int i = 0;
    while (i < length(&s)) // O(log(n))
    {
        rev = rev * 10 + s.data[i];
        i++;
    }
    while (!isEmpty(&s)) // O(log(n))
    {
        pop(&s);
    }
    return rev;
} // total = O(log(n))
int isSumPalindrome(int n)
{
    int sum = n + reverse(n);
    return sum == reverse(sum);
}
// void display(Stack *s)
// {
//     for (int i = 0; i < length(s); i++)
//     {
//         printf("%d", s->data[i]);
//     }
// }
int main()
{
    int n = 55;
    if (isSumPalindrome(n))
    {
        printf("palindromic");
    }
    else
    {
        printf("not palindromic");
    }
    return 0;
}