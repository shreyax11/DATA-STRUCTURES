
#include<stdio.h>

int main()
{
    int a[100][100],b[100][100],c[100][100];
    int i,j,k;
    printf("enter the elements of 1st array\n");
    for(i=0;i<2;i++)
    { 
        for(j=0;j<2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the elements of 2nd array\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("multiplying the both arrays\n..............\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=0;
            for(k=0;k<2;k++)
            {
                c[i][j]=a[i][k]*b[k][j]+c[i][j];
            }
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d",c[i][j]);
            printf("\t");
        }
    }
    return 0;
}
