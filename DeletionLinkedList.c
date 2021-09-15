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
// Case1: Deleting the first element from the linked list
struct Node* deleteFirst(struct Node*head)
{
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
} ;
// Case 2: Deleting the element at a given Index in the linked list
struct Node* deleteAtIndex(struct Node*head, int index)
{
    struct Node*p=head;
    struct Node*q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;

    }
    p->next=q->next;
    free(q);
    return head;


};
// Case 3: Deleting the Last element from the linked list
struct Node* deleteATEnd(struct Node*head)
{
    struct Node*p=head;
    struct Node*q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    p->next=NULL;
    free(q);
    return head;

};
// Case 4: Deleting the element with a given value from the linked list
struct Node* deleteAtValue(struct Node*head, int value)
{
    struct Node*p=head;
    struct Node*q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
};
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
    head->data=4;
    head->next=second;
    //Link the second node to the third node
    second->data=3;
    second->next=third;
    //Link the third node to the fourth node
    third->data=8;
    third->next=fourth;
    //Terminate at the fourth node
    fourth->data=1;
    fourth->next=NULL;

    printf("Linked list before deletion\n");
    LinkedListTraversal(head);
   // head=deleteFirst(head);
    // head =deleteFirst(head);      // To delete the next element in the linked list use the function again
    //head=deleteAtIndex(head,2);
    //head=deleteAtEnd(head);
    head=deleteAtValue(head,8);
    printf("Linked list after deletion\n");
    LinkedListTraversal(head);

    return 0;
}
