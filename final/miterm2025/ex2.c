#include <stdio.h>

int reverse(int n, int rev)
{
    if (n == 0)
    {
        return rev;
    }
    return reverse(n / 10, rev * 10 + n % 10);
}
int isPal(int n)
{
    if (n == reverse(n, 0))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n = 12621;
    if (isPal(n))
    {
        printf("pal");
    }
    else
    {
        printf("Not pal");
    }
    return 0;
}