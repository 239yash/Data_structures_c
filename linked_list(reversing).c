
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

void reverse()
{
struct node*back=NULL;
struct node*current=start;
struct node*forward=NULL;
while(current!=NULL)
{
forward=current->next;
current->next=back;
back=current;
current=forward;
}
start=back;
}


void main()
{
insert_end(20);
insert_end(25);
insert_end(10);
insert_start(35);
insert_start(40);
insert_start(45);
struct node*t;
t=start;
while(t)
{printf("%d \n",t->value);
t=t->next;}

reverse();

printf("now reversing the linked list \n \n");

t=start;
while(t)
{printf("%d \n",t->value);
t=t->next;
}
}

