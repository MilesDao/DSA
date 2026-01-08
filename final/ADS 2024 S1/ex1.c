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

int reverse(int n, int rev)
{
    if (n == 0)
        return rev;
    return reverse(n / 10, rev * 10 + n % 10);
} // O(log(n))

int isPalindrome(int n)
{
    return n == reverse(n, 0);
}
int isSumPalindrome(int n)
{
    int sum = n + reverse(n, 0); // O(log(n))
    return isPalindrome(sum);
}
int main()
{
    int N = 56;
    if (isSumPalindrome(N)) // O(log(n))
    {
        printf("palindromic");
    }
    else
    {
        printf("not palindromic");
    }

    return 0;
}