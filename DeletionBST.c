#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};
struct Node*createNode(int data)
{
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
};
void inOrder(struct Node*root)
{
    if(root!=NULL)
    {
      inOrder(root->left);
      printf("%d ",root->data);
      inOrder(root->right);
    }
}
struct Node*inOrderPredecessor(struct Node*root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
};
struct Node*deleteNode(struct Node*root, int value)
{
    struct Node*iPre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->right==NULL && root->left==NULL)
    {
        free(root);
        return NULL;
    }
    // Search for the node to be deleted
    if(value<root->data)
    {
       root->left=deleteNode(root->left, value);
    }
    else if(value>root->data)
    {
        root->right=deleteNode(root->right,value);
    }
    //  Deletion strategy  when the node is found
    else
    {
        iPre=inOrderPredecessor(root);
        root->data=iPre->data;
        root->left=deleteNode(root->left, iPre->data);
    }
    return root;

};
int main()
{
    struct Node*p=createNode(6);
    struct Node*p1=createNode(4);
    struct Node*p2=createNode(7);
    struct Node*p3=createNode(3);
    struct Node*p4=createNode(5);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    printf("Printing the elements in order traversal before deletion\n");
    inOrder(p);
    deleteNode(p,3);
    printf("Printing the elements in order traversal after deletion\n");
    inOrder(p);
    return 0;
}
