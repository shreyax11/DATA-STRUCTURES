//shreya gupta - 236
//simple union, find
#include<stdio.h>

int p[20];

void simple_union(int i, int j)
{
	p[i]=j;
}
int find(int i)
{
	int j;
	j=i;
	while(p[j]>0)
		j=p[j];
	return j;
}
void display(int n)
{
	int i;
	printf("\nParent:\t\t");
	for(i=1; i<=n; i++)
		printf("%d\t",p[i]);
	printf("\nElememts:\t");
	for(i=1; i<=n; i++)
		printf("%d\t",i);
}
int main()
{
	int i,j,f,root,ch,n;
	//int element[20];
	for(int i=1; i<=20; i++)
		p[i]=-1;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	//printf("Enter the elements:\n");
	//for(i=1; i<=n; i++)
	//	scanf("%d",&element[i]);
	display(n);
	do
	{
		printf("\n----MENU----\n");
		printf("1.SIMPLE UNION\n2.SIMPLE FIND\n3.EXIT\n");
		printf("ENTER YOUR CHOICE:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nENTER THE ROOT OF FIRST AND SECOND SET RESPECTIVELY: ");
				scanf("%d %d",&i,&j);
				if(i != j && p[i] == -1 && p[j] == -1)
				{	simple_union(i,j);
					display(n);
				}
				else
					printf("Union is not possible\n");
				break;
			case 2:
				printf("\nENTER THE NUMBER TO FIND: ");
				scanf("%d",&f);
				root = find(f);
				printf("\n%d is in the set whose root is %d ",f,root);
				display(n);
				break;
			case 3:
				printf("\nExiting the program....\n");
				break;
			default:
				printf("Invalid choice...\nTRY AGAIN..\n");
		}
	}while(ch>=1 && ch<4);
	return 0;
}
