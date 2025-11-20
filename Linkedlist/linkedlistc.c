#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node;

node* makeNode(int x){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data = x;
    tmp->next = NULL; 
    return tmp;
}
//duyet dslk
void duyet(node *a){
    while(a != NULL){
        printf("%d ", a ->data);
        a = a->next;
    }
}

int Size(node *a){
    int cnt = 0;
    while(a != NULL){
        cnt++;
        a = a->next;
    }
    return cnt;
}

void insertFirst(node **a , int x){
    node *tmp = makeNode(x);
    tmp->next = *a; // *dia chi cua node head
    *a = tmp;
} 

void insertLast(node **a , int x){
    node *tmp = makeNode(x);
    node *p = *a;
    while(p->next != NULL){
        p = p ->next;
    }
    p->next = tmp;

}

void insertMiddle(node **a, int x, int pos){

}
int main(){
    node *a = NULL;
    for(int i = 1; i <= 5; i++){
        insertFirst(&a, i);
    }
    for(int j = 10 ; j <= 20 ; j++){
        insertLast(&a,j);
    }
    duyet(a);
    printf("\nsize = %d", Size(a));
    return 0;
}