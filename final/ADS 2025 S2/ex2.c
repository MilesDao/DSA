/*
Question 2: (8 pts)
Let a priority queue of elements be defined as follows:
typedef struct {
 int data;
 int priority; // possible values: [0 .. 5]
} Element;
typedef struct {
 int size;
 Element data[100];
}Queue;
In this queue:
• Elements with higher priority values (smaller numbers) are placed at the front
whenever a new element is added.
University of Science and Technology of Hanoi
***
Final Examination
Subject: Algorithms and Data Structures
Code: 02 No of pages: 02
Date: 24/10/2025
Academic year: 2024–2025 Time: 75 minutes
Important instructions
1. Only the course slides and your own exercises'
code are allowed.
2. Copy or using Internet will lead to heavy
penalty.
Department ICT Lecturer (or Head of
Subject) Dr. Đoàn Nhật Quang
Student name Student’s ID
• Initial Queue:
Data: 30 | Priority: 1
Data: 25 | Priority: 3
• After enqueue (10, 0):
Data: 10 | Priority: 0
Data: 30 | Priority: 1
Data: 25 | Priority: 3
• The dequeue operation removes the front element (i.e., the element with the
highest priority).
You have to implement the following functions in C/C++:
▪ Implement a function init() to initialize the queue and create an initial queue
with at least six elements of your choice (data, priority).
▪ Implement the enquene() and dequeue() functions and other basic functions
(init(), display(), etc.)
▪ Write a main() function to test all the above functions.
*/
#include <stdio.h>
typedef struct
{
    int data;
    int priority; // possible values: [0 .. 5]
} Element;
typedef struct
{
    int size;
    Element data[100];
} Queue;
void init(Queue *q)
{
    q->size = 6;

    q->data[0] = (Element){10, 1};
    q->data[1] = (Element){20, 2};
    q->data[2] = (Element){30, 3};
    q->data[3] = (Element){40, 4};
    q->data[4] = (Element){50, 5};
    q->data[5] = (Element){60, 6};
}

void enqueue(Queue *q, int val, int priority)
{
    if (q->size >= 100)
        return;

    for (int i = q->size - 1; i >= priority; i--)
    {
        q->data[i + 1] = q->data[i];
    }
    q->data[priority] = (Element){val, priority};
    q->size++;
}

void dequeue(Queue *q, int priority)
{
    if (q->size == 0)
        return;
    for (int i = priority; i < q->size; i++)
    {
        q->data[i] = q->data[i + 1];
    }
    q->size--;
}
void display(Queue *q)
{

    for (int i = 0; i < q->size; i++)
    {
        printf("data = %d | priority = %d\n", q->data[i].data, q->data[i].priority);
    }
}
int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 100, 0);
    display(&q);
    printf("===================================\n");
    dequeue(&q, 4);
    display(&q);
    enqueue(&q, 400, 4);
    printf("===================================\n");
    display(&q);

    return 0;
}