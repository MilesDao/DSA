/*
Exercise 2 :
Write a program in C/C++ to enter a natural number n and find all sphenic numbers
from 1 to n using Recursion. Calculate the complexity of the proposed algorithm.
Note: A sphenic number is a product of p*q*r where p, q, and r are three distinct
prime numbers. Example: 30 = 2 * 3* 5; 42 = 2*3*7; 66 = 2*3*11*/
#include <stdio.h>

int isPrime(int n, int i)
{
    if (n < 2)
        return 0;
    if (i * i > n)
        return 1;
    if (n % i == 0)
        return 0;
    return isPrime(n, i + 1);
}

// integeral
int isSphenic1(int n)
{

    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i, 2) && n % i == 0)
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
// recursive
int isSphenic2(int n, int cnt, int i)
{
    if (cnt > 3)
        return 0;
    if (n == 1)
    {
        return cnt == 3;
    }

    if (isPrime(i, 2) && n % i == 0)
    {
        int power = 0;

        while (n % i == 0)
        {
            n /= i;
            power++;
        }
        if (power > 1)
            return 0;
        cnt += 1;
    }
    return isSphenic2(n, cnt, i + 1);
}
int main()
{
    int n = 165;
    for (int i = 30; i <= n; i++)
    {
        if (isSphenic1(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int i = 30; i <= n; i++)
    {
        if (isSphenic2(i, 0, 2))
        {
            printf("%d ", i);
        }
    }

    // printf("%d ", isSphenic2(30, 0, 2));
    return 0;
}