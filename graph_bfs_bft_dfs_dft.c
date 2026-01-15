//shreya gupta - 236
// graph - bfs, bft, dfs, dft
#include<stdio.h>
#define max 10
typedef struct queue{
	int item[10];
	int front,rear;
}queue;

int visited[10];

int deleteq(queue *q)
{
	int x;
	if(q->rear < q->front)
		return 0;
	x = q->item[q->front++];
	return x;
}
void insertq(queue *q,int v)
{
	if(q->rear == max-1)
		return;
	q->item[++q->rear] = v;
}
int emptyq(queue q)
{
	return q.rear < q.front ? 1 : 0;
}
int fullq(queue q)
{
	return q.rear == max-1 ? 1 : 0;
}
void bfs(int g[10][10],int n ,int v)
{
	int w,x; 
	queue q;
	q.front = 0; 
	q.rear = -1;
	//for(int i=1; i<=n; i++)
	//	visited[i]=0;
	insertq(&q,v);
	visited[v] = 1;
	printf("%d",v);
	while(!emptyq(q))
	{
		v = deleteq(&q);
		for(w = 1;w<=n;w++)
		{
			if(g[v][w] ==1)
			{
				if(visited[w] ==0)
				{
					insertq(&q,w);
					printf("%d",w);
					visited[w] = 1;
				}
			}
		}
	}
}

void bft(int g[10][10],int n)
{
	int i;
	//for(i = 1;i<= n;i++)
	//	visited[i] =0;
	for(i = 1;i<=n;i++)
	{
		if(visited[i] ==0)
			bfs(g,n,i);
	}
}

void dfs(int g[10][10],int n, int v)
{
	int i;
	visited[v]=1;
	printf("%d",v);
	for(i=1; i<=n; i++)
	{
		if(g[v][i] == 1 && visited[i] == 0)
			dfs(g,n,i);
	}
}
void dft(int g[10][10], int n)
{
	int i,j;
	//for(i=1; i<=n ; i++)
	//	visited[i]= 0;
	for(j=1; j<=n; j++)
	{
		if(visited[j]==0)
			dfs(g,n,j);
	}
}
int main()
{
	int i,j,e,ch,v1,v2,nv;
	int g[10][10],ne,v;
	printf("\nEnter no. of vertices in graph\n");
	scanf("%d",&nv);
	for(i = 1;i<=nv;i++)
	{
		for(j =1;j<= nv;j++)
			g[i][j]=0;
	}
	printf("\nEnter no. of edges in the graph\n");
	scanf("%d",&ne);
	for(i = 1; i<= ne; i++)
	{
		printf("\nEnter the pair of vertices for edge e %d :",i);
		scanf("%d%d",&v1,&v2);
		g[v1][v2] = 1;
		g[v2][v1] = 1;
	}
	printf("\nMatrix representation of graph\n");
	for(i = 1;i<=nv;i++)
	{
		for(j =1;j<=nv;j++)
			printf("%d\t",g[i][j]);
		printf("\n");
	}
	//for(i = 1;i<=nv;i++)
	//	visited[i]=0;
	do
	{
		for(i=1; i<=10; i++)
			visited[i]=0;
		printf("\n----graph traversal menu----\n");
		printf("1.BFS\n2.BFT\n3.DFS\n4.DFT\n5.EXIT\n");
		printf("enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the starting vertex: ");
				scanf("%d",&v);
				bfs(g,nv,v);
				break;
			case 2:
				//printf("enter the starting vertex: ");
				//scanf("%d",&v);
				bft(g,nv);
				break;
			case 3:
				printf("enter the starting vertex: ");
				scanf("%d",&v);
				dfs(g,nv,v);
				break;
			case 4:
				//printf("enter the starting vertex: ");
				//scanf("%d",&v);
				dft(g,nv);
				break;
			case 5:
				printf("exiting the program....\n");
				break;
			default :
				printf("invalid choice....\n");			
		}
	}while(ch>=1 && ch<5);
	return 0;
}
