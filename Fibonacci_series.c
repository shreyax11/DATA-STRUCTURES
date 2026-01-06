#include<stdio.h>
int fib(int n);
int main()
{
    int i,n;
    printf("enter the number:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("%d\t",fib(i));
    }
    return 0;
}
int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
    return fib(n-1)+fib(n-2);
    }
}
