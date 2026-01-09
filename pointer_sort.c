#include<stdio.h>

void sort(int *a, int n)
{
    int temp,i,j;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {   
                if(*(a+j)>*(a+j+1))
                {
                    temp=*(a+j);
                    *(a+j)=*(a+j+1);
                    *(a+j+1)=temp;
                }
            }
        }
    
}
int main()
{
    int a[100];
    int i,n;
    printf("enter the no. of elements in array");
    scanf("%d",&n);
    printf("enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("the array is \n......................\n");
    for(i=0;i<n;i++)
    { 
        printf("%d",a[i]);
        printf("\t");
    }
    printf("\nsorting the array..............\n");
    sort(a,n);
    for(i=0;i<n;i++)
    { 
        printf("%d\t",a[i]);
    }
    return 0;
}
