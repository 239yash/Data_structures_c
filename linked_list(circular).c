
#include<stdio.h>
struct node
{
int value;
struct node *next;
};
struct node *start=NULL;


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

circular()
{
struct node*t;
t=start;
while(t!=NULL)
{
 t=t->next;
}
t=start;
}

void traverse_circ()
{
struct node*t;
t=start;
do
{
printf("%d \n ",t->value);
t=t->next;
}
while (t!=start);
}

void main()
{
insert_end(20);
insert_end(25);
insert_end(10);
insert_start(35);
circular();
traverse_circ();
}

