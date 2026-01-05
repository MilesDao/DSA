/*
Question 1: (12pts)
In this problem, we check whether a sum of a given natural number and its reverse is
palindromic or not. A number is palindromic if it remains the same when its digits are reversed.
For example:
N = 56 and its reverse = 65, their sum is 121 = palindromic
N = 132 and its reverse = 231, their sum is 363 = palindromic
N = 605 and its reverse = 506, their sum is 1111 = palindromic
▪ Propose and implement a recursive function to solve the above problem. (8pts)
▪ Calculate the complexity of the proposed algorithm. (2pts)
▪ Propose a method to optimize the checking process. Justify your answer. (2pts)*/

#include <stdio.h>

int reverse(int n, int sum)
{
    if (n <= 0)
        return sum;

    sum = sum * 10 + n % 10;
    return reverse(n / 10, sum);
}

int checkPal(int n)
{
    int sum = n + reverse(n, 0);
    if (sum == reverse(sum, 0))
        return 1;
    return 0;
}
int main()
{
    int N = 55;
    if (checkPal(N))
    {
        printf("palindromic");
    }
    else
    {
        printf("not palindromic");
    }

    return 0;
}