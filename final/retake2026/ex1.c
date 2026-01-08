#include <stdio.h>
int numdigit(int n)
{
    int sum = 0;
    while (n > 0)
    {
        n /= 10;
        sum++;
    }
    return sum;
} // log n
int powdigit(int n, int r)
{
    if (r == 0)
        return 1;
    return n * powdigit(n, r - 1);
} // O(r)
int test(int n)
{
    int left, right, sum = 0;

    left = n / powdigit(10, numdigit(n) / 2);
    right = n % powdigit(10, numdigit(n) / 2);
    if (numdigit(right) < numdigit(left))
    {
        right *= 10;
    }
    sum = left + right;
    if (numdigit(sum) == 1)
        return sum;
    return test(sum);
}
int test2(int n)
{
    int left, right;
    while (numdigit(n) != 1)
    {
        left = n / powdigit(10, numdigit(n) / 2);
        right = n % powdigit(10, numdigit(n) / 2);
        if (numdigit(right) < numdigit(left))
        {
            right *= 10;
        }
        n = left + right;
    }
    return n;
}
int main()
{

    printf("%d ", test2(4730)); // O(logn^2)
    return 0;
}