#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} Queue;


Queue *create_queue(){
    Queue *queue =malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int size(Queue *queue){
    return queue ->size;
}
bool is_empty(Queue *queue){

    return (queue->size == 0);
}



int main(){

    return 0;
}


