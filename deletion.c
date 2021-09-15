#include<stdio.h>
void display(int arr[], int size)
{
    //Code for Traversal
    for(int i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void deletion(int arr[100], int index, int size)
{
    //Code for Insertion
    for(int i=index; i< size-1; i++)
    {
        arr[i]=arr[i+1];
    }
}
int main()
{
    int arr[100]={7,8,12,27,88};
    int size=5, element=45, index=1;
    display(arr,size);
    deletion(arr, index, size);
    size-=1;
    display(arr,size);
    return 0;
}
