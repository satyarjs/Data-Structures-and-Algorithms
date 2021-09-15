#include<stdio.h>
#include<stdlib.h>
void mergeSort(int arr[], int arr2[], int arr3[], int m, int n)
{
    int i,j,k;
    i=j=k=0;
    while(i<m && i<n)
    {
        if(arr[i]<arr2[j])
        {
            arr3[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
        // Copy all the remaining elements from arr[] to arr3[]
        while(i<m)
        {
            arr3[k]=arr[i];
            k++;
            j++;
        }
        // Copy all the remaining elements from arr2[] to arr3[]
        while(j<n)
        {
            arr3[k]=arr2[j];
            k++;
            j++;
        }
    }
}
int main()
{
    int arr[100];
    return 0;
}
