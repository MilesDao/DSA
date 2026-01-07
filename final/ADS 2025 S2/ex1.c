/*

Question 1: (8pts)
We want to compute a division between two integers (divisor is different from 0) using
only subtraction and recursion as follows:
𝑑𝑖𝑣(𝑎, 𝑏) = {
𝑞𝑢𝑜𝑡𝑖𝑒𝑛𝑡
𝑟𝑒𝑚𝑎𝑖𝑛𝑑𝑒𝑟
= 𝑞𝑢𝑜𝑡𝑖𝑒𝑛𝑡
=
+
𝑎 𝑖𝑓
1, 𝑑𝑖𝑣
𝑎 <
(𝑎
𝑏
− 𝑏, 𝑏)
For example: quotient and remainder = 0 at the beginning
▪ div(10,3) = (quotient = 1, div(10-3,3)) = (quotient = 2, div (7-3,3)) = (quotient = 3,
div(4-3,3))
▪ div(1,3) = (remainder = 1)
▪ Result: quotient = 3 and remainder = 1.
Note: Use pointers to update the quotient and remainder in the recursive function. You
can use the following declaration: int div(int *q, int *r, int a, int b).
▪ Implement this recursive division algorithm in C/C++. (6 pts)
▪ Calculate the complexity of your algorithm. Justify your answer. (2 pts)
*/
#include <stdio.h>

int div(int *q, int *r, int a, int b)
{
    if (a < b)
    {
        *r = a;
        return -1;
    }

    *q = *q + 1;
    return div(q, r, a - b, b);
}
int main()
{
    int q, r;
    div(&q, &r, 10, 3);

    printf("quotient = %d and remainder = %d.", q, r);
    return 0;
}