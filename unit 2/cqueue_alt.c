#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Why we need circular queues ? 
// In linear queues when you fill up a queue with all values and then start popping the values and then plan to store some values again it would still say queue is full because queue is only the part between the front and the rear pointer so this is wastage of memory which is a major drawback of linear queues.

void insert(int*, int*,int*, int, int);
int delete(int*, int*, int*, int);
void display(int*, int, int, int);

int main()
{
	int *q;
	int ch, k, key;
	int f,r,size;
	f=r=-1;
	printf("Enter the size of the array : \n");
	scanf("%d",&size);
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
			scanf("%d", &key);
			insert(q,&f,&r,size,key);
			printf("Element inserted\n");
			break;
			case 2: k  = delete(q,&f,&r,size);
			if(k>-1)
				printf("Element deleted : %d\n",k);
			break;
			case 3: display(q,f,r,size);
			break;
			case 4: exit(0);
		}
	}
	return 0;
}

void insert(int *q, int *f, int *r, int size, int x)
{
	if((*r+1)%size==*f)
		printf("Queue is full, cannot insert\n");
	*r = (*r+1)%size;
	q[*r]=x; 
	if(*f==-1) // when you insert in the front and you need to change front to the new element now.
		f=0;
}

int delete(int *q, int *f, int *r, int size)
{
	int x;
	if(*f==*r==-1)
	{
		printf("Empty queue\n");
		return -1;
	}
	x = q[*f];
	if(*f==*r) // only one element
		*f = *r = -1;
	else 
		*f = (*f+1)%size;
	return x;
}

void display(int *q, int f, int r, int size)
{
	if(f==r==-1)
		printf("Empty queue\n");
	else 
	{
		while(f!=r)
		{
			printf("%d->", q[f]);
			f = (f+1)%size;
		}
		printf("%d \n", q[f]); // to print the last element
	}
}