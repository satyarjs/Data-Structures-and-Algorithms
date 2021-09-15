#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node*next;
struct Node*prev;

};
void LinkedListTraversal(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("Elements: %d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct Node*N1=(struct Node*)malloc(sizeof(struct Node));
    struct Node*N2=(struct Node*)malloc(sizeof(struct Node));
    struct Node*N3=(struct Node*)malloc(sizeof(struct Node));
    struct Node*N4=(struct Node*)malloc(sizeof(struct Node));

    N1->prev=NULL;
    N1->next=N2;
    N1->data=4;

    N2->prev=N1;
    N2->next=N3;
    N2->data=42;

    N3->prev=N2;
    N3->next=N4;
    N3->data=43;

    N4->prev=N3;
    N4->next=NULL;
    N4->data=44;

    LinkedListTraversal(N1);
    return 0;
}
