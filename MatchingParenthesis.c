#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
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
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char value)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value;

    }
}
int pop(struct stack*ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow");
        return -1;

    }
    else
    {
        char value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int ParenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    // \0 is the NULL character
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(sp,'(');
        }
        else if(exp[i]==')')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp))
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
    char*exp="8*(9)";
    if(ParenthesisMatch(exp))
    {
        printf("The Parenthesis are matching\n");
    }
    else
    {
        printf("The Parenthesis are not matching\n");
    }
    return 0;
}
