#include <stdio.h>

void swap(int arr[], int len, int i)
{
    if (i == len - 1)
        return;
    int minIdx = 0;
    for (int j = i + 1; j < len; j++)
    {
        if (arr[minIdx] > arr[j] && arr[j] != 0)
        {
            minIdx = j;
        }
    }
    if (arr[minIdx] < arr[i])
    {
        int tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
        return;
    }

    swap(arr, len, i + 1);
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
    int arr[10000];
    int n = 82349;
    int len = 0;

    while (n > 0)
    {
        arr[len++] = n % 10;
        n /= 10;
    }
    for (int i = 0; i < len / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = tmp;
    }
    swap(arr, len, 0);
    display(arr, len);

    return 0;
}