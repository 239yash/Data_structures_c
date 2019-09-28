#include<stdio.h>
struct node
{
    int value;
    struct node *next;
};
struct node *start=NULL;
int rear=-1;
int front=-1;



void insertion(int data)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    struct node*t=start;
    if(start==NULL)
    {
        start=temp;
        temp->value=data;
        temp->next=start;
        rear++;
        front++;
    }
    else
    {
    do
    {
    t=t->next;
    }while (t->next!=start);
        t->next=temp;
        temp->value=data;
        temp->next=start;
        rear++;
    }

}

void deletion()
{
    struct node*t=start;
    struct node*s=start;
    if(front==-1)
    {
        printf("queue is empty\n");
    }
    else
     {
         do
         {
           s=s->next;
         }
         while(s->next!=start);

         s->next=t->next;
         start=t->next;
         free(t);
         front++;

     }
}

void print()
{
struct node*t;
t=start;

do
{

printf("%d \n",t->value);
t=t->next;

}
 while(t!= start);
}

void main()
{
    insertion(10);
    insertion(20);
    insertion(30);
    insertion(40);
    insertion(50);
    printf(" front is %d and rear is %d \n",front,rear);
    print();
    deletion();
    deletion();
    printf(" front is %d and rear is %d \n",front,rear);
    print();

}

