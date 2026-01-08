#include <stdio.h>

float pi(int n, int i)
{
    if (i > n)
        return 0;

    return (4 / (float)(4 * i + 1) - 4 / (float)(4 * i + 3)) + pi(n, i + 1);
}
int main()
{

    int n = 100;
    printf("pi = %.7f\n", pi(n, 0));
}