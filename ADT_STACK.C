#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}node;
node* createnode(int v);
node* push(node* top,int v);
node* pop(node* top);
void peek(node* top);
void display(node* top);

node* createnode(int v)
{
	node* nn;
	nn=(node*)malloc(sizeof(node));
	if(nn==NULL)
	{
		printf("ERROR:memory is not allocated..\n");
		return nn;
	}
	nn->data=v;
	nn->next=NULL;
	return nn;
}
node* push(node* top,int v)
{
	node *nn;
	nn=createnode(v);
	if(top==NULL)
	{
		top=nn;
	}
	else
	{
		nn->next=top;
		top=nn;	
	}
	return top;
}
node* pop(node* top)
{
	int v;
	node *temp;
	if(top==NULL)
	{
		printf("Stack is empty..\n");
		return top;
	}
	v=top->data;
	printf("the deleted element is %d",v);
	temp=top;
	top=top->next;
	free(temp);
	return top;
}
void peek(node* top)
{
	int v;
	if(top==NULL)
	{
		printf("stack is empty..\n");
		return;
	}
	v=top->data;
	printf("the peek value is %d",v);
}
void display(node* top)
{
	node* p;
	if(top==NULL)
	{
		printf("stack is empty..\n");
		return;
	}
	p=top;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void main()
{
	int v,ch;
	node *top=NULL;
	do{
		printf("\n*--dynamic stack--*\n");
		printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
		printf("enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the value:");
				scanf("%d",&v);
				top=push(top,v);
				break;
				top=pop(top);
				break;
			case 3:
				peek(top);
				break;
			case 4:
				display(top);
				break;
			case 5:
				exit(0);
			deafult:
				printf("invalid choice");
		}
	}while(1);
}



