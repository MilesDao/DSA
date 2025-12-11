/*
Exercise 2 :
Write a program in C/C++ to enter a natural number n and find all sphenic numbers
from 1 to n using Recursion. Calculate the complexity of the proposed algorithm.
Note: A sphenic number is a product of p*q*r where p, q, and r are three distinct
prime numbers. Example: 30 = 2 * 3* 5; 42 = 2*3*7; 66 = 2*3*11
*/

#include<stdio.h>

int isPrime(int n, int i){
    if(n<2) return 0;
    if(i*i > n) return 1;
    if(n%i ==0) return 0;
    return isPrime(n, i+1);
}

int countPrime(int n, int i, int count){
    if(i >n) return count;
    if(isPrime(i, 2) && n % i ==0 && (n/i)%i !=0){
        count++;
        while(n %i ==0){
            n = n/i;
        }
    }
    return countPrime(n, i + 1, count);
}

void findSphenic(int n , int i){
    if(i > n) return;
    if (countPrime(i, 2, 0) == 3){
        printf("%d ", i);
    }
    findSphenic(n, i + 1);
}
int main(){
    int n = 100;
    findSphenic(n,2);
    return 0;
}