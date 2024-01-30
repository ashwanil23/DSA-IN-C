#include <stdio.h>
#include <stdlib.h>
void printArr(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d ",i,arr[i]);printf("\n");
    }
    
}
void bSort(int *arr, int size){
    int temp;
    int isShort = 0;
    for (int i = 0; i < size-1; i++)
    {
        printf("Working on pass number %d \n",i+1);
        isShort = 1;
        for (int j = 0; j < size-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isShort = 0;
            }
            
        }
        if(isShort){
                return;
            }    
    }

}
int main()
{
    int arr[7] = {1, 33, 12, 85, 34, 7, 346};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr,size);
    bSort(arr, size);
    printArr(arr,size);
    return 0;
}
