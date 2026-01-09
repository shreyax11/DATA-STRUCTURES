#include<stdio.h>
void perfect(int num)
{
    int sum,i;
    sum=0;
    for(i=1;i<num;i++)
    {
        if(num%i==0)
        {
            sum=sum+i;
        }
    }
    if(sum==num)
    {
        printf("perfect number");
    }
    else
    {
        printf("not perfect number");
    }
}
int main()
{
    int num;
    printf("enter a number");
    scanf("%d",&num);
    printf("checking perfect number or not\n");
    perfect(num);
    return 0;
}
