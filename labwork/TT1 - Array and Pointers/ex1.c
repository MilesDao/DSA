/*
Exercise 1:
Write a pseudocode and implement a program in C to swap the first and last digits
of a positive integer.*/
#include <stdio.h>
int numdi(int n)
{
    int sum = 0;
    while (n > 0)
    {
        n /= 10;
        sum++;
    }
    return sum;
}
int powdi(int n, int r)
{
    if (r == 0)
        return 1;
    return n * powdi(n, r - 1);
}
int swap(int n)
{
    int first = 0, last = 0, mid = 0, sum = 0;
    last = n % 10;
    first = n / powdi(10, numdi(n) - 1);
    mid = (n - first * powdi(10, numdi(n) - 1) - last) / 10;

    sum = (last * powdi(10, numdi(n) - 1) + mid * 10 + first);
    return sum;
}
int main()
{
    int n = 29347381;

    printf("%d", swap(n));
}