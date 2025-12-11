#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    int price;
} Item;

typedef struct Customer {
    char name[50];
    int buyQty;                 // how many units they want
    struct Customer *next;
} Customer;


typedef struct {
    Customer *front;
    Customer *rear;
} Queue;


Queue* initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, char customerName[], int buyQty) {
    Customer *c = (Customer*)malloc(sizeof(Customer));
    strcpy(c->name, customerName);
    c->buyQty = buyQty;
    c->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = c;
    } else {
        q->rear->next = c;
        q->rear = c;
    }
}

Customer* dequeue(Queue *q) {
    if (isEmpty(q)) return NULL;

    Customer *c = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    return c;
}

void displayQueue(Queue *q) {
    Customer *p = q->front;
    printf("\n--- Current Queue ---\n");
    while (p != NULL) {
        printf("Customer: %-10s | Wants: %d\n", p->name, p->buyQty);
        p = p->next;
    }
    printf("----------------------\n");
}



// ============================
// Process customer
// ============================
void processCustomer(Customer *c, Item *item) {
    printf("\nCustomer '%s' wants %d units of %s.\n",
           c->name, c->buyQty, item->name);

    if (item->quantity >= c->buyQty) {
        item->quantity -= c->buyQty;

        printf("✔️ Purchase successful! %s bought %d units.\n",
               c->name, c->buyQty);
        printf("Remaining stock of %s: %d units.\n",
               item->name, item->quantity);
    } else {
        printf("⚠️  Not enough stock! Only %d units left.\n",
               item->quantity);
    }
}




int main() {

    Item item;
    strcpy(item.name, "Laptop");
    item.quantity = 10;
    item.price = 1500;

    Queue *q = initQueue();

    enqueue(q, "Alice", 3);
    enqueue(q, "Bob", 5);
    enqueue(q, "Charlie", 4);
    enqueue(q, "Daisy", 1);

    displayQueue(q);

    while (!isEmpty(q)) {
        Customer *c = dequeue(q);
        processCustomer(c, &item);
        free(c);
    }

    printf("\nAll customers processed.\n");

    return 0;
}
