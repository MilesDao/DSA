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


#include<stdio.h>
int reverse( int n){
    int tmp = 0;
    while( n > 0){
        tmp = tmp *10 + n%10;
        n/=10;
    }
    return tmp;
}
int checkPalindromic(int n){
    int rev = reverse(n);
    int sum = rev +n;
    if(sum== reverse(sum)) return 1;
    return 0;
}
int main(){

    int n  = 1449;
    if(checkPalindromic(n)){
        printf("N = %d and its reverse = %d, their sum is %d = palindromic\n", n , reverse(n), n+ reverse(n));
    }
    else{
        printf("N = %d and its reverse = %d, their sum is %d not palindromic\n", n , reverse(n), n+ reverse(n));
    }
    return 0;
}