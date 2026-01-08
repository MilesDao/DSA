#include <stdio.h>

int count(int n)
{
    int sum = 0;
    while (n > 0)
    {
        n /= 10;
        sum++;
    }
    return sum;
} // O(log(n))
int power10(int n)
{
    if (n == 0)
        return 1;
    return 10 * power10(n - 1);
} // O(r)
void split(int n)
{
    if (count(n) == 1)
        return;
    int first = n / power10(count(n) / 2); // O(logn)
    int last = n % power10(count(n) / 2);  // O(logn)
    if (count(first) > count(last))
    {
        last *= 10;
    }
    printf("%d + %d  = %d\n", first, last, first + last);
    split(first + last);
}
// total = O(logn)
int main()
{
    int n = 47360;
    split(n);
    return 0;
}