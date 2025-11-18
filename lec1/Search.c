#include<stdio.h>
int main(){
    int arr[6]={5,3,9,12,15,1};
    int n =6;
    int i = 0;
    while (i < n){
        if(arr[i] == 12) break;
        i = i + 1;
    }
    printf("%d", i);
    
}