#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
void isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }

}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct stack *s;
    s->size=80;
    s->top=-1;
    s->arr=(char *)malloc(s->size *sizeof(char));
    // Pushing an element into the stack
    //s->arr[0]=7;
    //s->top++;
    // Check if the stack is empty
    isEmpty(s);
    return 0;
}
