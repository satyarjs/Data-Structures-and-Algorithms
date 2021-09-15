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
int main()
{
    struct stack *sp =(struct stack *)malloc(sizeof(struct stack));
    sp->size=6;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size *sizeof(int));
    printf("%d\n",isFull(sp));
    printf("%d\n", isEmpty(sp));
    printf("The stack has been created successfully\n");
    //if(isEmpty(sp))
    //{
      //  printf("The stack is empty");
    //}
    //else{
      //  printf("The stack is not empty");
    //}
    //if(isFull(sp))
    //{
      //  printf("The stack is full");
    //}
    //else{
      //  printf("The stack is not full");
    //}
    int value=49;
    Push(sp,56);
    Push(sp,56);
    Push(sp,56);
    Push(sp,56);
    Push(sp,56);
    Push(sp,49);

    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    Pop(sp,value);
    printf("The element %d has been popped out of the stack\n",value);
    return 0;
}
