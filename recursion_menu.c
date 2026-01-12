#include<stdio.h>
#include<string.h>
#define size 10
int sum(int);
long factorial(int);
void rev(char str[size], int l);
int sumfib(int n);
void printfib(int n);
void toh(int n,char from_rod,char to_rod,char aux_rod);
void main()
{
	char str[size];
	int n,s,ch,l;
	long f;
	do
	{	
		printf("\n_____MENU_____\n");
		printf("1.sum of n numbers\n");
		printf("2.factorial\n3.reverse of a string\n4.sum of fibonacci series\n5.fibonacci series\n6.tower of hanoi");
		printf("\n7.Exit\n");
		printf("enter the choice....");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter a number:");
				scanf("%d", &n);
				s=sum(n);
				printf("the sum is: %d", s);
				printf("\n");
				break;
			case 2:
				printf("Enter a number:");
				scanf("%ld", &n);
				f=factorial(n);
				printf("the factorial is: %ld", f);
				printf("\n");
				break;
			case 3:
				printf("Enter a string:");
				scanf("%s", str);
				l = strlen(str);
				rev(str,l);
				printf("\n");
				break;
			case 4:
				printf("enter a number:");
				scanf("%d",&n);
				printf("the sum of fibonacci series is : %d",sumfib(n));
				printf("\n");
				break;
			case 5:
				printf("enter a number:");
				scanf("%d",&n);
				printf("the fibonacci series is :\n");
				printfib(n);
				printf("\n");
				break;
			case 6:
				printf("enter the disks:");
				scanf("%d",&n);
				toh(n,'a','b','c');
				printf("\n");
				break;
			case 7:
				exit(0);
			default:
				printf("INVALID CHOICE");	
		}
	}while(1);
}
int sum (int n)
{
	int s;
	if(n == 0)
		return 0;
	s = n + sum(n-1);
	return s;
}
long factorial(int n)
{
	long f;
	if(n == 1)
		return 1;
	f = n * factorial(n-1);
	return f;
}
void rev(char str[size], int l)
{
	if(l<0)
		return;
	printf("%c",str[l-1]);
	rev(str,l-1);
}
int sumfib(int n)
{
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	return 1 + sumfib(n-1) + sumfib(n-2);
}
void printfib(int n)
{
	static int m1=0,m2=1,m3;
	if(m1==0)
		printf("%d %d",m1,m2);
	if(n>0)
	{
		m3=m1+m2;
		m1=m2;
		m2=m3;
		printf("%d ",m3);
		printfib(n-1);
	}
}
void toh(int n,char from_rod,char to_rod,char aux_rod)
{
	if(n==1)
	{
		printf("\n move disk 1 from rod %c to rod %c",from_rod,to_rod);
		return;
	}
	toh(n-1,from_rod,aux_rod,to_rod);
	printf("\n move disk %d from rod %c to rod %c",n,from_rod,to_rod);
	toh(n-1,aux_rod,to_rod,from_rod);
}
