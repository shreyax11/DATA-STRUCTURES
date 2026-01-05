#include<stdio.h>
void armstrong(int n)
{
    int rem,sum,on;
    on=n;
    sum=0;
    while(n>0)
    {
        rem=n%10;
        sum=sum+(rem*rem*rem);
        n=n/10;
    }
    if (sum==on)
    {
        printf("armstrong number");
    }
    else
    {
        printf("not armstrong number");
    }
}
int main()
{
    int num;
    printf("enter the number :");
    scanf("%d",&num);
    printf("checking entered number is armstrong or not:\n");
    armstrong(num);
    return 0;
}
