#include <stdio.h>
#include <stdlib.h>
void printArray(int *arr, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    printf("Size of Array is = %d", size);
}
int maxElement(int *arr, int size)
{
    int max = arr[0];
    int i = 1;
    while (i < size)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        i++;
    }
    return max;
}

void countSort(int *arr, int size)
{
    int max = maxElement(arr, size);

    int *temp = (int *)malloc((max+1) * sizeof(int));

    int i = 0;
    int j = 0;

    for (int k = 0; k < max + 1; k++)
    {
        temp[k] = 0;
    }

    for (i = 0; i < size; i++)
    {
        temp[arr[i]] = temp[arr[i]] + 1;
    }

    i = 0;
    j = 0;
    while (i < max+1)
    {
        if ((temp[i]) > 0)
        {
            arr[j] = i;
            temp[i] = temp[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[10] = {12, 2, 23, 2, 5, 11, 24, 54, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array Before CountSort is : ");
    printArray(arr, size);
    printf("\n");

    countSort(arr, size);
    printf("Array after CountSort is : ");
    printArray(arr, size);

    return 0;
} /* END OF MAIN FILE*/