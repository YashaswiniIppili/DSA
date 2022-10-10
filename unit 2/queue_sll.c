#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
	int data;
	struct node* link;
}node;

typedef struct queue
{
	node* front;
	node* rear;
}queue;

void insert(int, queue*);
int delete(queue*);
void display(queue*);

int main()
{
	int k, ch, key;
	queue q;
	q.front = q.rear = NULL;
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
			insert(key, &q);
			break;
			case 2: k = delete(&q);
			if(k>-1)
				printf("Element deleted is %d\n",k);
			break;
			case 3: display(&q);
			break;
			case 4: exit(0);
		}
	}
	return 0;
}

void insert(int key, queue* ptr_q)
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = key;
	temp->link = NULL;
	// check if it's the first element
	if(ptr_q->front==NULL)
		ptr_q->front = ptr_q->rear = temp;
	else
	{
		ptr_q->rear->link = temp;
		ptr_q->rear = temp;
	}
}

int delete(queue* ptr_q)
{
	int x;
	node* pres;
	pres = ptr_q->front;
	// check if queue is empty or not
	if(ptr_q->front==NULL)
	{
		printf("Empty queue\n");
		return -1;
	}
	x = pres->data;
	// if there's only one node
	if(ptr_q->front==ptr_q->rear)
		ptr_q->front=ptr_q->rear=NULL; // when there's only one node you have to point them to NULL.
	else
		ptr_q->front = pres->link; // point front to next node
	free(pres);
	return x;
}

void display(queue* ptr_q)
{
	node* pres;
	pres = ptr_q->front;
	if(pres==NULL)
		printf("Empty queue\n");
	else
	{
		while(pres!=ptr_q->rear)
		{
			printf("%d->", pres->data);
			pres = pres->link;
		}
		printf("%d\n", pres->data); // to print the data of the last node
	}
}