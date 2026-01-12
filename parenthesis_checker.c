#include<stdio.h>
#define size 20
//#include<string.h>

typedef struct Stack
{
	int top;
	char a[size];
}stack;

int validparen(char a[size]);
void push(stack *s, char v);
void pop(stack *s);
char peek (stack s);

void main()
{
	char a[size];
	printf("Enter the expresion:");
	scanf("%s",a);
	if(validparen(a))
		printf("Valid expression");
	else
		printf("Invalid expression");
}

int validparen(char a[size])
{
	int i;
	stack s;
	s.top = -1;
	i = 0;
	while(a[i] != '\0')
	{
		if(a[i] == '(' || a[i] == '{' || a[i] == '[' )
			push(&s,a[i]);
			
		else if(a[i] == ')' || a[i] == '}' || a[i] == ']' )
		{
			if(s.top == -1)
				return 0;
				
			else if((a[i] == ')' && peek(s) == '(' ) || 
					(a[i] == '}' && peek(s) == '{' ) || 
					(a[i] == ']' && peek(s) == '[' ))
				pop(&s);
				
			else
				return 0;
		}
		i++;
	}
	if(s.top == -1)
		return 1;
	return 0;
}

void push(stack *s, char v)
{
	if (s->top==size-1)
	{
		printf("Stack is full\n");
		return;
	}
	s->a[++(s->top)]=v;
}

void pop(stack *s)
{
	char del;
	del=s->a[s->top--];
	return;
}

char peek (stack s)
{
	return s.a[s.top];
}
