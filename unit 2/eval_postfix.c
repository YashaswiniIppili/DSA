#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int isoper(char ch)
{
	if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
		return true;
	else 
		return false;
}

int pop(int* s, int* top)
{
	int key;
	key = s[*top];
	(*top)--;
	return key;
}

void push(int* s, int* top, int data)
{
		++(*top);
		s[*top] = data;
}

int eval_postfix(char* postfix)
{
	int i=0,top,r;
	int s[100];
	top = -1;
	while(postfix[i]!='\0')
	{
		char ch = postfix[i];
		if(isoper(ch))  // returns true or false
		{
			int op1 = pop(s,&top);
			int op2 = pop(s,&top);
			switch(ch)
			{
				case '+': r = op1+op2;
				push(s,&top,r);
				break;
				case '-': r = op2-op1;
				push(s,&top,r);
				break;
				case '*': r = op1*op2;
				push(s,&top,r);
				break;
				case '/': r = op2/op1;
				push(s,&top,r);
				break;
			}
		}
		else
		{
			push(s,&top,ch-'0'); // convert char to int and push
		}
		i++;
	}
	return pop(s,&top);
}

int main()
{
	char postfix[100];
	printf("Enter the postfix expression to be evaluated : \n");
	scanf("%s", postfix);
	int k = eval_postfix(postfix);
	printf("Result : %d\n", k);
	return 0;
}