/*
Exercise 1:
Suppose we would like to implement a queue system for a commercial website.
Given that the website offers a list of items, each item has a limited quantity in
stock. Implement a queue of customers, and each customer can buy only a few
products among the available items.
❼ Determine the item name, quantity, and price in stock.
❼ Specify a queue of n customers; each customer can buy k products from one
item (k is different for each customer).
❼ Customers take turns to enter (enqueue) and leave (dequeue) the queue according to the FIFO order to purchase wanted products.
❼ If a customer successfully purchases products, display a message and reduce
the number of products in stock. Otherwise, display a warning message if the
item has been run out*/

#include <stdio.h>
#include <string.h>
#define CAPACITY 100
typedef struct
{
    char name[100];
    int quantity;
    double price;

} Item;
typedef struct
{
    char customerName[100];
    char itemName[100];
    int buyQty;
} Customer;
struct _Queue
{
    int front;
    int back;
    Customer data[CAPACITY];
};

typedef struct _Queue Queue;
void init(Queue *q)
{
    q->back = 0;
    q->front = 0;
}
int isEmpty(Queue *q)
{
    return q->back == 0;
}
int length(Queue *q)
{
    int l = q->back - q->front;
    return l;
}

void enqueue(Queue *q, Customer c)
{
    if (length(q) == CAPACITY)
    {
        printf("is Full");
        return;
    }
    if (isEmpty(q))
    {
        q->data[0] = c;
    }
    else
    {
        int idx = q->back;
        q->data[idx] = c;
    }
    q->back++;
}
Customer dequeue(Queue *q)
{
    Customer empty = {"", "", 0};
    if (isEmpty(q))
    {
        return empty;
    }
    Customer c = q->data[q->front];
    for (int i = 1; i < length(q); i++)
    {
        q->data[i - 1] = q->data[i];
    }

    q->back = q->back - 1;
    return c;
}
void processPurchase(Customer c, Item items[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(c.itemName, items[i].name) == 0)
        {
            if (items[i].quantity >= c.buyQty)
            {
                items[i].quantity -= c.buyQty;
                printf("%s bought %d %s(s). Total = %.2lf$\n", c.customerName, c.buyQty, c.itemName, c.buyQty * items[i].price);
            }
            else
            {
                printf("%s is out of stock for %s\n", items[i].name, c.customerName);
            }
            return;
        }
    }
    printf("purchase complete");
}
int main()
{
    Item items[] = {
        {"Sock", 10, 2.0},
        {"Hat", 20, 2.5},
        {"T-shirt", 2, 10.0},
        {"Pant", 3, 5.02}};
    int n = 4;

    Queue q;
    init(&q);

    Customer c1 = {"Alice", "Sock", 3};
    Customer c2 = {"Bob", "T-shirt", 2};
    Customer c3 = {"Charlie", "Pant", 5};

    enqueue(&q, c1);
    enqueue(&q, c2);
    enqueue(&q, c3);

    while (!isEmpty(&q))
    {
        Customer c = dequeue(&q);
        processPurchase(c, items, n);
    }

    return 0;
}
