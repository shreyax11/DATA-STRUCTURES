#include<stdio.h>
int n_sum(int num)
{
    if(num==1)
    {
        return 1;
    }
    return num+n_sum(num-1);
}
int main()
{
    int num,a;
    printf("enter the num");
    scanf("%d",&num);
    printf("sum of the series id \n");
    a=n_sum(num);
    printf("%d",a);
    return 0;
}
