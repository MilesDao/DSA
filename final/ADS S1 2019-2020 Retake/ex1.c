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

int isSphenic(int n)
{
    int cnt = 0;
    int lastFactor = -1;
    for (int i = 2; i * i <= n && cnt < 3; i++)
    {
        if (n % i == 0)
        {
            n /= i;
            cnt++;
            if (n % i == 0)
                return 0;

            lastFactor = i;
        }
    }
    // If n > 1 after the loop, the remaining n is the last prime factor
    if (n > 1 && n != lastFactor)
    {
        cnt++;
    }
    return cnt == 3;
}
// O(sqrt(n))
int main()
{

    for (int i = 30; i <= 165; i++)
    {
        if (isSphenic(i) == 1)
        {
            printf("%d ", i); // O(n*sqrt(n))
        }
    }
    // isSphenic(42);
    return 0;
}