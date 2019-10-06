#include<stdio.h>
#include<stdlib.h>

//creation of node structure
struct node
{
    int value;
    struct node*left;
    struct node*right;
};

//creation of array
struct node*a[20];
int front=-1;
int rear=-1;

//function to create a tree

struct node* create()
{
    struct node*p;
    int x;
    printf("enter the no. (-1 for no data) \n");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    p=(struct node*)malloc(sizeof(struct node));
    p->value=x;

    printf(" left child of %d \n",x);
    p->left=create();

    printf(" right child of %d \n",x);
    p->right=create();

    return(p);
}

//function for insertion in queue

void enqueue(struct node*temp)
{
    if(temp!=NULL)
    {
        if(rear==19)
        {
            printf("queue overflow\n");
            return;
        }
        if(front==-1)
        {
            rear++;
            front++;
            a[rear]=temp;
        }
        else
        {

                rear++;
                a[rear]=temp;

        }


    }
}

//deletion in queue

void dequeue()
{
    if(front==-1 || front==20)
    {
        printf(" queue empty \n");
        return;
    }
    else
    {
        front++;
    }

}
 struct node* first()
 {
     if(front==-1)
     {
         printf("queue empty \n");
         return NULL;
     }
     else
     {
         return(a[front]);
     }

 }

//function for level order traversel

void levelorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }


      enqueue(root);
      while(empty()!=0)
      {
          struct node*current=first();
          printf("%d ",current->value);
          if(current->left!=NULL)
          {
              enqueue(current->left);
          }
          if(current->right!=NULL)
          {
              enqueue(current->right);
          }
          dequeue();
      }


}

//checking for queue empty

int empty()
{
    if(front==-1 || front==rear+1)
    {
        return(0);
    }
    else
    {
            return(1);
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


void main()
{
    struct node*root;
    root=create();
    //levelorder(root);
    preorder(root);
    levelorder(root);
}
