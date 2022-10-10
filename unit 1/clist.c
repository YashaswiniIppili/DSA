//program to implement circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	 struct node *link;
};

typedef struct node node_t;

//last : pointer to last node
struct list
{
	node_t *last;
};

typedef struct list clist_t;

void init_list(clist_t *);
void insert_front(clist_t *, int);
void insert_end(clist_t*,int);
void delete_node(clist_t*, int);
void display(clist_t*);

int main()
{
	int ch,key,pos;
	clist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.Delete a node");
		printf("\n5..Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_front(&l,key);
						 break;
			case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_end(&l,key);
						 break;			 
			case 3:display(&l);
			             break;
			 
			case 4:printf("\nEnter the key...");
			             scanf("%d",&key);
						 delete_node(&l,key);	
                         break;	
					   
			case 5:exit(0);
		}
	}
}

void init_list(clist_t * ptr_list)
{
	ptr_list->last=NULL;
}

void insert_front(clist_t *ptr_list, int key)
{
	  node_t *temp,*last;
	//create node and populate
	
		temp=(node_t*)malloc(sizeof(node_t));	
        temp->key=key;
		temp->link=temp;
	
	    last =ptr_list->last;  //get the address the last node;
		
		if(last==NULL) //first node
		 ptr_list->last=temp;
		else
		{
			temp->link=last->link; 
			last->link=temp;
		}
}
			
	void insert_end(clist_t *ptr_list, int key)
{
	  node_t *temp,*last;
	  
	//create node and populate
	
		temp=(node_t*)malloc(sizeof(node_t));	
        temp->key=key;
		temp->link=temp;
	
	    last =ptr_list->last;  		
	  
	     if(last==NULL)  // if empty list
			 ptr_list->last=temp; // first node
		 else
		 {
			temp->link=last->link;  // link after the last node
			last->link=temp; 
			ptr_list->last=temp; // make last point to new last node
		}
			 
}		 
			 
	  void display(clist_t* ptr_list)
	  {
		  node_t *pres, *last,*prev;
		  if(ptr_list->last==NULL)
			  printf("Empty List\n");
		  else
		  {
			  last=ptr_list->last; //copy last nodes address
			  pres=last->link; // point to the first node
			  
			  while(pres!=last)
			  {
				  printf("%d ->",pres->key);
			     pres=pres->link;
			  }
			   printf("%d ",pres->key); // print the last node
		  }
	  }
	 void delete_node(clist_t* ptr_list, int  key)
	 {
		 
		 node_t *last,*pres,*prev;
		 last=ptr_list->last; //copy addres of the last node
		 pres=last->link; //point to the first node
		 prev=last;
		 
		 
		 while((pres->key!=key)&&(pres!=last))
		 {
			 prev=pres;
			 pres=pres->link;
		 }
		 if(pres->key==key)
		 {
			 //if only one node ?
			 if(pres->link==pres)
				 ptr_list->last=NULL;
			 else 
			 {
				 prev->link=pres->link;  // link the previous node to next node
				 if(pres==last)// if deleting last node
				   ptr_list->last=prev; // change last
			 }
            free(pres);
		 }
       else
           printf("key not found..\n");
	 }	   
		