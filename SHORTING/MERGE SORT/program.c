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
void merge(int *arr, int low ,int mid ,int high)
{
    int j = mid+1;int B[100];
    int k = low;
    int i = low;
    while(i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++; k++;
        }
        else {
            B[k] = arr[j];
            j++;k++;
        }
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        i++;k++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        j++;k++;
    }
    for (int i = 0; i <= high ; i++)
    {
        arr[i] = B[i];
    }
}
void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
int main()
{
    int arr[6] = {7, 12, 3, 4, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);
    mergeSort(arr, 0, 5);
    printArr(arr, size);
    return 0;
}
