#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node*right;
    struct Node* left;
};
struct Node*createNode(int data)
{
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
};
int isBST(struct Node*root)
{
    static struct Node*prev=NULL;
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
        // Considering an empty tree to be an binary search tree
        return 1;
    }
}struct Node*searchBST(struct Node*root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        // We should return the pointer not the data so return root
        return root;
    }
    else if(root->data > key)
    {
        return searchBST(root->left,key);
    }
    else
    {
        return searchBST(root->right,key);
    }
};
struct Node*searchIter(struct Node*root,int key)
{
    // Till root is not equal to NULL means we either reach the leaf Node or NULL is given in the beginning
    while(root!=NULL)
    {
        if(root->data==key)
        {
            return root;
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
    return NULL;
};
int main()
{
    struct Node*p=createNode(5);
    struct Node*p1=createNode(3);
    struct Node*p2=createNode(6);
    struct Node*p3=createNode(1);
    struct Node*p4=createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    struct Node*n=searchIter(p,4);
    if(n!=NULL)
    {
        printf("Found :%d",n->data);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}
