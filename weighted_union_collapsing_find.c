#include <stdio.h>

// Shreya Gupta - 236
// Weighted Union and Collapsing Find

int p[20];

void weighted_union(int i, int j)
{
    int temp;
    temp = p[i] + p[j];

    if (p[i] > p[j])   // j has larger tree
    {
        p[i] = j;
        p[j] = temp;
    }
    else               // i has larger tree
    {
        p[j] = i;
        p[i] = temp;
    }
}

int collapsing_find(int x)
{
    int root = x, temp;

    while (p[root] > 0)
        root = p[root];

    while (x != root)
    {
        temp = p[x];
        p[x] = root;
        x = temp;
    }
    return root;
}

void display(int n)
{
    int i;
    printf("\nParent:\t\t");
    for (i = 1; i <= n; i++)
        printf("%d\t", p[i]);

    printf("\nElements:\t");
    for (i = 1; i <= n; i++)
        printf("%d\t", i);
}

int main()
{
    int i, j, ch, n, root;

    for (i = 1; i <= 20; i++)
        p[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    display(n);

    do
    {
        printf("\n\n----MENU----");
        printf("\n1. Weighted Union");
        printf("\n2. Collapsing Find");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter two roots: ");
                scanf("%d%d", &i, &j);

                if (p[i] < 0 && p[j] < 0)
                {
                    weighted_union(i, j);
                    display(n);
                }
                else
                    printf("Union not possible (not roots)");
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &i);
                root = collapsing_find(i);
                printf("Root of %d is %d", i, root);
                break;

            case 3:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice!");
        }
    } while (ch != 3);

    return 0;
}
