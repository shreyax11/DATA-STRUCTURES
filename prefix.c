//question 4 1infix to prefix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
typedef struct 
{
    char data[SIZE];
    int top;
} CharStack;
typedef struct 
{
    int top;
    int operandstack[SIZE];
} IntStack;

void pushChar(CharStack *s, char c) 
{ 
    s->data[++(s->top)] = c; 
    
}

char popChar(CharStack *s) 
{ 
    return s->data[(s->top)--]; 
    
}

char peekChar(CharStack *s) 
{ 
    return s->data[s->top]; 
    
}

int isCharEmpty(CharStack *s) 
{ 
    return s->top == -1; 
    
}

void pushInt(IntStack *s, int v) 
{
    if (s->top == SIZE - 1) {
        printf("Stack full\n");
        return;
    }
    s->operandstack[++(s->top)] = v;
}

int popInt(IntStack *s) 
{
    if (s->top == -1) {
        printf("Stack empty\n");
        exit(1);
    }
    return s->operandstack[(s->top)--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Reverse string and swap brackets
void reverse(char str[]) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++) 
    {
        if (str[i] == '(') 
            str[i] = ')';
        else if (str[i] == ')') 
            str[i] = '(';
    }
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) 
{
    CharStack s;
    s.top = -1;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) 
    {
        char c = infix[i];
        if (isalnum(c)) 
        {
            postfix[j++] = c;
        } 
        else if (c == '(') 
        {
            pushChar(&s, c);
        } 
        else if (c == ')') 
        {
            while (!isCharEmpty(&s) && peekChar(&s) != '(') 
            {
                postfix[j++] = popChar(&s);
            }
            popChar(&s);
        } 
        else 
        {
            while (!isCharEmpty(&s) && precedence(peekChar(&s)) >= precedence(c)) 
            {
                postfix[j++] = popChar(&s);
            }
            pushChar(&s, c);
        }
    }
    while (!isCharEmpty(&s)) 
    {
        postfix[j++] = popChar(&s);
    }
    postfix[j] = '\0';
}

// Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) 
{
    char revInfix[SIZE], postfix[SIZE];
    strcpy(revInfix, infix);
    reverse(revInfix);
    infixToPostfix(revInfix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Compute
int compute(int l, int r, char opt) 
{
    switch (opt) 
    {
        case '*': return l * r;
        case '+': return l + r;
        case '-': return l - r;
        case '/': return l / r;
        case '^': {
            int res = 1;
            for (int i = 0; i < r; i++) res *= l;
            return res;
        }
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

// Prefix evaluation
int preeval(char preexp[SIZE]) 
{
    IntStack s;
    s.top = -1;
    int len = strlen(preexp);
    for (int i = len - 1; i >= 0; i--)
    {
        if (isdigit(preexp[i])) 
        {
            pushInt(&s, preexp[i] - '0');
        } 
        else 
        {
            int left = popInt(&s);
            int right = popInt(&s);
            int result = compute(left, right, preexp[i]);
            pushInt(&s, result);
        }
    }
    return popInt(&s);
}

void main() 
{
    char infix[SIZE], prefix[SIZE];
    int choice;

    do{
        printf("\n--- MENU ---\n");
        printf("1. Convert Infix to Prefix\n");
        printf("2. Evaluate Prefix Expression\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPrefix(infix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;

            case 2:
                printf("Enter prefix expression (single digit operands): ");
                scanf("%s", prefix);
                printf("Result: %d\n", preeval(prefix));
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }while(1);
}
