#include <stdio.h>
#define MAX 10
void max_heapify(int a[], int i, int n)
{
    int largest, l, r,temp;
    largest = i;
    l = 2*i + 1;
    r = 2*i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }
}
void create_max_heap(int a[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        max_heapify(a, i, n);
}
void insert_into_max_heap(int a[], int *n, int value)
{
    int i;
    if (*n == MAX)
    {
        printf("Heap is full\n");
        return;
    }
    i = *n;
    (*n)++;
    while (i > 0 && a[(i - 1) / 2] < value)
    {
        a[i] = a[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    a[i] = value;
}
void delete_root(int a[], int *n)
{
    int x;
    if (*n == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    x = a[0];
    a[0] = a[*n - 1];
    (*n)--;
    max_heapify(a, 0, *n);
    printf("Deleted element: %d\n", x);
}
void display(int a[], int n)
{
    if (n == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int heap[MAX];
    int n = 0, ch;
    do
    {
        printf("\n--- MAX HEAP MENU ---\n");
        printf("1.Insert\n2.Delete Root\n3.Display\n4.Create Max Heap\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            {
                int k, value;
                printf("How many values to insert: ");
                scanf("%d", &k);
                printf("Enter %d values: ", k);
                for (int i = 0; i < k; i++)
                {
                    scanf("%d", &value);
                    insert_into_max_heap(heap, &n, value);
                }
                break;
            }
            case 2:
                delete_root(heap, &n);
                break;
            case 3:
                display(heap, n);
                break;
            case 4:
                create_max_heap(heap, n);
                printf("Max Heap created\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 5);
    return 0;
}
