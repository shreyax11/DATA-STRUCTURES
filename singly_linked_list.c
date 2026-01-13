#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node* createnode(int v);
node* sortedlist(node *start);
void displaylist(node *start);
node* deletelist(node *start);
node* reverselist(node *start);
void main()
{
	node* start = NULL;
	int ch;
	do
	{
		printf("\n_____MENU_____\n");
		printf("1.INSERTION\n");
		printf("2.DELETION\n3.TRAVERSING\n4.REVERSE\n");
		printf("5.Exit\n");
		printf("enter the choice....");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				start=sortedlist(start);
				break;
			case 2:
				start=deletelist(start);
				break;
			case 3:
				displaylist(start);
				break;
			case 4:
				reverselist(start);
				break;
			case 5:
				exit(0);
			default:
				printf("invalid choice...\n");
		}
	}while(1);
}
node* createnode(int v)
{
	node *nn;
	nn=(node *)malloc(sizeof(node));
	if(nn==NULL)
	{
		printf("ERROR:memory is not allocated..\n");
		return nn;
	}
	nn->data=v;
	nn->next=NULL;
	return nn;
}
node *sortedlist(node *start)
{
	char ch;
	int v;
	node *nn,*p;
	do
	{
		printf("enter the value to insert:\t");
		scanf("%d",&v);
		nn=createnode(v);
		if(start==NULL)
			start=nn;
		else if(start->data > nn->data)
		{
			nn->next=start;
			start=nn;
		}
		else
		{
			p=start;
			while(p->next != NULL && p->next->data <= nn->data)
			{
				p=p->next;
			}
			nn->next=p->next;
			p->next=nn;
		}
		printf("do you want to add more?\n (Y or y / N or n) :");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	return start;
}
node* deletelist(node *start)
{
	node *p;
	node *temp;
	int target;
	printf("enter the element to delete :");
	scanf("%d",&target);
	if(start==NULL)
	{
		printf("list is empty..\n");
		return start;
	}
	else if(start->data == target)
	{
		temp=start;
		start=start->next;
		free(temp);
	}
	p=start;
	while(p->next != NULL && p->next->data != target)
	{
		p=p->next;
	}
	
	if(p->next != NULL)
	{
		temp=p->next;
		p->next=p->next->next;
		free(temp);
	}
	else
		printf("target value in not found..\n");
	return start;
}
void displaylist(node *start)
{
	node *p;
	if(start==NULL)
	{
		printf("list is empty..\n");
		return;
	}
	p=start;
	while(p != NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
}
node* reverselist(node *start)
{
	node *p=NULL;
	node *c=start;
	node *nn;
	while(c!=NULL)
	{
		nn=c->next;
		c->next=p;
		p=c;
		c=nn;
	}
	return p;
}
