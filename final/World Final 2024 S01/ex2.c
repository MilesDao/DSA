/*
Question 2 (7 pts)
In this problem, we design and implement data structures in C/C++ to work on a list of 3D vectors.
 Propose a data structure for a 3D vector (x, y, z) with x, y, z are real. (1 pt)
 Propose a List data structure to store a collection of 3D vectors (the list capacity, n, can be predefined). (1 pt)
 Write a function to calculate the Euclidean distance between a pair of vectors in the list. (2 pts)
Given two vectors: v1 = (x1, y1, z1) and v2 = (x2, y2, z2) then their distance is expressed by:

d(v1, v2) = √(𝑥1 − 𝑥2)2 + (𝑦1 − 𝑦2)2 + (𝑧1 − 𝑧2)2

 Write a function to display the vectors in a list and the distance matrix. (2 pts)
Note: the distance matrix is square and of the size n × n. Each element of the matrix (i,j) is the
distance between two vectors vi and vj.
 Write a main function to test all the above functions. (1 pt)
*/

#include <stdio.h>
#include <math.h>
#define MAX 100

typedef struct
{
    double x;
    double y;
    double z;
} Vector;

typedef struct
{
    int size;
    Vector data[MAX];
} List;
void init(List *l)
{
    l->size = 0;
}
void add(List *l, double x, double y, double z)
{
    if (l->size == MAX)
        return;
    l->data[l->size].x = x;
    l->data[l->size].y = y;
    l->data[l->size].z = z;

    l->size++;
}
double distance(Vector v1, Vector v2)
{
    double res = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z));
    return res;
}
void display(List *l)
{
    for (int i = 0; i < l->size; i++)
    {
        printf("(%.2lf, %.2lf, %.2lf)", l->data[i].x, l->data[i].y, l->data[i].z);
    }
}
void displaydistance(List *l)
{
    for (int i = 0; i < l->size; i++)
    {
        for (int j = 0; j < l->size; j++)
        {
            printf("%.3lf ", distance(l->data[i], l->data[j]));
        }
        printf("\n");
    }
}
int main()
{
    List l;
    init(&l);

    add(&l, 0, 0, 0);
    add(&l, 1, 2, 2);
    add(&l, 3, 1, 4);

    display(&l);
    printf("\n");
    displaydistance(&l);
    return 0;
}