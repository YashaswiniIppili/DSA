// Implementation of priority queue using arrays

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element
{
	int prty;
	int data;
}element;

void insert(element*, int, int, int*);
element delete(element*, int*);  // returning a structure from a function, return type and argument both of type structure
void display(element*, int);

int main()
{
	int k, ch, prty, x;
	element pq[100], temp;
	int count = 0;
	while(true)
	{
		printf("1. Insert\n2. Delete\n3. Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the priority : ");
					scanf("%d", &prty);
					printf("Enter the data : ");
					scanf("%d",&x);
					insert(pq,x,prty,&count);
					break;
			case 2: temp = delete(pq, &count);
			if(temp.data>0)
			{
				printf("Deleted element : %d\n", temp.data);
				printf("Priority : %d\n", temp.prty);
			}
			break;
			case 3: display(pq, count);
			break;
			case 4: exit(0);
		}
	}
}

void insert(element* pq, int x, int prty, int *count)
{
	int j;
	element temp;
	temp.data = x;
	temp.prty = prty;
	j = *count -1;
	while((j>0)&&(pq[j].prty>temp.prty))
	{
		pq[j+1] = pq[j];
		j--;
	}
	pq[j+1] = temp;
	(*count)++;
}

element delete(element* pq, int* count)
{
	int i;
	element temp;
	// check if empty queue
	if((*count)==0)
	{
		printf("Empty queue\n");
		temp.data = -1;
		temp.prty = -1;
	}
	else
	{
		temp = pq[0]; // get the first element
		for(i=1;i<*count;i++) // shift the elements
			pq[i-1] = pq[i];
	}
	(*count)--;
	return temp;
}

void display(element* pq, int count)
{
	int i;
	if(count==0)
		printf("Empty queue\n");
	else 
	{
		for(i=0;i<count;i++)
			printf("Value = %d, Priority = %d\n",pq[i].data, pq[i].prty);
	}
}
