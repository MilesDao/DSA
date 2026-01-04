#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j;
    int *arr = (int *)malloc(2*sizeof(int));

    if ( arr == NULL|| numsSize <2 || nums == NULL){
        *returnSize = 0;
        return NULL;

    }
    for( int i =0 ; i < numsSize ; i++){
        for(int j = i+1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                *returnSize =2;
                arr[0] = i;
                arr[1] = j;
            }
            return arr;
        }
    }
    *returnSize =0;
    free(arr);
    return NULL;
}

int main(){
    int nums[] = {3,2,4};
    int target = 6;
    int returnSize;

    int *res = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, &returnSize);

    printf("%d %d", res[0], res[1]);
    free(res);
    return 0;
}


int isPrime(int num, int i){
    if( num <=2 ) return (num ==2)? 1:0;
    if( num % i ==0) return 0;
    if( i*i > num) return 1;
    return isPrime(num, i+1);
}
int findDistinctPrimes(int num, int current, int count){
    if( num ==1) return count;
    if( isPrime(current, 2) && num % current ==0){
        count++;
        while( num % current ==0){
            num = num / current;
        }
    }
    return findDistinctPrimes(num, current+1, count);
}
void findSphenicNumbers(int n, int current){
    if( current > n) return;
    if( findDistinctPrimes(current, 2, 0) ==3){
        printf("%d ", current);
    }
    findSphenicNumbers(n, current+1);
}
