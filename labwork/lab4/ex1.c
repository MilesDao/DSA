/*
Exercise 1 : In this problem, we would like to implement the algorithm to cal-
culate the digit sum of a given natural number that can be used in detecting errors
in message transmission or data storage.
For example:
N = 103509, the digit sum = 1 + 0 + 3 + 5 + 0 + 9 = 18.
N = 9512, the digit sum = 9 + 5 + 1 + 2 = 17
 Write a pseudo-code to solve the above problem using Iteration.
 Write a program from the pseudo-code and solve the Problem using Iteration.
 Calculate the complexity. Justify your answer.
 Write a program to solve the Problem using Recursion (with Iteration if
necessary).
 Calculate the complexity. Justify your answer.
*/
#include<stdio.h>

int findSum(int n){
    if( n ==0 ) return 0;
    return n%10 + findSum(n/10);
}

int main(){
    int n =103509;
    printf("%d", findSum(n));


    return 0;
}