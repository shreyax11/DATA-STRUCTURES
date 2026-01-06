#include<stdio.h>
void fact(int n)
{
    int i,fact;
    fact=1;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    printf("the factorial is %d",fact);
}
int main()
{
    int num;
    printf("enter the number:");
    scanf("%d",&num);
    fact(num);
    return 0;
}
