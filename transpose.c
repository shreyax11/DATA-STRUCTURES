#include<stdio.h>
int main()
{
    int a[100][100],b[100][100],c[100][100];
    int i,j,k;
    printf("enter the elements of the array\n");
    for(i=0;i<2;i++)
    { 
        for(j=0;j<2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("the array is \n......................\n");
    for(i=0;i<2;i++)
    { 
        for(j=0;j<2;j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
    printf("\ntranspose of the matrix \n..............\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t",a[j][i]);
        }
    }
    return 0;
}
