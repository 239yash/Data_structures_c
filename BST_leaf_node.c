#include<stdio.h>
#include<stdlib.h>

//creation of node structure
struct node
{
    int value;
    struct node*left;
    struct node*right;
};

//function for creation of a BST

struct node* new_node(data)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->value=data;
    temp->left=NULL;
    temp->right=NULL;
    return(temp);
}

struct node* insert(struct node*root,int data)
{
    if(root==NULL)
    {
        root=new_node(data);

        return(root);
    }
    else
    {
        if(data<=root->value)
        root->left=insert(root->left,data);
        else
        root->right=insert(root->right,data);

        return(root);
    }


}

void preorder(struct node*t)
{
  if(t!=NULL)
  {
    printf("  %d",t->value);
    preorder(t->left);
    preorder(t->right);
  }

}

struct node* leaf_node(struct node*root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(value < root->value)
    root->left=leaf_node(root->left,value);
    else if(value > root->value)
    root->right=leaf_node(root->right,value);
    else
    {
        if(root->left==NULL && root->right==NULL)
        printf(" this node is a leaf node\n");
        else
        printf(" this node is not a leaf node\n");

    }
    return(root);



}


int main()
{
    struct node*root=NULL;
    root=insert(root,16);
    root=insert(root,9);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);
    root=leaf_node(root,12);
    preorder(root);
}

