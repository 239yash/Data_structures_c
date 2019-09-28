#include<stdio.h>
#include<stdlib.h>
struct node
{
 int value;
 int priority;
 struct node*next;
};
struct node*start=NULL;

void insert(int data,int pri)
{
struct node*temp=(struct node*)malloc(sizeof(struct node));
if(start==NULL)
{
 start=temp;
 temp->next=NULL;
 temp->value=data;
 temp->priority=pri;
}
else
{
 struct node*t=start;
  while(t->next!=NULL)
{
t=t->next;
}
t->next=temp;
temp->next=NULL;
temp->value=data;
temp->priority=pri;

}
}

void getmax()
{
struct node*t=start;
int prior=t->priority;

while(t!=NULL)
{
if(prior>=t->priority)
{
prior=t->priority;
}
t=t->next;
}

t=start;
while(t!=NULL)
{
if(t->priority==prior)
{
printf(" the element is %d and priority is %d \n",t->value,prior);
}
t=t->next;
}
}

void delmax()
{
struct node*t=start;
int prior=t->priority;
struct node*p;


while(t->next!=NULL)
{
if(prior>=t->priority)
{
prior=t->priority;
}
t=t->next;

}
t=start;
while(t->next!=NULL)
{
if(t->priority==prior)
{break;}
t=t->next;
}

if(t==start)
{
start=t;
}

if(t!=start)
{
p=t;
t=t->next;
free(p);
}}

void print()
{
struct node*t=start;
while(t!=NULL)
{
printf(" the element is %d with priority %d \n",t->value,t->priority);
t=t->next;
}
}

void main()
{
insert(10,5);
insert(20,2);
insert(30,3);
insert(40,4);
getmax();
delmax();
print();

}

