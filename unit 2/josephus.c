// Implementation of Josephus Problem

#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
	int *cq;
	int f,r,size;
}queue;

void init(queue*);
void insert(queue*, int);
int delete(queue*);
int isempty(queue*);
int josephus(queue*);

int main()
{
	int ch, k, n, i, result;
	queue q;
	init(&q);
	printf("Enter the number of people : \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		insert(&q,i);
	result = josephus(&q);
	printf("The survivor is %d\n", result);
	return 0;
}

void init(queue* q)
{
	printf("Enter the size of the queue : \n");
	scanf("%d",&q->size);
	q->f = q->r = -1;
	q->cq = (int*)malloc(sizeof(int)*q->size);
}

void insert(queue* q, int key)
{
	q->r = (q->r+1)%q->size; // increment rear
	q->cq[q->r] = key; // insert the element
	if(q->f==-1) // first element
		q->f=0;
}

int delete(queue* q)
{
	int key;
	key = q->cq[q->f];
	// if only one element
	if(q->f==q->r)
		q->f = q->r = -1;
	else
		q->f  = (q->f+1)%q->size;
	return key;
}

int isempty(queue* q)
{
	//check if the queue is empty or not
	if(q->f==-1)
		return 1;
	return 0;
}

int josephus(queue* q)
{
	int k;
	while(!isempty(q))
	{
		k=delete(q);
		insert(q,k);
		k=delete(q);  // delete alternate person
	}
	return k;
}