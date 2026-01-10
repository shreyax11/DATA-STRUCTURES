#include <stdio.h>

void selectionSort(int arr[], int n, int index)
{
    int min = index;
    if (index == n - 1)
        return;
    for (int i = index + 1; i < n; i++)
    {
        if (arr[i] < arr[min])
            min = i;
    }
    if (min != index)
    {
        int temp = arr[index];
        arr[index] = arr[min];
        arr[min] = temp;
    }
    selectionSort(arr, n, index + 1);
}

int main()
{
    int n;
    printf("How many elements do you want to enter? ");
    scanf("%d", &n);
    int arr[n];   
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    selectionSort(arr, n, 0);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
