#include<stdio.h>
void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}
int indexInsertion(int arr[],int size,int element,int capacity, int index){
  if(size>=capacity)
  {
      return -1;
  }
  for(int i=size-1; i>=index;i--)
  {
      arr[i+1]=arr[i];
  }
  arr[index]=element;
  return 1;
}
int main()
{
    int arr[100]={1,2,56,78,96};
    int size=5;
    int element=24;
    int index=3;
    int capacity=100;
    display(arr,size);
    printf("After insertion the arrays is \n");
    indexInsertion(arr, size, element, capacity, index);
    size=size+1;
    display(arr, size);
    return 0;
}
