// Circular queue using linked lists

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
	int *cq;
	int f,r,size;
}queue;

void init(queue*);
void insert(queue*, int);
int delete(queue*);
void display(queue*);
int isempty(queue*);

int main()
{
	int ch,k,key;
	queue cq;
	init(&cq);
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
			scanf("%d",&key);
			insert(&cq, key);
			break;
			case 2: k = delete(&cq);
			if(k>-1)
				printf("Element deleted : %d\n",k);
			break;
			case 3: display(&cq);
			break;
			case 4: exit(0);
		}
	}
	return 0;
}

void init(queue* ptr_q)
{
	printf("Enter the size of the queue : \n");
	scanf("%d", &ptr_q->size);
	ptr_q->cq = (int*)malloc(sizeof(int)*ptr_q->size);
	ptr_q->f=ptr_q->r=-1;
}

void insert(queue* ptr_q, int data)
{
	// check if the queue is full or not
	if((ptr_q->r+1)%ptr_q->size == ptr_q->f)
		printf("Circular queue is full, cannot insert\n");
	// increment rear pointer
	ptr_q->r=(ptr_q->r+1)%ptr_q->size;
	ptr_q->cq[ptr_q->r] = data;
	// to insert first element
	if(ptr_q->f==-1)
		ptr_q->f=0;
}

int isempty(queue* ptr_q)
{
	if(ptr_q->f==-1)
		return 1;
	return 0;
}

int delete(queue* ptr_q)
{
	int x;
	if(isempty(ptr_q))
	{
		printf("Empty queue\n");
		return -1;
	}
	x = ptr_q->cq[ptr_q->f];
	// if only one element
	if(ptr_q->r==ptr_q->f)
		ptr_q->r=ptr_q->f=-1;
	else
		ptr_q->f=(ptr_q->f+1)%ptr_q->size;
	return x;
}

void display(queue* ptr_q)
{
	int i,f,r,size;
	f = ptr_q->f; 
	r=ptr_q->r;
	size = ptr_q->size;
	if(isempty(ptr_q))
		printf("Empty queue\n");
	else
	{
		for(i=f;i!=r;i=(i+1)%size)
			printf("%d->",ptr_q->cq[i]);
	}
	printf("%d\n",ptr_q->cq[i]);
}