#include <stdio.h>
#include <ctype.h>

typedef struct stack
{
	char s[100];
	int top;
}stack;

void init(stack* ptr_stk)
{
	ptr_stk->top = -1;
}

void push(stack* ptr_stk, int data)
{
	ptr_stk->top++;
	ptr_stk->s[ptr_stk->top] = data; // else you could do ptr_stk->s[++ptr_stk->top] = data;
}

int pop(stack* ptr_stk)
{
	int key = ptr_stk->s[ptr_stk->top];
	ptr_stk->top--;
	return key;
}

int peep(stack* ptr_stk)
{
	int key = ptr_stk->s[ptr_stk->top];
	return key;
}

int precedence(char p, char q)
{
	switch(q)
	{
		case '+':
		case '-': if(p=='(')
						return 0;
					return 1;
		case '*':
		case '/': if(p=='('||st=='+'||st=='-')
						return 0;
					return 1;
		case '(': return 0;
		case ')': if(st=='(')
						return 0;
						return 1;
	}
}

void infixToPostfix(char* infix,char *postfix)
{
	STACK s;
	initStack(&s);
	char dummy;
	int k=0;
	for(int i=0;infix[i]!='\0';i++)
	{
		if(isdigit(infix[i]))
			postfix[k++]=infix[i];
		else
		{
			while(!isEmpty(&s) && prcd(stackTop(&s),infix[i]))
				postfix[k++]=pop(&s);
			if(infix[i]==')')
				dummy=pop(&s);
			else
				push(&s,infix[i]);
				
		}
	}
	while(!isEmpty(&s))
		postfix[k++]=pop(&s);
	postfix[k]='\0';
}

int main()
{
	char infix[100];
	char postfix[100];
	printf("Enter a valid infix exprssion : \n");
	scanf("%s", infix);
	infixtopostfix(infix, postfix);
	printf("%s\n", postfix);
	return 0;
}
