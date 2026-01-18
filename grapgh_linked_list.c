// Shreya 236
// Graph using linked list - BFS, BFT, DFS, DFT

#include<stdio.h>
#include<stdlib.h>

typedef struct nodetype
{
    int info;
    struct nodetype *next;
} node;

typedef struct queuetype
{
    int item[10];
    int front, rear;
} Queue;

int visited[11];

// Create new node
node *getnode()
{
    node *nn = (node*)malloc(sizeof(node));
    nn->next = NULL;
    return nn;
}

// Create adjacency list
node *create_list(node *head, int k)
{
    node *p = head, *r;
    int v;
    printf("Enter %d adjacent vertices:\n", k);
    while(k--)
    {
        scanf("%d", &v);
        r = getnode();
        r->info = v;
        p->next = r;
        p = r;
    }
    return head;
}

// Display graph
void display_graph(node *head[10], int n)
{
    int i;
    node *p;
    printf("\nAdjacency List Representation:\n");
    for(i=1;i<=n;i++)
    {
        printf("Vertex %d -> ", i);
        p = head[i]->next;
        while(p)
        {
            printf("%d -> ", p->info);
            p = p->next;
        }
        printf("NULL\n");
    }
}

// Queue functions
int empty(Queue q)
{
    return (q.front > q.rear);
}

void insertq(Queue *q, int x)
{
    if(q->rear == 9)
    {
        printf("Queue Full\n");
        return;
    }
    q->item[++q->rear] = x;
}

int deleteq(Queue *q)
{
    if(empty(*q))
        return -1;
    return q->item[q->front++];
}

// BFS
void bfs(node *head[10], int v)
{
    Queue q;
    node *p;
    q.front = 0;
    q.rear = -1;

    visited[v] = 1;
    printf("%d ", v);
    insertq(&q, v);

    while(!empty(q))
    {
        v = deleteq(&q);
        p = head[v]->next;

        while(p)
        {
            if(!visited[p->info])
            {
                visited[p->info] = 1;
                printf("%d ", p->info);
                insertq(&q, p->info);
            }
            p = p->next;
        }
    }
}

// BFT
void bft(node *head[10], int n)
{
    for(int i=1;i<=n;i++)
        if(!visited[i])
            bfs(head, i);
}

// DFS
void dfs(node *head[10], int v)
{
    node *p;
    visited[v] = 1;
    printf("%d ", v);

    p = head[v]->next;
    while(p)
    {
        if(!visited[p->info])
            dfs(head, p->info);
        p = p->next;
    }
}

// DFT
void dft(node *head[10], int n)
{
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(head, i);
}

int main()
{
    int n, i, k, ch, v;
    node *head[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(i=1;i<=n;i++)
    {
        head[i] = getnode();
        head[i]->info = i;
        printf("Enter number of vertices adjacent to %d: ", i);
        scanf("%d", &k);
        create_list(head[i], k);
    }

    display_graph(head, n);

    do
    {
        for(i=1;i<=n;i++)
            visited[i] = 0;

        printf("\n--- GRAPH TRAVERSAL MENU ---\n");
        printf("1. BFS\n2. BFT\n3. DFS\n4. DFT\n5. EXIT\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter starting vertex: ");
                scanf("%d", &v);
                bfs(head, v);
                break;

            case 2:
                bft(head, n);
                break;

            case 3:
                printf("Enter starting vertex: ");
                scanf("%d", &v);
                dfs(head, v);
                break;

            case 4:
                dft(head, n);
                break;
        }
        printf("\n");

    } while(ch != 5);

    return 0;
}
