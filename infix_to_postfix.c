#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define size 10

typedef struct Stack
{
    int top;
    int arr[size];
}stack;

//evalutation
int posteval(char postexp[size]);
int compute(int l,int r,char opt);

//conversion
void intopost(char infix[size],char postfix[size]);
int precedence(char opt);
int isRightAssociative(char op);

void push(stack *s,char v);
char pop(stack *s);
char peek(stack s);
int isempty(stack s);
int isfull(stack s);

void main()
{
    char postexp[size],infix[size];
    int ch,a;

    do{
        printf("\n* - - M E N U - - *\n");
        printf("1.Infix to Postfix\n2.Evaluation\n3.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the valid infix expression:\n");
                scanf("%s",infix);
                intopost(infix,postexp);
                printf("The postfix expression is:\n%s",postexp);
                break;

            case 2:
                printf("Enter the valid postfix expression:\n");
                scanf("%s",postexp);
                a = posteval(postexp);
                printf("The answer is: %d",a);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice");
        }

    }while(1);
}

//evaluation
int posteval(char postexp[size])
{
    stack s;
    s.top = -1;
    int i=0,leftoprd,rightoprd,result;

    while(postexp[i] != '\0')
    {
        if(isdigit(postexp[i]))
            push(&s, postexp[i] - 48);
        else
        {
            rightoprd = pop(&s);
            leftoprd  = pop(&s);
            result = compute(leftoprd, rightoprd, postexp[i]);
            push(&s, result);
        }
        i++;
    }
    return pop(&s);
}
int compute(int l,int r,char opt)
{
    switch(opt)
    {
        case '*': return l*r;
        case '+': return l+r;
        case '-': return l-r;
        case '/': return l/r;
        case '^': return l^r;
        default : return -1;
    }
}



//conversion
void intopost(char infix[size],char postfix[size])
{
    int i=0,j=0;
    char c;
    stack s;
    s.top = -1;

    while(infix[i] != '\0')
    {
        c = infix[i];
        if(isdigit(c))
            postfix[j++] = c;
        else if(c == '(')
            push(&s, c);
        else if(c == ')')
        {
            while(!isempty(s) && peek(s) != '(')
                postfix[j++] = pop(&s);
            pop(&s); // remove '('
        }
        else   // operator
        {
            while(!isempty(s) && precedence(peek(s)) > 0)
            {
                if( (isRightAssociative(c) && precedence(c) < precedence(peek(s))) ||
                    (!isRightAssociative(c) && precedence(c) <= precedence(peek(s))) )
                {
                    postfix[j++] = pop(&s);
                }
                else break;
            }
            push(&s, c);
        }
        i++;
    }
    while(!isempty(s))
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}
int isRightAssociative(char op)
{
    return op == '^'; // ^ is right associative
}
int precedence(char ch)
{
    switch(ch)
    {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        case '(':
            return 0;
        default:
            return -1;
    }
}
void push(stack *s, char v)
{
    if(isfull(*s))
    {
        printf("Stack is full");
        return;
    }
    s->arr[++s->top] = v;
}
char pop(stack *s)
{
    if(isempty(*s))
    {
        printf("Stack is empty");
        return '\0';
    }
    return s->arr[s->top--];
}
char peek(stack s)
{
    if(isempty(s))
    {
        return '\0';
    }
    return s.arr[s.top];
}
int isempty(stack s)
{
    return s.top == -1;
}
int isfull(stack s)
{
    return s.top == size - 1;
}
