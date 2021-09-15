#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};
struct Node*f=NULL;
struct Node*r=NULL;
int isEmpty(struct Node*r, struct Node*f)
{
    if(f==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node*f,struct Node*r)
{
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    // Check if ptr pointer cannot be created
    if(n==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void LinkedListTraversal(struct Node*ptr)
{
    printf("Printing the elements of this Linked list\n");
    while(ptr!=NULL)
    {
        printf("Element :%d\n",ptr->data);
        ptr=ptr->next;
    }

}
void enqueue(int value)
{
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    // It is also the condition of isFull
    if(n==NULL)
    {
        printf("The queue is full\n");
    }
    else
    {
        n->data=value;
        n->next=NULL;
        // A special case when both the f and r are NULL and also the isEmpty condition
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next=n;
            r=n;
        }
    }
}
int dequeue()
{
    int value=-1;
    struct Node*n=f;
    // Check is the queue is empty
    if(f==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        f=f->next;
        value=n->data;
        free(n);
    }
    return value;
}
int main()
{
    // Enqueue few elements into the Linked list
    enqueue(32);
    enqueue(10);
    enqueue(12);

    // Printing the elements of the Linked list after the enqueue
    LinkedListTraversal(f);

    // Dequeuing few elements from the Linked list
    dequeue();

    // Printing the elements of the Linked list after the dequeuing
    LinkedListTraversal(f);
    return 0;
}
