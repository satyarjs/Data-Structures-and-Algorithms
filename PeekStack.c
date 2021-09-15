#include<stdio.h>
#include<stdlib.h>
struct stack {
    int size;
    int top;
    int *arr;

};
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void Push(struct stack *ptr, int value)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}
int Pop(struct stack *ptr, int value)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int Peek(struct stack *ptr, int i)
{
    int arrIndex=ptr->top-i+1;

    if(arrIndex<0)
    {
        printf("Not a valid position");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top-i+1];
    }
}
int main()
{
    struct stack *sp =(struct stack *)malloc(sizeof(struct stack));
    sp->size=6;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size *sizeof(int));
    int value=49;
    Push(sp,56);
    Push(sp,56);
    Push(sp,56);
    Push(sp,56);
    Push(sp,56);
    Push(sp,49);
    Pop(sp,value);
    printf("The elements of the stack has been shown below");
    for(int j=1; j<sp->top+1;j++)
    {
        printf("At position %d the value is %d \n",j,Peek(sp,j));
    }
    return 0;
}
