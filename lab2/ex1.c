#include<stdio.h>
#include<stdlib.h>
struct listNum{
    int *arr;
    int size;
    int capa;
};
typedef struct listNum listNum;

void init(listNum *a, int sign){
    a ->capa = 10;
    a ->size = 1;
    a->arr = (int*)malloc(a->capa *sizeof(int));
    a->arr[0] = sign;
}

void ensureCapa(listNum *a) {
    if (a->size < a->capa) return;
    a->capa *= 2;
    a->arr = (int*)malloc(a->capa * sizeof(int));
}

void insertNum(listNum *a, int pos, int d){
    if(d<0 ||d>9) printf("invalid digit\n");
    if(pos < 1||pos > a->size) printf("invalid position\n");
    ensureCapa(a);
    for(int i = a->size ; i>pos; i--){
        a->arr[i] = a->arr[i-1];
    }
    a->arr[pos] = d;
    a->size +=1;
}

void removeNum(listNum *a, int pos){
    if(pos < 1||pos > a->size) printf("invalid position\n");
    for(int i = pos; i < a->size -1; i++){
        a->arr[i] = a->arr[i+1];
    }
    a->size --;
}

long long sum(listNum *a){
    long long sum = 0;
    for( int i = 1; i< a->size ; i++){
        sum+= a->arr[i];
    }
    return sum;
}

void display(listNum *a) {
    if (a->arr[0] == -1) printf("-");
    for (int i = 1; i < a->size; i++) {
        printf("%d", a->arr[i]);
    }
    printf("\n");
}

int main(){
    listNum a;
    init(&a, -1);
    insertNum(&a, 1, 1);
    insertNum(&a, 2, 2);
    insertNum(&a, 3, 3);
    insertNum(&a, 4, 4);
    insertNum(&a, 5, 5);
    display(&a);
    printf("================\n");
    removeNum(&a, 3);
    insertNum(&a, 3, 9);
    display(&a);
    printf("Sum of digits = %lld\n", sum(&a));
    return 0;
}