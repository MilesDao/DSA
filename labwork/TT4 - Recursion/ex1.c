/*
Exercise 1 : In this problem, we would like to implement the algorithm to calculate the digit sum of a given natural number that can be used in detecting errors
in message transmission or data storage.
For example:
N = 103509, the digit sum = 1 + 0 + 3 + 5 + 0 + 9 = 18.
N = 9512, the digit sum = 9 + 5 + 1 + 2 = 17
❼ Write a pseudo-code to solve the above problem using Iteration.
❼ Write a program from the pseudo-code and solve the Problem using Iteration.
❼ Calculate the complexity. Justify your answer.
❼ Write a program to solve the Problem using Recursion (with Iteration if
necessary).
❼ Calculate the complexity. Justify your answer.*/
#include <stdio.h>
int digitsum(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + digitsum(n / 10);
} // O(logn)

int main()
{

    int n = 9512;
    printf("%d ", digitsum(n));
    return 0;
}