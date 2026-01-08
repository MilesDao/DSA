/*

Problem:
Given an array of 10 elements: 2, 10, 27, 13, 90, 45, 5, 26, 49, 50.
In this problem, we try to find all co-prime numbers. Two integer numbers are co-prime if the
greatest common divisor of these two is 1.
The list of co-prime numbers from the above array is: {(2, 27), (2,13), (2,45), (2,5), (2,49), (10,
27), (10, 13), (10,49), (27,13), (27,5), (27,26), (27,50), (13,90), (13,45), (13,5), (13,49), (13,50),
(90,49), (90,26), (90,49), (45,26), (45,49), (5,26), (5,49), (26,49), (49,50)}
Question 1: (10 pts)
 Write a program to find all co-prime numbers with a given array of integer numbers using
Iteration. (8 pts)
 Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify
your answer. (2 pts)*/
// 27 49
#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
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