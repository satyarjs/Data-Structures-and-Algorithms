#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
    int size;
    int f;
    int r;
    int*arr;

};
int isFull(struct circularQueue*q)
{
    if((q->r+1)%(q->size)==q->f)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
int isEmpty(struct circularQueue*q)
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
void enqueue(struct circularQueue*q, int value)
{

    // Check if the next element of the rear element is the front element
    if(isFull(q))
    {
        printf("The queue is full\n");
    }
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
        printf("Enqueued element: %d\n",value);
    }
}
int dequeue(struct circularQueue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}
int main()
{
    struct circularQueue q;
    q.size=4;
    q.f=0;
    q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));

    // Enqueue few elements
    enqueue(&q,78);
    enqueue(&q,15);
    enqueue(&q,87);

    // Dequeue few elements
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));

    // Enqueue few elements to make the stack full
    enqueue(&q,10);
    enqueue(&q,10);
    enqueue(&q,10);
    if(isEmpty(&q))
    {
        printf("The queue is empty\n");
    }
    if(isFull(&q))
    {
        printf("The queue is full\n");
    }
    return 0;
}
