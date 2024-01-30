#include <stdio.h>
#include <stdlib.h>
void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d ", i, arr[i]);
        printf("\n");
    }
}
void iSort(int *arr, int size)
{
    int key;
    int j;
    for (int i = 1; i <= size - 1; i++)
    {
        printf("Working on pass number %d \n", i);
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[5] = {7,12,3,4,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);
    iSort(arr, size);
    printArr(arr, size);
    return 0;
}
