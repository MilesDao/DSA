#include<stdio.h>
int main(){

    int arr[6]={5,3,9,12,15,1};
    int n = 6, k = 3;

    for( int i = 0 ; i< n ; i++){
        printf("%d->%d, ", i, arr[i]);
    }
    printf("\n======================\n");
    int j = k;
    while(j < n){
        arr[j-1] = arr[j];
        j += 1;// 
    }
    n = n-1;
    for( int i = 0 ; i< n ; i++){
        printf("%d->%d, ", i, arr[i]);
    }
    return 0;
}