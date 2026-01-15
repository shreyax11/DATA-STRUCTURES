#include<stdio.h>
#define INF 999

void spanningTree(int n, int cost[10][10])
{
    int visited[10] = {0};
    int i, j, min, u, v;
    int edges = 0, totalCost = 0;

    visited[1] = 1;   // start from vertex 1

    printf("\nEdges selected for Spanning Tree:\n");

    while(edges < n - 1)
    {
        min = INF;

        for(i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                for(j = 1; j <= n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -- %d  cost = %d\n", u, v, min);
        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum cost of Spanning Tree = %d\n", totalCost);
}

int main()
{
    int n, i, j, cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    spanningTree(n, cost);
    return 0;
}
