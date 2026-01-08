/*
Problem 1: (10 pts)
 Write a program to enter a natural number n and find all sphenic numbers from 1 to n using
Recursion (combined with iteration if necessary).
Note: A sphenic number is a product of p*q*r where p, q, and r are three distinct prime numbers.
Example: 30 = 2 * 3* 5; 42 = 2*3*7; 66 = 2*3*11.
30, 42, 66, 70, 78, 102, 105, 110, 114, 130, 138, 154, 165, … are sphenic numbers.
 Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify your
answer. (2pts)*/

#include <stdio.h>
int isPrime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int isSphenic(int n)
{

    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i) && n % i == 0)
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
int main()
{

    for (int i = 30; i <= 165; i++)
    {
        if (isSphenic(i) == 1)
        {
            printf("%d ", i);
        }
    }
    // isSphenic(42);
    return 0;
}