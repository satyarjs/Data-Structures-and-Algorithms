#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct Queue*q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Queue*q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueueRear(struct Queue*q, int value)
{
    if(isFull(q))
    {
        printf("The Queue  is full\n");
    }
    else
    {
        q->r=q->r+1;
        q->arr[q->r]=value;
    }
}

// The insertion from the front can only be done after removing one or more than one element from the front otherwise insertion from the front is not possible
void enqueueFront(struct Queue*q, int value)
{
    if(q->r==q->size-1 && q->f==-1)
    {
        printf("The Queue is full\n");
    }
    else
    {
        q->f=q->f-1;
        q->arr[q->f]=value;
    }
}
int dequeueRear(struct Queue*q)
{
    int value=-1;
    if(isEmpty(q))
    {
        printf("The Queue is empty\n");
    }
    else
    {
        value=q->arr[q->r];
        q->r=q->r-1;
    }
    return value;
}
int dequeueFront(struct Queue*q)
{
    int value=-1;
    if(isEmpty(q))
    {
        printf("The Queue is empty\n");
    }
    else
    {
        q->f=q->f+1;
        value=q->arr[q->f];
    }
    return value;
}
int main()
{
    struct Queue q;
    q.size=6;
    q.f=-1;
    q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueueRear(&q,14);
    enqueueRear(&q,1);
    enqueueRear(&q,2);
    enqueueRear(&q,3);
    enqueueRear(&q,4);
    enqueueRear(&q,5);
    printf("Dequeuing element from the front %d\n",dequeueFront(&q));
    enqueueFront(&q,12);
    printf("Dequeuing element from the rear %d\n",dequeueRear(&q));
    enqueueRear(&q,11);


    if(isFull(&q))
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }
    return 0;
}
