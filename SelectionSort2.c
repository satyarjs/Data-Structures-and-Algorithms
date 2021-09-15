#include<stdio.h>
#include<stdlib.h>
void PrintArray(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void SelectionSort(int *arr,int size)
{
    printf("Running selection sort......\n");
    int IndexofMin;
    int temp;
    // Loop for the number of passes
    for(int i=0;i<size-1;i++)
    {
        IndexofMin=i;
        // This loop is used to found the minimum element
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[IndexofMin])
            {
                IndexofMin=j;
            }
        }
        // After we found the minimum  element and make it the IndexofMin we can swap the element with arr[i]
        // Swapping of arr[i] and the arr[IndexofMin]
        temp=arr[i];
        arr[i]=arr[IndexofMin];
        arr[IndexofMin]=temp;
    }
}
int main()
{
    // Input Array (There will be total n-1 passes. 5-1=4 in this case
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    // 00  01  02  03  04
    // 02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03   04
    // 02, 03,|05, 13,  12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    // The final sorted array
    // 00  01  02  03  04
    // 02, 03, 05, 12 ,13

    int arr[]={3,5,2,13,12};
    int size=(sizeof(arr))/(sizeof(arr[0]));
    // Printing the array before sorting
    PrintArray(arr,size);
    // Sorting the array using Selection sort
    SelectionSort(arr,size);
    // Printing the array after sorting
    PrintArray(arr,size);
    return 0;
}
