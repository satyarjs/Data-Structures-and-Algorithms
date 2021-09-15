#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node*next;
};
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
int isFull(struct Node*top)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void LinkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node* Push(struct Node*top, int value)
{
    if(isFull(top))
    {
        printf("Stack Overflow");
    }
    else
    {
        struct Node*n = (struct Node*)malloc(sizeof(struct Node));
        n->data=value;
        n->next=top;
        top=n;
        return top;
    }
}
int Pop(struct Node **top)
{
    if(isEmpty(*top))
       {
           printf("Stack Underflow");
       }
       else
        {
            struct Node *n =*top;
            *top=(*top)->next;
            int x= n->data;
            free(n);
            return x;
        }
}
int main()
{
    struct Node *top=NULL;
    top=Push(top,14);
    top=Push(top,23);
    top=Push(top,121);
    top=Push(top,159);
    LinkedListTraversal(top);
    Pop(&top);
    printf("After popping the element \n");
    LinkedListTraversal(top);


    return 0;
}
