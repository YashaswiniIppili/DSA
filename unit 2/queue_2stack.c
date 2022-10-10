// Implementing queue using two stacks

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

int stack1[N];
int stack2[N];
int top1 = -1;
int top2 = -1;
int count = 0;

void push1(int data)
{
	if(top1==N-1)
		printf("Stack is full, cannot insert\n");
	else 
	{
		top1++;
		stack1[top1] = data;
	}
}

void push2(int data)
{
	if(top2==N-1)
		printf("Stack is full, cannot insert\n");
	else 
	{
		top2++;
		stack2[top2] = data;
	}
}

int pop1()
{
	return stack1[top1--];
}

int pop2()
{
	return stack2[top2--];
}

void display()
{
	int i;
	if(top1==-1)
		printf("Empty queue\n");
	else 
	{
		for(i = 0;i<=top1;i++)
			printf("%d->",stack1[i]);
		printf("\n");
	}
}

void enqueue()
{
    int data;
    if(top1 == N-1){
        printf("overflow\n");
    }
    else
    {
    printf("Enter the data: ");
    scanf("%d",&data);
    push1(data);
    count++;
    }
}

void dequeue()
{
    int i,a,b,x;
   if(top1 == -1)
   {
       printf("queue is empty\n");
   }
   else
   {
       	for(i = 0 ; i<count ; i++ )
       	{
           a = pop1();
           push2(a);
       	}
       	b = pop2();
       	printf("the dequeued element is : %d\n",b);
       	count--;
   		for(i = 0; i<count ; i++)
   		{
       		x = pop2();
       		push1(x);
   		}
   }
}

int main()
{
    int ch;
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    while(true)
    {
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                enqueue();
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("invalid choice\n");
            }
        }
    }
    return 0;
}