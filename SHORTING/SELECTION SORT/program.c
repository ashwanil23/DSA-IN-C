#include <stdio.h>
#include <stdlib.h>
void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void sSort(int *arr, int size)
{
    int min;
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        min = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                temp = arr[j];
                arr[j] = min;
                min = temp;
            }
        }
        arr[i] = min;
    }
}

int main()
{
    int arr[5+5] = {7, 12, 8 ,9 ,10 ,10 ,9 ,83 ,4 ,1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);
    sSort(arr, size);
    printArr(arr, size);
    return 0;
}
