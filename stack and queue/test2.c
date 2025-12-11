#include<stdio.h>
int reverse(int n){
    int tmp = 0;
    while (n>0)
    {
        tmp = tmp *10 + n%10;
        n/=10;
    }
    return tmp;
}

int checkPalindromic( int n ){
    int sum = n + reverse(n);
    if(sum == reverse(sum)) return 1;
    return 0;
}
int main (){
    int n = 65;
    if(checkPalindromic(n)){
        printf("N = %d and its reverse = %d, their sum is %d = palindromic\n", n , reverse(n), n+ reverse(n));
    }
    else{
        printf("N = %d and its reverse = %d, their sum is %d not palindromic\n", n , reverse(n), n+ reverse(n));
    }

    return 0;
}