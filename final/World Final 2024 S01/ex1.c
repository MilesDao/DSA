/*
Question 1 (10 pts)
In this problem, a natural number is given. The objective is to find a digit and swap its position
in the number to obtain the smallest possible value.
Note: The smallest value must have the same number of digits as in the original value; thus,
0 cannot be used.
 Example: 51029 -> the possible smallest value is 15029 after one swap.
 Propose an algorithm using iteration and implement it in C/C++ to complete the task. (3
pts)
 Propose and implement an alternative algorithm using recursion for this task. (6 pts)
 Calculate the complexity of the two approaches. Justify your answer by making comments
on the code. (1 pt)
Hint: You can use an array to store all digits. The problem becomes sorting and searching on
an array*/

#include <stdio.h>
#include <stdlib.h>

int length(int n, int len)
{
    if (n == 0)
    {
        return len;
    }
    len++;
    return length(n / 10, len);
}

void store(int n, int arr[])
{
    int len = 0;
    while (n > 0)
    {
        arr[len] = n % 10;
        n /= 10;
        len++;
    }
    for (int i = 0; i < len / 2; i++) // 5
    {
        int tmp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = tmp;
    }
}

void findSwap(int arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        int minIdx = 0;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIdx] && arr[j] != 0)
            {
                minIdx = j;
            }
        }
        if (arr[minIdx] < arr[i])
        {
            int tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
            break;
        }
    }
}
void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n = 82349;
    int arr[20];
    store(n, arr);
    findSwap(arr, length(n, 0));
    display(arr, length(n, 0));

    return 0;
}