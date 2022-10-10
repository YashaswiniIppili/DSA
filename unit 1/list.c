#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;

struct list
{
	node_t *head;
};
typedef struct list list_t;
void init_list(list_t*);
void delete_node(list_t *, int);	
void insert_head(list_t *, int);
void insert_end(list_t*,int);
void insert_pos(list_t *, int,int);
void display(list_t *);
void delete_pos(list_t *, int);	
int count_node(list_t *);
int count_node_recur(node_t*);
void print_reverse(list_t*);
void print_reverse_recur(node_t*);
//void delete_alternate(list_t *);

int main()
{
   list_t l;
   init_list(&l);
    int n,ch,pos;
   while(1)
   {
	   display(&l);
	   printf("\n1..Insert at head\n");
	   printf("2..Insert at end\n");
	   printf("3..display\n");
	   printf("4..Insert at a given position\n");
	   printf("5..Delete  node given its value\n");
	   printf("6..Delete  node given its position\n");
	   printf("7..count number of nodes-recursion\n");
	   printf("8..print the list in reverse\n");
	   printf("9..exit\n");
	   scanf("%d",&ch);
	   switch(ch)
	   {
		   case 1: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						 insert_head(&l,n);
						 break;
			case 2: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						 insert_end(&l,n);
						 break;			 
			case 3: display(&l);
			              break;
						  
			case 4: printf("\nEnter the element and position ..");
						  scanf("%d %d",&n,&pos);
						  insert_pos(&l,n,pos);	
                          break;		
          case 5: printf("\nEnter the element to be deleted ..");
						scanf("%d",&n);
						  delete_node(&l,n);	
                          break;			
           case 6: printf("\nEnter the position of node ..");
						scanf("%d",&pos);
						  delete_pos(&l,pos);	
                          break;		
           case 7: printf("Count the no of nodes using recurion");
                        int k= count_node(&l);
						printf("\nthe number of nodes = %d\n",k);
                         break;		
             case 8: printf("print the list in reverse");
                        print_reverse(&l);
						
                         break;						 
			case 9:exit(0);
	   }
   }
}

    void print_reverse(list_t *ptr_list)
	{
		print_reverse_recur(ptr_list->head);
	}
	
	
	void print_reverse_recur(node_t *pres)
	{
		if(pres->link!=NULL)
			print_reverse_recur(pres->link);
		printf("%d -> ",pres->key);
	}
		
		
int count_node(list_t *ptr_list)
 {
	 int count=0;
	 count=count_node_recur(ptr_list->head);
	 return count;
 }
 
 int  count_node_recur(node_t *pres)
 {
	 int count=0;
	if(pres->link==NULL)//only one node
      return 1;
    count=1+count_node_recur(pres->link);
	return count;
 }
	  
	 
	 
 
	 
	 

  void delete_node(list_t *ptr_list, int data)
  {
	  node_t *pres, *prev;
	  prev=NULL;
	  pres=ptr_list->head;
	  
	  //move forward until the node is found
	  //or you go beyond the list
	  while((pres!=NULL)&&(pres->key!=data))
	  {
	     prev=pres;
		 pres=pres->link;
	  }
	  if(pres!=NULL) //node  found
	  {
		  //if first node
		  if(prev==NULL) //it is the first node
			  ptr_list->head=pres->link;
			else
		      prev->link=pres->link;
	  }
	else
		printf("Node not found..\n");
	free(pres);
  }
 		    
   void insert_pos(list_t *ptr_list, int data, int pos)
   {
	   node_t *pres, *temp, *prev;
	   int i;
		//create node and populate
		temp=(node_t*)malloc(sizeof(node_t));	
        temp->key=data;
		temp->link=NULL;
		
		i=1;
		prev=NULL;
		pres=ptr_list->head;
		//go to the desired position
		while((pres!=NULL) &&(i<pos))
		{
			i++;
			printf("i=%d\n",i);
			prev=pres;
			pres=pres->link;
		}
		if(pres!=NULL) //position is found some where between the first and last
		{
		   if(prev==NULL) //inserting in postion 1
		   {
			ptr_list->head=temp;
			temp->link=pres;
		}
		else//prev is not NULL, inserting node in the middle
		{
			temp->link=pres;
			prev->link=temp;
		 }
		}
		else // pres NULL
		{
			if(i==pos)//insert at the end
			  prev->link=temp;
			else
				printf("\nInvalid position..");
		}
   }
			  
   
    void insert_end(list_t *ptr_list, int data)
	{
		node_t *pres, *temp;
		//create node and populate
		temp=(node_t*)malloc(sizeof(node_t));	
        temp->key=data;
		temp->link=NULL;
		
		//is the list empty?
		
		if(ptr_list->head==NULL)
			ptr_list->head=temp;
		else
		{
			 //list not empty, go to end of list
			pres=ptr_list->head; //copy address of the first node
			while(pres->link!=NULL)
			    pres=pres->link;
			
			pres->link=temp;
		}
	}
				
		
     void display(list_t *ptr_list)
	 {
		 node_t *pres;
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
				
	void insert_head(list_t *ptr_list, int data)
	{	
	    node_t *temp;
		temp=(node_t*)malloc(sizeof(node_t));	
        temp->key=data;
		temp->link=NULL;
		
		//is list empty ?
		if(ptr_list->head==NULL)
			ptr_list->head=temp;
		else
		{
			temp->link=ptr_list->head;
			ptr_list->head=temp;
		}
	}
					   
void init_list(list_t *ptr_list)
{
    ptr_list->head=NULL;
}
	
 

  void delete_pos(list_t *ptr_list, int pos)
  {
	  
	  node_t *pres, *prev;
	  pres=ptr_list->head;
	  prev=NULL;
	  
	  int i =1;
	  //move forward until the postion is found
	  while((pres!=NULL)&&(i<pos))
	  {
		  i++;
		  prev=pres;
		  pres=pres->link;
	  }
	
     if(pres!=NULL)//position found
     {
         //if first position
		 if(prev==NULL)
			 ptr_list->head=pres->link; //make head point to second node
		else // not the first node
           	prev->link=pres->link;
        free(pres);
     }
   else
	   printf("Invalid Position..\n");
  }
	 
			 

		 
	  
	  
	  

