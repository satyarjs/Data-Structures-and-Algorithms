#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;

};
void preorder(struct Node*root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct Node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct Node*createNode(int data)
{
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
};
int main()
{
    // Constructing the root node using function
    struct Node*p=createNode(4);
    struct Node*p1=createNode(1);
    struct Node*p2=createNode(6);
    struct Node*p3=createNode(5);
    struct Node*p4=createNode(2);

    // Finally the tree looks like this
    /*
                  4
                 / \
                1   6
                /\
               5  2
    */
    // Linking the root and the left and the right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inorder(p);
    return 0;
}
