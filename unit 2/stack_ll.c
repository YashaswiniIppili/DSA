// Implementationn of Stacks using Linked Lists or Dynamic Implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int key;
	struct node *link;  // self-referencing structure
}node;

typedef struct stack 
{
	node* top;
}stack;

void init(stack*);
void push(stack*, int);
int pop(stack*);
void display(stack*);
void peep(stack*);

int main()
{
	stack st;
	int ch, key, k;
	init(&st);
	while(1)
	{
		display(&st);
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Peep\n");
		printf("5. Exit\n");
		printf("Enter a choice : \n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the element : ");
			scanf("%d", &key);
			push(&st,key);
			break;
			case 2: k = pop(&st);
			if(k>0)
				printf("Popped element : %d\n", k);
			break;
			case 3: display(&st);
			break;
			case 4: peep(&st);
			break;
			case 5: exit(0);
		}
	}
	return 0;
}

void init(stack* ptr_stk)
{
	ptr_stk->top = NULL;
}

void push(stack* ptr_stk, int key)
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->key = key;
	temp->link = NULL;

	temp->link = ptr_stk->top;
	ptr_stk->top = temp;
}

int pop(stack* ptr_stk)
{
	node* pres;
	int key;
	if(ptr_stk->top==NULL)
	{
		printf("Empty Stack\n");
		return -1;
	}
	else 
	{
		pres=ptr_stk->top;  // copy the address of the first node
		key = pres->key;  // store the data part of the first node because you have to follow LIFO
		ptr_stk->top = pres->link; // you need to point top to the next node and that link is stored in pres->link
		free(pres); // then you free pres
		return key;  // pop the element
	}
}

void display(stack* ptr_stk)
{
	int i;
	node *pres;
	if(ptr_stk->top==NULL)
		printf("Empty stack\n");
	else
	{
		pres = ptr_stk->top; // copy the address of the first node pointed by top
		while(pres!=NULL)
		{
			printf("%d->", pres->key);
			pres=pres->link;
		}
	}
}

void peep(stack* ptr_stk)
{
	if(ptr_stk->top==NULL)
		printf("Empty stack\n");
	else 
	{
		node* pres;
		pres = ptr_stk->top;
		printf("%d \n", pres->key);
	}
}
