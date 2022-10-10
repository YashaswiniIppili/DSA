#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;
  struct node *link;
}node;

typedef struct list
{
	node* head;
}list;

void init_list(list*);
void insert_order(list*,int);
void display(list *);
  
int main()
{
	 list l;
	 init_list(&l);
	 int x;
	 display(&l);
	 while(1)
		{
			printf("Enter the element : \n");
			scanf("%d",&x);
	    if(x==0)
			break;
			insert_order(&l, x);
			printf("\n");
			display(&l);
		}		
}

void init_list(ptr_list *ptr_list)
{
	ptr_list->head=NULL;
}
	  
void  insert_order(ptr_list *ptr_list, int x)
{
		  node *pres, *prev, *temp;
		  
		  temp= (node*)malloc(sizeof(node));
		  temp->key=x;
		  temp->link=NULL;
		  
		  prev=NULL;
		  pres=ptr_list->head;
		  //move forward until you find position or go beyond the list 
		  while((pres!=NULL)&&(x>pres->key))
		  {
		    prev=pres;
			 	pres=pres->link;
		  }
		  if(pres!=NULL) //position found
		  {
			  if(prev==NULL)//first position, inserting smallest no.
			  {
		      ptr_list->head=temp;
				  temp->link=pres;
		    }
		  	else //prev not null, insert somewhere in middle 
		  	{
			  	temp->link=pres;
			  	prev->link=temp;
		  	}
			}
			else //pres is NULL	
			{
				if(prev==NULL) //inserting first no.
			    ptr_list->head=temp;
		   	else	
			  	prev->link=temp; // insert at end, largest no.
	    }  
}		  
			  
void display(ptr_list *ptr_list)
{
	node *pres;
  //is list empty ?
	if(ptr_list->head==NULL)
		  printf("\nEmpty list.\n");
	else
	{
		//copy the address of the first node
		pres=ptr_list->head;
		while(pres!=NULL)
		{
			printf("%d-->",pres->key);
			pres=pres->link;
		}
	}
}		  
