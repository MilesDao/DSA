#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    int price;
} stock;

typedef struct Customer {
    char name[50];
    int unit;
    struct Customer *next; 
} Customer;

typedef struct {
    Customer *front;
    Customer *rear;
} queue;

queue *init(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(queue *q){
    return (q->front == NULL);
}

void enqueue(queue *q, char name[], int unit){
    Customer *c = (Customer*)malloc(sizeof(Customer));
    strcpy(c->name, name);
    c->unit = unit;
    c->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = c;
    } else {
        q->rear->next = c;
        q->rear = c;
    }
}

Customer *dequeue(queue *q){
    if(isEmpty(q)) return NULL;
    Customer *c = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    return c;
}
void display(queue *q) {
    Customer *p = q->front;
    printf("\nCurrent Queue:\n");
    while (p != NULL) {
        printf("Customer: %s | Wants: %d\n", p->name, p->unit);
        p = p->next;
    }
    printf("===========================================\n");
}

void customer(Customer *c, stock *item) {
    printf("\nCustomer: %s, wants %d units of %s.\n", c->name, c->unit, item->name);

    if (item->quantity >= c->unit) {
        item->quantity -= c->unit;

        printf("Purchase successful! %s bought %d units.\n",
               c->name, c->unit);
        printf("Remaining stock of %s: %d units.\n",
               item->name, item->quantity);
    } else {
        printf("  Not enough stock! Only %d units left.\n",
               item->quantity);
    }
}


int main() {

    stock item;
    strcpy(item.name, "Laptop");
    item.quantity = 10;
    item.price = 1500;

    queue *q = init();

    enqueue(q, "A", 3);
    enqueue(q, "B", 5);
    enqueue(q, "C", 4);
    enqueue(q, "D", 1);

    display(q);

    while (!isEmpty(q)) {
        Customer *c = dequeue(q);
        customer(c, &item);
        free(c);
    }


    return 0;
}
