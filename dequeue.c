#include<stdio.h>
struct node
{
    int value;
    struct node*next;
};
struct node*start=NULL;

void insert_end(int n)
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 struct node *t;
 if(start==NULL)
 {
 temp->value=n;
 temp->next=NULL;
 start=temp;}
 else
 {
   t=start;
   while(t->next!=NULL)
   {
     t=t->next;
   }
   temp->value=n;
   temp->next=NULL;
   t->next=temp;
 }
}

insert_start(int n)
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 struct node*t;
 if(start==NULL)
 {temp->value=n;
 temp->next=NULL;
 start=temp;}
 else
 {
   t=start;
   start=temp;
   temp->value=n;
   temp->next=t;
 }
}

void removal_start()
{
    struct node *t=start;
    start=t->next;
    free(t);
 }

void removal_end()
{
  struct node*s;
 struct node*t=start;
 while(t->next!=NULL)
 {
 s=t;
 t=t->next;
 }

 s->next=NULL;
 free(t);
 }
 void print()
 {
     struct node*t=start;
     while(t!=NULL)
     {
         printf("\n%d ",t->value);
         t=t->next;
     }
 }

void main()
{
    insert_start(10);
    insert_end(20);
    insert_start(30);
    insert_start(40);
    print();
   removal_end();
   //removal_start();
    print();
}
