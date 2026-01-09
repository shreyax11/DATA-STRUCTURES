#include<stdio.h>
void palindrome(int n)
{
    int rev,rem,on;
    rev=0;
    on=n;
    while(n>0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    if(on==rev)
    {
        printf("the number is palindrome ");
    }
    else
    {
        printf("not palindrome");
    }
}
int main()
{
    int num;
    printf("enter the number :");
    scanf("%d",&num);
    printf("checking wether the number is palindrome or not:");
    palindrome(num);
    return 0;
}
