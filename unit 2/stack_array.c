// Array implementation of Stack (Static Implementation)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack 
{
	int *s;
	int size;
	int top;
}stack;

void init_stack(stack* ptr_stk);
void push(stack* ptr_stk, int);
void pop(stack* ptr_stk);
void display(stack* ptr_stk);
void peek(stack* ptr_stk);

int main()
{
	stack stk;
	init_stack(&stk);
	display(&stk);
	int ch, data, k;
	while(true)
	{
		printf("1. Push an element onto the stack\n");
		printf("2. Display the elements of the stack\n");
		printf("3. Pop an element out of the stack\n");
		printf("4. Take a peek\n");
		printf("5. Exit\n");
		printf("Pick a choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be pushed onto the stack : \n");
			scanf("%d",&data);
			push(&stk, data);
			break;
			case 2: display(&stk);
			break;
			case 3: pop(&stk);
			break;
			case 4: peek(&stk);
			break;
			case 5: exit(0);
		}
	}
	return 0;
}

void init_stack(stack* ptr_stk)
{
	ptr_stk->top = -1;
	printf("Enter the size of the stack : ");
	scanf("%d", &ptr_stk->size);
	ptr_stk->s = (int*)malloc(sizeof(int)*ptr_stk->size);
}

void push(stack* ptr_stk, int data)
{
	// Check if the stack is full or not
	// Stack overflow
	if(ptr_stk->top == ptr_stk->size-1)
		printf("Stack is full, cannot insert\n");
	else 
	{
		++ptr_stk->top;
		ptr_stk->s[ptr_stk->top] = data;
	}
}

void display(stack* ptr_stk)
{
	if(ptr_stk->top == -1)
		printf("Empty stack\n");
	else 
	{
		for(int i=ptr_stk->top;i>-1;i--) // beacause stack follows LIFO, you need to pop the last element added first
			printf("%d\n",ptr_stk->s[i]);
	}
}

void pop(stack* ptr_stk)
{
	int k;
	if(ptr_stk->top == -1)
		printf("No elements to pop\n");
	else
	{
		k = ptr_stk->s[ptr_stk->top];
		ptr_stk->top--;
	}
	printf("%d\n",k);
}

void peek(stack* ptr_stk)
{
	if(ptr_stk->top==-1)
		printf("Empty stack\n");
	else 
		printf("%d\n", ptr_stk->s[ptr_stk->top]);
}