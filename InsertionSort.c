#include<stdio.h>
void PrintArray(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void InsertionSort(int *arr,int size)
{
    int key,j;
    // Loop for passes
    for(int i=1;i<=size-1;i++)
    {
        key=arr[i];
        j=i-1;
        // Loop for each pass
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    // -1  0   1   2   3   4   5
    //     12, 54, 65, 07, 23, 09 --> i=1, key=54, j=0
    //
    int arr[]={12,54,65,7,23,9};
    int size=(sizeof(arr))/(sizeof(arr[0]));
    // Printing the elements of the array before sorting
    PrintArray(arr,size);
    // Sorting the array using the insertion sort
    InsertionSort(arr,size);
    // Printing the elements of the array after sorting
    PrintArray(arr,size);
    return 0;
}
