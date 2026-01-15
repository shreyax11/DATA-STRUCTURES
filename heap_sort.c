//shreya gupta - 236
//max heap sort
#include <stdio.h>
#define MAX 10
void max_heapify(int a[], int i, int n)
{
	int largest,l,r,temp;
    largest = i;
    l = 2*i + 1;
    r = 2*i + 2;
    if (l<n && a[l]>a[largest])
        largest = l;
    if (r<n && a[r]>a[largest])
        largest = r;
    if (largest != i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(a, largest, n);
    }
}
void create_max_heap(int a[], int n)
{
	int i;
    for (i = n/2-1; i>=0; i--)
        max_heapify(a, i, n);
}
void heap_sort(int a[],int n)
{
	int i,temp;
	create_max_heap(a,n);
	for(i=n-1; i>=1; i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[0]=temp;
		max_heapify(a,1,i-1);
	}
}
int main()
{
	int n,i;
	int a[MAX];
	printf("\n--- MAX HEAP SORT ---\n");
	printf("ENTER NO. OF ELEMENT TO INSERT:\n");
	scanf("%d",&n);
	printf("ENTER THE %d ELEMENTS:\n",n);
	for (i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("THE ORIGINAL ARRAY IS:\n");
    for (i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\nTHE SORTED ARRAY IS:\n");
    heap_sort(a,n);
    for (i=0; i<n; i++)
        printf("%d ",a[i]);
}
