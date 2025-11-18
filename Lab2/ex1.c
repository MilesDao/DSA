#include<stdio.h>
void isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    while( i < bitsSize-1){
        if(bits[i] == 1) i +=2;
        else{
            i += 1;
        }
        printf("%d\n", i);
    }
}
int main(){

    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i<size; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>1) break;
    }
    isOneBitCharacter(arr, size);
    return 0;
}