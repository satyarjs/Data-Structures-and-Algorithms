#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};

int isFull(struct Node*ptr)
{
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node* Push(struct Node*top, int value)
{
    if(isFull(top))
    {
        printf("Stack Overflown\n");
    }
    else
    {
        struct Node*n=(struct Node*)malloc(sizeof(struct Node));
        n->data=value;
        n->next=top;
        top=n;
        return top;
    }
};
void LinkedListTraversal(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int Peek(int pos)
{
    struct Node*ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int isEmpty(struct Node*top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int StackTop(struct Node*top)
{
    if(isEmpty(top))
    {
        printf("The stack is empty\n");
    }
    else
    {
        return top->data;
    }
}
int StackBottom(struct Node*top)
{
    if(isEmpty(top))
    {
        printf("The stack is empty\n");
    }
    else
    {
        struct Node*ptr=top;
        for(int i=1;i<4;i++)
        {
            ptr=ptr->next;
        }
        return ptr->data;
    }
}
int main()
{
    struct  Node*top=NULL;
    top=Push(top,145);
    top=Push(top,78);
    top=Push(top,63);
    top=Push(top,31);
    //LinkedListTraversal(top);
    //printf("The value at the first position is :%d\n",Peek(1));
    //printf("The value at the second position is %d\n",Peek(2));
    for(int i=0;i<4;i++)
    {
        printf("The value at the position %d is: %d\n",i,Peek(i));
    }
    return 0;
}
