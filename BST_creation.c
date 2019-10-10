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

int main()
{
    struct node*root=NULL;
    root=insert(root,16);
    root=insert(root,9);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);
    preorder(root);

}
