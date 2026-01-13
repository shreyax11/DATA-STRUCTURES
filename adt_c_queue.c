#include<stdio.h>
#include<stdlib.h>
#define size 3
typedef struct CQueue{
	int queue[size];
	int front;
	int rear;
}queue;

int isfull(queue *q)
{
	return((q->rear+1)%size==(q->front));
}

int isempty(queue *q)
{
	return q->front==-1;
}

void enqueue(queue *q , int value)
{
	if(isfull(q))
	{
		printf("queue is full..\n");
		return;
	}
	if(isempty(q))
	{
		q->front=q->rear=0;
	}
	else
	{
		q->rear=((q->rear+1)%size);
	}
	q->queue[q->rear]=value;
	printf("the value is inserted...\n");
}

void dequeue(queue *q)
{
	int delete;
	if(isempty(q))
	{
		printf("queue is empty..\n");
		return;
	}
	delete=q->queue[q->front];
	if(q->front==q->rear)
	{
		q->rear=q->front=-1;
	}
	else
	{
		q->front==((q->front++)%size);	
	}
	printf("the deleted element is %d \n",delete);
}

void display(queue *q)
{
	int i;
	if(isempty(q))
	{
		printf("queue is empty..\n");
		return;
	}
	printf("queue elements are:\n");
	i=q->front;
	do
	{
		printf("%d\t", q->queue[i]);
		i=((i+1)%size);
	}while(i!=(q->rear+1)%size);
	printf("\n");
}

void main()
{
	queue q;
	q.front=-1;
	q.rear=-1;
	
	int ch,value;
	do
	{
		printf("*---CIRCULAR QUEUE MENY---*\n");
		printf("1.ENQUEUE\n2.DQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("enter your choice...\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the value to insert in a queue..\n");
				scanf("%d",&value);
				enqueue(&q,value);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				display(&q);
				break;
			case 4:
				printf("exiting from the program...\n");
				exit(0);
			default:
				printf("INVALID CHOICE.....\n");
		}
	}while(1);
}
