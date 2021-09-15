#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;

};
void LinkedListTraversal(struct Node*head)
{
    struct Node*ptr=head;

    do{
        printf("Elements: %d\n",ptr->data);
        ptr=ptr->next;
    } while(ptr!=head);

}
struct Node* insertAtFirst(struct Node*head,int data)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node*p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    // At this point p points to the last pointer of the circular linked list
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
};
int main()
{
    // Allocate memory for nodes in the linked list in the Heap
    struct Node *head;
    head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second;
    second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third;
    third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth;
    fourth=(struct Node*)malloc(sizeof(struct Node));

    // Link the first node to the second node
    head->data=7;
    head->next=second;
    // Link the second node to the third node
    second->data=11;
    second->next=third;
    // Link the third node to the fourth node
    third->data=41;
    third->next=fourth;
    // Link the fourth node to the first node
    fourth->data=66;
    fourth->next=head;

    printf("Circular linked list before insertion\n");
    LinkedListTraversal(head);
    printf("Circular linked list after insertion\n");
    head=insertAtFirst(head,54);
    LinkedListTraversal(head);
    return 0;
}
