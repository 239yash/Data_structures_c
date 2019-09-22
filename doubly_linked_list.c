
#include<stdio.h>
struct node
{
int value;
struct node *next;
struct node *prev;
};
struct node *start=NULL;

insert_end(int data)
{
struct node*temp=(struct node*)malloc(sizeof(struct node));
struct node*t=start;
if(start==NULL)
{
start=temp;
temp->value=data;
temp->prev=NULL;
}
else
{
while(t->next!=NULL)
{
t=t->next;
}
t->next=temp;
temp->next=NULL;
temp->prev=t;
temp->value=data;
}}

insert_start(int data)
{
struct node*temp=(struct node*)malloc(sizeof(struct node));
struct node*t=start;
if(start==NULL)
{
start=temp;
temp->prev=NULL;
temp->value=data;
}
else
{
start=temp;
temp->value=data;
temp->prev=NULL;
t->prev=temp;
temp->next=t;
}
}

traverse_end()
{
struct node*t=start;
while(t->next!=NULL)
{t=t->next;}
while(t!=NULL)
{printf(" %d \n ",t->value);
t=t->prev;}
}

void main()
{
insert_end(10);
insert_end(20);
insert_end(30);
insert_end(40);
insert_end(50);
insert_start(25);
/*struct node*t;
t=start;
while(t!=NULL)
{
printf(" %d \n ",t->value);
t=t->next;
}*/
traverse_end();
}

