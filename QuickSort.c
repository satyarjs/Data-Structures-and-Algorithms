#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/* Procedure for Partitioning

1. i=low
2. j=high
3. pivot =low
4. i++ until element > pivot is found
5. j-- until element < pivot is found
6.  Swap arr[i] and arr[j] and repeat 4th and 5th point until j<i
7. Swap pivot and arr[j]

*/
int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);

    // Swap arr[low] also known as pivot element and arr[j]
    swap(arr[low], arr[j]);
    return j;
}
void QuickSort(int arr[], int low, int high)
{
    // Index of the pivot after partition
    int PartitionIndex;
    if (low < high)
    {
        PartitionIndex = Partition(arr, low, high);
        QuickSort(arr, low, PartitionIndex - 1);  // sort left sub-array
        QuickSort(arr, PartitionIndex + 1, high); // sort right sub-array
    }
}
int main()
{
    int arr[] = {3, 5, 2, 13, 12};
    int size = (sizeof(arr)) / (sizeof(arr[0]));
    // Printing the array of the elements before sorting
    PrintArray(arr, size);
    // Sorting the elements using quick sort
    QuickSort(arr, 0, size - 1);
    // Printing the array of the elements after sorting
    PrintArray(arr, size);
    return 0;
}
