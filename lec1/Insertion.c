#include<stdio.h>
int main(){
    int arr[6]={5,3,9,12,15,1};
    int item = 10, k = 5, n=6;//position, //length;
    
    int j = n;
    for(int i = 0 ; i< n ; i++) printf("%d - > %d\n", i, arr[i]);
    printf("============================\n");
    n= n+1;
    while(j >=k){
        arr[j +1] = arr[j];
        j = j-1;
    }
    arr[k]= item;

    for(int i = 0 ; i< n ; i++) printf("%d - > %d\n", i, arr[i]);
    return 0;
}