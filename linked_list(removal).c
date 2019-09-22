
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

void removal()
{
 int choice;
 printf("enter the choice 1 for the removal from start and 2 for the removal from end \n");
 scanf("%d",&choice);
 if (choice==1)
 {
  struct node *t=start;
 start=t->next;
 free(t);
 }
 if(choice==2)
 {
 struct node*s=start;
  struct node*t=start;
 while(t->next!=NULL)
 t=t->next;
 while(s)
 {
 if(s==t)
 {
 s->next=NULL;
 break;
 }
 }
 free(t);
 }
}

void main()
{
insert_end(20);
insert_end(25);
insert_end(10);
insert_start(35);
insert_end(15);
insert_start(30);
struct node*t;
t=start;
while(t)
{printf("%d \n",t->value);
t=t->next;}
removal();
t=start;
while(t)
{printf("%d \n",t->value);
t=t->next;
}
}
