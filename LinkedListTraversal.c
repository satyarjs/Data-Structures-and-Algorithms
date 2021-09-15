#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;

};
void LinkedListTraversal(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("Elements :%d\n", ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    //Allocating memory for nodes in the linked lists in Heap
    struct Node*head;
    head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second;
    second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third;
    third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth;
    fourth=(struct Node*)malloc(sizeof(struct Node));

    //link the first node to the second node
    head->data=7;
    head->next=second;
    //Link the second node to the third node
    second->data=24;
    second->next=third;
    //Link the third node to the fourth node
    third->data=36;
    third->next=fourth;
    //Terminate at the fourth node
    fourth->data=12;
    fourth->next=NULL;

    LinkedListTraversal(head);
    return 0;
}
