#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
	int data;
	struct node* link;
}node;

typedef struct cqueue
{
	node* front;
	node* rear;
}cq;

void insert(int key, cq* ptr_q)
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = key;
	temp->link = NULL;
	// check if it's the first element
	if(ptr_q->front==NULL)
	{
		ptr_q->front = ptr_q->rear = temp;
		ptr_q->rear->link =ptr_q->front;
	}
	// when you already have nodes in the list
	else
	{
		ptr_q->rear->link = temp; // you point the existing rear node to the new node because in a queue you add elements from the end
		ptr_q->rear = temp; // you now assign the last node to be the rear node, point rear to the new last node
		ptr_q->rear->link =ptr_q->front; // since this is circular the last node should now contain the address of the first node
	}
}

int delete(cq* ptr_q)
{
	node* pres;
	pres = ptr_q->front;
	// check if the queue is empty or not
	if(ptr_q->front==NULL)
		printf("Empty queue\n");
	// if there's only one node
	else if(pres==ptr_q->rear)
	{
		ptr_q->front=ptr_q->rear= NULL;
		free(pres);
	}
	// if there is more than one node in the list
	else
	{
		ptr_q->front=pres->link;
		ptr_q->rear->link = ptr_q->front;
		free(pres);
	}
}

void peek(cq* ptr_q)
{
	if(ptr_q->front==NULL)
		printf("Empty queue\n");
	else
	{
		printf("%d\n",ptr_q->front->data);
	}
}

void display(cq* ptr_q)
{
	node* pres;
	pres = ptr_q->front;
	if(ptr_q->front==NULL)
			printf("Empty queue\n");
	else 
	{
		while(pres->link!=ptr_q->front)
		{
			printf("%d->",pres->data);
			pres=pres->link;
		}
		printf("%d\n", pres->data);
	}
}

int main()
{
	int k, ch, key;
	cq q;
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