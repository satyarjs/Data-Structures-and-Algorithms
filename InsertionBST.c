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
    n->left=NULL;
    n->right=NULL;
};
int isBST(struct Node*root)
{
    struct Node*prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else
    {
        // Considering an empty tree to be a BST
        return 1;
    }
}
void insert(struct Node*root, int key)
{
    struct Node*prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            return;
        }
        else if(key<root->data)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    struct Node*new=createNode(key);
    if(key<prev->data)
    {
        prev->left=new;
    }
    else
    {
        prev->right=new;
    }
}
int main()
{
    struct Node*p=createNode(8);
    struct Node*p1=createNode(6);
    struct Node*p2=createNode(9);
    struct Node*p3=createNode(5);
    struct Node*p4=createNode(15);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    insert(p,17);
    printf("%d",p->right->right->data);
    return 0;
}
