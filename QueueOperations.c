#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int back;
    int front;
    int *arr;
};
int isFull(struct queue*q)
{
    if(q->back=q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue*q,int value)
{
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->back=q->back+1;
        q->arr[q->back]=value;
    }
}
void queueTraversal(struct queue*q)
{
    for(int i=0;i<q->size-1;i++)
    {
        q->back=q->back+1;
        printf(" The elements in the queue are :%d\n",q->arr[q->back]);
    }
}
int main()
{
    struct queue*q;
    q->size=6;
    q->front=-1;
    q->back=-1;
    q->arr=(int*)malloc(q->size*(sizeof(int)));
    enqueue(q,14);
    enqueue(q,78);
    enqueue(q,40);
    enqueue(q,35);
    enqueue(q,21);
    enqueue(q,12);
    queueTraversal(q);
    return 0;
}
