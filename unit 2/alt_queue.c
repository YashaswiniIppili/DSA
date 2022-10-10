#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insert(int, int*, int*, int*, int);
int delete(int*, int*, int*);
void display(int*, int, int);

int main()
{
	int *q;
	int ch,k,key;
	int f,r,size;
	f=r=-1;
	printf("Enter the size of the queue : \n");
	scanf("%d, &size");

	q = (int*)malloc(sizeof(int)*size);
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
			insert(key, q, &f, &r, size);
			break;
			case 2: k = delete(q, &f, &r);
			if(k>-1)
				printf("Element is deleted : %d\n",k);
			break;
			case 3: display(q, f, r);
			break;
			case 4: exit(0);
		}
	}
	return 0;
}

void insert(int data, int* q, int* f, int* r, int size)
{
	// check if the queue is full or not
	if(*r==size-1)
		printf("Queue is full, cannot insert\n");
	(*r)++;
	q[*r] = data;
	// check if it's the first element or not
	if(*f==-1)
		*f=0;
}

int delete(int* q, int* f, int* r)
{
	int key;
	// check if the queue is empty or not
	if(*f==*r==-1)
		printf("Empty queue\n");
	key = q[*f];
	// check if there's only one element
	if(*f==*r)
		*f=*r=-1;
	else
		(*f)++; // increment front to traverse throughout
	return key;
}

void display(int *q, int f, int r)
{
	int i;
	if(f==r==-1)
		printf("Empty queue\n");
	else
	{
		for(i=f;i<=r;i++)
			printf("%d ",q[i]);
	}
	printf("\n");
}