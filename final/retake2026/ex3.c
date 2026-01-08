/*
Question 3: (5 pts)
Traditional Selection Sort selects only the minimum element in each pass. We want design a Two-
Way Selection Sort algorithm that, during each pass, selects both the minimum and maximum
elements and places them at the beginning and end of the array, respectively.
Your tasks are:
· Implement the above sorting algorithm (4 pts).
· Analyze the time complexity of your algorithm. (1 pt).*/

//  5 1 3 4 2==1 2 3 4 5

#include <stdio.h>

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
    }
}
int main()
{
    int n = 10;
    int arr[] = {3, 1, 2, 4, 9, 6, 5, 7, 10, 8};
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}