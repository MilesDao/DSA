/*
Question 2: (6 pts)
In this context, we try to find co-prime numbers using at least a recursive function.
 Implement the recursive function (2 pts).
 Write a program to solve the above Problem using the recursive function (4 pts)
*/
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

int iSphenic(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i, 2) == 1 && n % i == 0)
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
int isSphenic(int n, int i)
{
}
int main()
{

    for (int i = 30; i <= 165; i++)
    {
        if (iSphenic(i))
        {
            printf("%d ", i);
        }
    } // O(n*n*sqrt(n))

    return 0;
}