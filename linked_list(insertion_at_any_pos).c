
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

int count()
{
int c=0;
struct node*t=start;
while(t!=NULL)
{
c++;
t=t->next;
}
return(c);
}

void insert_nth(int data,int n)
{
int j=count();

if(start==NULL)
{printf("the list is empty\n");}
if(j<n-1)
{printf("the data cannot be inserted as list is samller then the given location\n");}

struct node *temp=(struct node*)malloc(sizeof(struct node));
struct node*t=start;
struct node*k;

temp->value=data;
for(int i=1;i<=n-2;i++)
{t=t->next;}
k=t->next;
t->next=temp;
temp->next=k;

}


void main()
{
insert_end(20);
insert_end(25);
insert_end(10);
insert_start(35);
insert_nth(40,2);
insert_nth(45,3);
insert_nth(50,4);
struct node*t;
t=start;
while(t)
{printf("%d \n",t->value);
t=t->next;
}
}

