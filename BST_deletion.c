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

// printing in preorder style
void preorder(struct node*t)
{
  if(t!=NULL)
  {
    printf("  %d",t->value);
    preorder(t->left);
    preorder(t->right);
  }

}

// function for deletion of node
struct node* delete_node(struct node*root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(value < root->value)
    root->left=delete_node(root->left,value);
    else if(value > root->value)
    root->right=delete_node(root->right,value);

    else
    {
        // no child
        if(root->left==NULL && root->right==NULL)
        {free(root);
        root=NULL;

        }

        // only right child available
        else if(root->left==NULL)
        {
            struct node*temp=root;
            root=root->right;
            free(temp);
        }

        // only left child availble
        else if(root->right==NULL)
        {
            struct node*temp=root;
            root=root->left;
            free(temp);
        }

        // bth the child are available
        else
        {
            struct node*temp;
            temp->value=min(root->right);
            root->value=temp->value;
            root->right=delete_node(root->right,temp->value);
        }

    }
    return(root);
}

    //functon for finding minimum in right subtree
    int min(struct node*root)
    {
        if(root==NULL)
        return;

        int value=root->value;
        int right=min(root->right);
        if(right<value)
        value=right;
        return value;

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
    printf("\n");
    delete_node(root,20);
    preorder(root);

}
