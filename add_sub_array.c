#include<stdio.h>

int main()
{
    int a[100],b[100],c[200];
    int na,nb,i,j;
    printf("enter the number of elements in 1st 1D array:\t");
    scanf("%d",&na);
    printf("enter the number of elements in 2nd 1D array:\t");
    scanf("%d",&nb);
    printf("enter the elements of 1st array\n");
    for(i=0;i<na;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the elements of 2nd array\n");
    for(j=0;j<nb;j++)
    {
        scanf("%d",&b[j]);
    }
    printf("adding the both arrays\n..............\n");
    for(i=0;i<na;i++)
    {
        c[i]=a[i]+b[i];
    }
    for(i=0;i<na;i++)
    {
        printf("%d",c[i]);
        printf("\n");
    }
    printf("subtracting the both arrays\n..............\n");
    for(i=0;i<na;i++)
    {
        c[i]=a[i]-b[i];
    }
    for(i=0;i<na;i++)
    {
        printf("%d",c[i]);
        printf("\n");
    }

    return 0;
}
