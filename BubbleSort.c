#include<stdio.h>
#include<stdlib.h>
void PrintArray(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d \n",arr[i]);
    }
    printf("\n");
}
void BubbleSort(int *arr, int size)
{
    int temp;
    // For number of passes
    for(int i=0; i<size-1;i++)
    {
        // For comparison in each pass and number of comparison should decrease by 1 in each pass so size-1-i
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
}
// The bubble sort adaptive is for the array which is semi sorted or already sorted
void BubbleSortAdaptive(int *arr, int size)
{
    int temp;
    int isSorted=0;
    for(int i=0;i<size-1;i++)
    {
        printf("Working on the pass number %d\n",i+1); // Here it is i+1 because i is starting with zero
        isSorted=1;
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                // If we cannot swap anything in the array then the array is sorted
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSorted=0; // If the swap is happening then the array is not sorted so isSorted value is zero
            }
        }
        if(isSorted)
        {
            return;  // Here return means end the function here
        }
    }
}
int main()
{
    int arr[]={12,54,65,7,23};
    int size=(sizeof(arr))/(sizeof(arr[0]));
    // Printing the array before sorting
    PrintArray(arr,size);
    // Sorting the array using the bubble sort
    BubbleSort(arr,size);
    printf("The elements after sorting the array are :\n");
    // Printing the array after sorting
    PrintArray(arr,size);
    return 0;
}
