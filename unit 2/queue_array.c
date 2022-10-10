#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
	int *q;
	int f,r,size;
}queue;

void insert(queue*, int);
int delete(queue*);
void display(queue*);
void init(queue*);

int main()
{
	queue q;
	int ch, k, key;
	init(&q);
	while(true)
	{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Pick a choice : \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value : \n");
			scanf("%d", &key);
			insert(&q,key);
			printf("Element inserted\n");
			break;
			case 2: k  = delete(&q);
			if(k>-1)
				printf("Element deleted : %d\n",k);
			break;
			case 3: display(&q);
			break;
			case 4: exit(0);
		}
	}
	return 0;
}

void init(queue* ptr_q)
{
	ptr_q->f = ptr_q->r = -1;
	printf("Enter the size of the queue : ");
	scanf("%d", &ptr_q->size);
	ptr_q->q = (int*)malloc(sizeof(int)*ptr_q->size);
}

void insert(queue* ptr_q, int data)
{
	// Check if the queue is full or not
	if(ptr_q->f==ptr_q->r==ptr_q->size-1)
		printf("Queue is full, cannot insert\n");
	// if first element
	if(ptr_q->f==-1)
		ptr_q->f = 0;
	// increment rear, queue obeys FIFO
	ptr_q->r++;
	ptr_q->q[ptr_q->r] = data;
}

int delete(queue* ptr_q)
{
	int x;
	// check if the queue is empty or not
	if(ptr_q->f==ptr_q->r==-1)
	{
		printf("Empty queue, cannot delete\n");
		return -1;
	}
	x = ptr_q->q[ptr_q->f]; // get the first element and store it in x
	// if there's only one element in the queue
	if(ptr_q->f==ptr_q->r)
		ptr_q->f=ptr_q->r=-1;
	else
		ptr_q->f++;
	return x;
}

void display(queue* ptr_q)
{
	int i;
	if(ptr_q->f==ptr_q->r==-1)
		printf("Empty queue\n");
	else 
	{
		for(i=ptr_q->f;i<=ptr_q->r;i++)
			printf("%d\n", ptr_q->q[i]);
	}
}