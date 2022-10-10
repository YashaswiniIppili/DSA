//implementation of doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  struct node *next;
  struct node *prev;
};
  
  typedef struct node node_t;
  
  struct dlist
  {
	  node_t* head;
  };
  
  typedef struct dlist dlist_t;
  
  void init_list(dlist_t*);
  void insert_head(dlist_t*,int);
  void display(dlist_t*);
  void insert_tail(dlist_t*,int);
  void delete_first(dlist_t*);
  void delete_last(dlist_t *);
  void delete_node(dlist_t*, int);
  void delete_pos(dlist_t*,int);
  void insert_pos(dlist_t*,int,int);
  void insert_after(dlist_t*, int, int);
  void insert_before(dlist_t*, int, int);
   
   int main()
{
	int ch,key,pos,value;
	dlist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.delete first node");
		printf("\n5. Delete Last Node..");
		printf("\n6 .Delete a node given value");
		printf("\n7.Delete at a position");
		printf("\n8.Insert at a Given Position");
		printf("\n9. Insert after given value..\n");
		printf("\n10. Insert before given value..\n");
		printf("\n11.Exit");
		
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_head(&l,key);
						 break;
		case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_tail(&l,key);
						 break;			 
		   case 3:display(&l);
			             break;
		  case 4:delete_first(&l);
              			break;		
			case 5:delete_last(&l);
              			break;				
		 /*  case 6:printf("\nEnter the key...");
			             scanf("%d",&key);
						 delete_node(&l,key);	
                         break;	
		  case 7:printf("\nEnter the position");
			             scanf("%d" ,&pos);
						 delete_pos(&l,pos);
						 break;	
			case 8:printf("\nEnter the key and position");
			             scanf("%d %d" ,&key,&pos);
						 insert_pos(&l,key,pos);
						 break;
			case 9:printf("\nEnter the value and key");
			             scanf("%d %d" ,&value,&key);
						 insert_after(&l,value,key);
						 break;		 
			case 10:printf("\nEnter the value and key");
			             scanf("%d %d" ,&value,&key);
						 insert_before(&l,value,key);
						 break;	*/		 
			case 11:exit(0);
		}
	}
}

  void init_list(dlist_t *ptr_list)
  {
	  ptr_list->head=NULL;
  }
   
  void insert_head( dlist_t *ptr_list,int key)
	{
		
		//create node
		node_t *temp;
		
		temp=(node_t*)malloc(sizeof(node_t));
		temp->key = key;
		temp->next=temp->prev=NULL;
		
	  //if first node ?                                                  
	  if(ptr_list->head==NULL)
		  ptr_list->head=temp;
	  
	  else
	  {
		  
		  temp->next=ptr_list->head;
		  ptr_list->head->prev=temp;
		  ptr_list->head=temp;
	  }
	}
	
	void display(dlist_t *ptr_list )
	{
		node_t *pres;
		pres=ptr_list->head;
		
		if(pres==NULL)
			printf("\nEmpty List..\n");
		else
		{
			while(pres!=NULL)
			{
				printf("%d<->",pres->key);
				pres=pres->next;
			}
		}
	  printf("\n");
	}
				
		 void insert_tail(dlist_t *ptr_list,int key)
		 {
			//create node
		node_t *temp, *pres;
		
		temp=(node_t*)malloc(sizeof(node_t));
		temp->key = key;
		temp->next=temp->prev=NULL;
		
		// if first node
		 if(ptr_list->head==NULL)
		  ptr_list->head=temp;
        else
		{
            pres=ptr_list->head;
			//go to last node
			while(pres->next!=NULL)
				pres=pres->next;
			
			pres->next=temp;
			temp->prev=pres;
		}
		 }			

			
		void delete_first(dlist_t *ptr_list)
		{
			node_t *pres;
			
			pres=ptr_list->head;
			
			if(pres->next==NULL) // only one node 
			   ptr_list->head=NULL;
			else
			{
                  pres->next->prev=NULL;
				  ptr_list->head=pres->next;
			}
			free(pres);
		}
				  
			void delete_last(dlist_t *ptr_list)
		  {
			node_t *pres;
			
			pres=ptr_list->head;	  
				
            if(pres->next==NULL) // only one node 
			   ptr_list->head=NULL;
			 else
			 {
				  //go to last node
				 while(pres->next!=NULL)
					 pres=pres->next;
				 
				 pres->prev->next=NULL;
			 }
			 free(pres);
		}
	
 void delete_node(dlist_t* ptr_list, int key)
 {
	 
	 node_t *pres;
	 
	 pres=ptr_list->head;
	 
	 //find the node
	 while(pres!=NULL) &&(pres->key!=key))
		 pres=pres->next;
	if(pres!=NULL) // node found
	{
		//where ?
		//if only one node
		
		if((pres->next== NULL)&&(pres->prev==NULL))
		    ptr_list->head=NULL;
		else if (pres->prev==NULL) //first node
		{
			pres->next->prev=NULL;
			ptr_list->head=pres-next;
		}
	
	
	
	
	
		
		
		
		
		





		
			
			
		