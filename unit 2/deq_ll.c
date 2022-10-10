// dequeue can be used as a palindrome checker, mostly used in multiprocessor scheduling

#include <stdlib.h>
#include <stdio.h>

typedef struct node 
{
	int data;
	struct node* next;
	struct node* prev;
}node;

typedef struct dequeue 
{
	node* front;
	node* rear;
}dequeue;

void init(dequeue*);
void display(dequeue*);
void inserthead(dequeue*,int);
void inserttail(dequeue*, int);
int deletehead(dequeue*);
int deletetail(dequeue*);

int main()
{
	int k,ch,x;
	dequeue dq;
	init(&dq);
	while(1)
	{
		printf("1. Insert head\n");
		printf("2. Insert tail\n");
		printf("3. Delete head\n");
		printf("4. Delete tail\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value : ");
					scanf("%d",&x);
					inserthead(&dq,x);
					break;
			case 2: printf("Enter the value : ");
					scanf("%d",&x);
					inserttail(&dq,x);
					break;
			case 3: k = deletehead(&dq);
					if(k>-1)
						printf("Element deleted : %d\n",k);
					break;
			case 4: k = deletetail(&dq);
					if(k>-1)
						printf("Element deleted : %d\n",k);
					break;
			case 5: display(&dq);
					break;
			case 6: exit(0);
		}
	}
	return 0;
}

void init(dequeue* p)
{
	p->front=p->rear=NULL;
}

void inserthead(dequeue* p, int data)
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data=data;
	temp->prev = temp->next = NULL;
	// for first node
	if(p->front==NULL)
		p->front = p->rear = temp;
	else
	{
		temp->next = p->front;
		p->front->prev = temp;
		p->front = temp;
	}
}

void inserttail(dequeue* p, int data)
{
	node * temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->prev = temp->next = NULL;
	// for first node
	if(p->front==NULL)
		p->front = p->rear = temp;
	else 
	{
		p->rear->next = temp;
		temp->prev = p->rear;
		p->rear = temp;
	}
}

int deletehead(dequeue* p)
{
	node* pres;
	int key;
	pres = p->front; // copy the address of the node that front is pointing to
	key = pres->data;
	// if only one node
	if(p->front==p->rear)
		p->front = p->rear = NULL;
	else
	{
		p->front=pres->next;
		p->front->prev = NULL;
	}
	free(pres);
	return key;
}

int deletetail(dequeue* p)
{
	node* pres;
	int key;
	pres = p->rear;
	key = pres->data;
	if(p->front==p->rear)
		p->front=p->rear=NULL;
	else
	{
		p->rear=pres->prev;
		p->rear->next=NULL;
	}
	free(pres);
	return key;
}

void display(dequeue* p)
{
	node* pres;
	// check if the queue is empty or not
	if(p->front==NULL)
		printf("Empty dequeue\n");
	else
	{
		pres = p->front;
		while(pres!=p->rear)
		{
			printf("%d->",pres->data);
			pres = pres->next;
		}
		printf("%d\n",pres->data);
	}
}
