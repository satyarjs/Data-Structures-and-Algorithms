#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void printArray(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int maximum(int arr[], int size)
{
    int max=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}
void countSort(int *arr, int size)
{
    int i,j;
    // Find the maximum element
    int max=maximum(arr,size);
    // Create a count array
    int *count=(int *)malloc((max+1)*sizeof(int));
    // Initialize the array elements to 0
    for(int i=0;i<size;i++)
    {
        count[i]=0;
    }

    // Increment the corresponding index in the count array
    for(int i=0;i<size;i++)
    {
        count[arr[i]]++;
    }
     i=0;   // Counter for count array
     j=0;   // Counter for given array
     while(i<=max)
     {
         if(count[i]>0)
         {
             arr[j]=i;
             count[i]--;
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
    int arr[]={9,1,4,14,4,15,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Printing the elements of the array before sorting\n");
    printArray(arr,size);
    printf("Sorting the elements of the array\n");
    countSort(arr,size);
    printf("Printing the elements of the array after sorting\n");
    printArray(arr,size);
    return 0;
}
