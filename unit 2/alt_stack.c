// Alternate implementation of stack using array

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void push(int*, int*, int, int);
int pop(int*, int*);
void display(int*, int);
void peep(int*, int);

int main()
{
	int top,size,ch,k,key;
	int *st;
	printf("Enter the size of the stack : \n");
	scanf("%d", &size);
	st = (int*)malloc(sizeof(int)*size);
	top = -1;
	while(1)
	{
		display(st, top);
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Peep\n");
		printf("5. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the data : \n");
			scanf("%d", &key);
			push(st, &top, size, key);
			break;
			case 2: k = pop(st, &top);
			if(k>0)
				printf("Element popped : %d\n",k);
			break;
			case 3: display(st, top);
			break;
			case 4: peep(st, top);
			break;
			case 5: exit(0);
		}
	}
	return 0;
}

void push(int* st, int *t, int size, int key)
{
	if(*t==size-1)
		printf("Stack is full\n");
	else 
	{
		(*t)++;
		st[*t] = key;
	}
}

int pop(int* st, int *t)
{
	int key;
	if(*t==-1)
	{
		printf("Empty Stack\n");
		return -1;
	}
	key = st[*t];
	(*t)--;
	return key;
}

void display(int* st, int t)
{
	int i;
	if(t==-1)
		printf("Empty Stack\n");
	else 
	{
		for(i=t;i>-1;i--)
			printf("%d\n",st[i]);
	}
}

void peep(int* st, int t)
{
	if(t==-1)
		printf("Empty Stack\n");
	else
		printf("%d\n",st[t]);
}