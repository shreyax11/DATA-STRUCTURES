#include<stdio.h>
#include<stdlib.h>
#define size 3
typedef struct Queue{
	int front,rear;
	int q[size];
}queue;
void enqueue(queue *q,int value);
int dequeue(queue *q);
void display(queue *q);
void main()
{
	int ch,v,a;
	queue q;
	q.front=q.rear=-1;
	do
	{
		printf("\n*---QUEUE MENU---*\n");
		printf("1.ENQUEUE\n2.DQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("enter your choice...\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the value to insert in a queue..\n");
				scanf("%d",&v);
				enqueue(&q,v);
				break;
			case 2:
				a=dequeue(&q);
				printf("the deleted element is %d",a);
				break;
			case 3:
				display(&q);
				break;
			case 4:
				exit(0);
			default:
				printf("INVALID CHOICE.....\n");
		}
	}while(1);
}
void enqueue(queue *q,int v)
{
	if(q->rear==size-1)
	{
		printf("value can't be inserted because...\n");
		printf("Queue is full\n");
		return;
	}
	if (q->rear==-1)
	{
		q->front=0;
	}
	q->rear++;
	q->q[q->rear]=v;
	printf("the inserted value is %d\n",v);
	printf("\n");
}
int dequeue(queue *q)
{
	int a;
	if(q->front==-1||q->front>q->rear)
	{
		printf("queue is empty...\n");
		return;
	}
	a=q->q[q->front];
	q->front++;
	if(q->front>q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	printf("\n");
	return a;
}
void display(queue *q)
{
	int i;
	if(q->front==-1||q->front > q->rear)
	{
		printf("queue is empty..\n");
		return;
	}
	printf("QUEUE :\n");
	for(i=q->front;i<=q->rear;i++)
		printf("%d\t",q->q[i]);
	printf("\n");
}
