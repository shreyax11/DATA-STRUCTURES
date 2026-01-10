#include<stdio.h>
void prime(int num)
{
    int f,i;
    if(num==0||num==1)
    {
        printf("not prime");
    }
    else
    {
        for(i=2;i<num;i++)
        {
            if(num%i==0)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            printf("not a prime number");
        }
        else
        {
            printf("prime number");
        }
    }
}
int main()
{
    int num;
    printf("enter the number\n");
    scanf("%d",&num);
    printf("prime or not?\n");
    prime(num);
    return 0;
}
