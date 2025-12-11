/*

Exercise 3:
We want to implement a program in C/C++ to calculate approximately the number
Pi, a real constant, π = 3.14159265358979323846. One of the Pi formulas is as
follows:
4 4 4 4
4
4
π = − + − + ... +
−
1 3 5 7
4n + 1 4n + 3
where n is a natural number.
When n = 10, pi 3.0962410; When n = 100, pi 3.13659310; When n = 1000, pi
3.14109110; When n = 10000, pi 3.14138410;
 Write a function using Recursion with the input n to calculate pi. Another
parameters can be used in the function input. Write a main function to test
implemented functions.
 Calculate the complexity of your algorithm. Justify the answer.
*/
#include<stdio.h>
double pi(int n, int i, double sum){
    if( i > n) return sum;
    
    sum += (4.0/(4*i +1))-(4.0/(4*i +3));
    return pi(n, i+1, sum);
}
int main(){
    int n =10000;
    double result = pi(n, 0, 0.0);
    printf("for n=%d, pi = %.8f", n, result);
    return 0;
}