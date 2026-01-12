#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 10
typedef struct stack{
	int top;
	int oprdst[size];
}stack;
void push(stack *s,int v)
{
	if(s->top==size-1)
	{
		printf("stack is full...\n");
		return;
	}
	s->oprdst[++s->top]=v;
}
int pop(stack *s)
{
	int b;
	if(s->top==-1)
	{
		printf("stack is empty..\n");
		return;
	}
	b=s->oprdst[s->top];
	s->top--;
	return b;
}
int compute(int l,int r,char opt)
{
	switch(opt)
	{
		case '*':
			return (l*r);
		case '+':
			return (l+r);
		case '/':
			return (l/r);
		case '-':
			return (l-r);
		default:
			printf("invalid");
	}
}
int posteval(char postexp[size])
{
	stack s;
	s.top=-1;
	int i,leftoprd,rightoprd,result;
	i=0;
	while(postexp[i] != '\0')
	{
		if(isdigit(postexp[i]))
		{
			push(&s,postexp[i]-48);
		}
		else
		{
			rightoprd=pop(&s);
			leftoprd=pop(&s);
			result=compute(leftoprd, rightoprd, postexp[i]);
			push(&s,result);
		}
		i++;
	}
	return pop(&s);
}
void main()
{
	char postexp[size];
	int result;
	printf("enter the valid postfix expression :\n");
	scanf("%s",postexp);
	result=posteval(postexp);
	printf("the evaluated value is %d \n", result);
}
