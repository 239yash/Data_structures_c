#include<stdio.h>

int a[20];
int front=-1;
int rear=-1;

void enqueue(int data)
{
if(rear==19)
{printf("the queue is full \n ");
}

if(front==-1)
{
rear++;
front++;
a[rear]=data;
}

if(front!=-1)
{rear++;
a[rear]=data;}
}

int dequeue()
{
if(front==-1)
{
printf(" the queue is empty \n ");
}
else
{
front++;
}}

int front_ele()
{
if(front==-1)
{printf(" the queue is empty \n ");

}
else
{
printf(" the element at front is %d \n",a[front]);
}
}

void main()
{
enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
dequeue();
for(int i=front;i<=rear;i++)
{
printf(" %d \n ",a[i]);
}
}
