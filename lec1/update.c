#include<stdio.h>
int main(){
    int arr[6]={5,3,9,12,15,1};
    int n =6, k = 3;
    arr[k] = 280;
    for(int i = 0 ; i< n ; i++){
        printf("%d - > %d , ",i , arr[i]);
    }
    return 0;
}