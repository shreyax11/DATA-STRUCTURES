#include<stdio.h>
int main()
{
    int a[100][100];
    int i,j,f;
    printf("enter the elements of the array\n");
    for(i=0;i<3;i++)
    { 
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("the array is \n......................\n");
    for(i=0;i<3;i++)
    { 
        for(j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
    printf("\nchecking identity matrix \n..............\n");
    f=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if((i==j&& a[i][j]!=1 )|| (i!=j &&a[i][j]!=0))
            {
                f=-1;
            }
        }
    }
    if(f==-1)
    {
        printf("not");
    }
    else
    {
        printf("identity matrix");
    }
    return 0;
}
