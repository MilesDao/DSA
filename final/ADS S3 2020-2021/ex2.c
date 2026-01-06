/*
Question 2: (6 pts)
In this context, we try to find co-prime numbers using at least a recursive function.
 Implement the recursive function (2 pts).
 Write a program to solve the above Problem using the recursive function (4 pts)*/
#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void display(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (gcd(arr[i], arr[j]) == 1)
            {
                printf("(%d, %d); ", arr[i], arr[j]);
            }
        }
    }
}
int main()
{
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};

    display(arr);
    return 0;
}