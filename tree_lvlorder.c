#include<stdio.h>
#include<stdlib.h>
//creation of node structures
struct node
{
    int value;
    struct node*left;
    struct node*right;
};

//creation of queue structure
struct queue
{
    struct node*link;
    struct queue*next;
};
struct queue*start=NULL;

//declarations
struct node* create();
void enqueue(struct node*);
void dequeue();
void levelorder(struct node*);


//function for node creation
struct node* create()
{
    struct node*p;
    int x;
    printf("enter data and -1 for no node");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    p=(struct node*)malloc(sizeof(struct node));
    p->value=x;

    printf("enter left child of %d \n",x);
    p->left=create();

    printf("enter the right child of %d \n",x);
    p->right=create();
    return(p);
}

//funtion for insertion in queue
void enqueue(struct node*temp)
{
    struct queue*new=(struct queue*)malloc(sizeof(struct queue));
    struct queue*t=start;
    if(temp!=NULL)
    {
    if(start==NULL)
    {
        new->link=temp;
        new->next=NULL;
        start=new;
    }
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=new;
        new->link=temp;
        new->next=NULL;
}
}
}

//deletion of front element from queue
void dequeue()
{
    if(start==NULL)
    {
        printf("queue is empty");
        return;
    }
    else
    {
            struct queue*t=start;
            struct queue*s;
            s=start;
            t=t->next;
            start=t;
            free(s);
    }

}

// function for level order printing
/*void levelorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        enqueue(root);
        while(empty()!=0)
        {
            struct node*current=first();
            printf("%d  ",current->value);
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

}*/

struct node* first()
{
    struct queue*t=start;
    if(start==NULL)
    return NULL;
    else
    {
    struct node*s=t->link;
      return(s);
    }

}

//function for checkin the queue is empty or not

int empty()
    {
        struct queue*t=start;
        if(start==NULL)
        {
            return(0);
        }
        else
        return(1);

    }

    // function for preorder traversel
    void preorder(struct node*root)
    {
    if(root==NULL)
    return;
    printf("%d ",root->value);
    preorder(root->left);
    preorder(root->right);}

void main()
{
    struct node*root;
    root=create();
    //levelorder(root);
    preorder(root);
}
