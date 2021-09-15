#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int f;
    int r;
    int*arr;

};
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
void enqueue(struct Queue *q,int value)
{
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->r=q->r+1;
        q->arr[q->r]=value;
    }
}
int dequeue(struct Queue*q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("No element to dequeue\n");
    }
    else
    {
        a=q->arr[q->f];
        q->f=q->f+1;
    }
    return a;
}
int main()
{
    struct Queue q;
    q.size=10;
    q.f=-1;
    q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,78);
    dequeue(&q);
    if(isEmpty(&q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue is not empty\n");
    }
    return 0;
}
