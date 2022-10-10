//program to implement circular doubly linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next,*prev;
};

typedef struct node node_t;
struct dlist
{
	node_t *head;
};

typedef struct dlist dlist_t;

void insert_head(dlist_t*,int);
void insert_tail(dlist_t*,int); 
void delete_node(dlist_t*,int);
void display(dlist_t*);
void init_list(dlist_t*);

int main()
{
  int ch,x,pos;
  
  dlist_t dl;
  
  init_list(&dl);

  while(1)
  { 
    display(&dl);
    printf("\n1..Insert Head\n");
    printf("2..Insert Tail\n");
    printf("3..Delete a Node..\n");
    printf("4..Display\n");
    printf("5..Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("Enter the number...");
            scanf("%d",&x);
            insert_head(&dl,x);
            break;
     case 2:printf("Enter the number...");
            scanf("%d",&x);
            insert_tail(&dl,x);
            break;
    case 3: printf("Enter the value of the node to be deleted...");
            scanf("%d",&x);
            delete_node(&dl,x);
            break;
   
     case 4:display(&dl);
            break;
     case 5:exit(0);
   }
 }
}

void init_list(dlist_t* ptr_list)
{
	ptr_list->head=NULL;
}

void delete_node(dlist_t *ptr_list,int x)
 {
  node_t *pres,*prev;

  pres=ptr_list->head;//copy of the first node
 
 //move till you find the node
 //or you reach the last node
  while((pres->next!=ptr_list->head)&&(pres->data!=x))
        pres=pres->next;
	 
  if(pres->data==x)//node found
  {
      if(pres->next==pres)//only one node
        ptr_list->head=NULL; // make head NULL
      else
        {
					
            if(pres==ptr_list->head) //first node
                ptr_list->head=pres->next; //make head point to next node		
            pres->prev->next=pres->next; 
	         pres->next->prev=pres->prev;
		  
        }
       free(pres);                             
   }
   else
     printf("Node not found..\n");
 }
        
 void insert_head(dlist_t *ptr_list,int x)
 {
    node_t *temp,*pres;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp->prev=temp;

     pres=ptr_list->head;
    if(pres==NULL)
      ptr_list->head=temp;
    else
     {
	   pres->prev->next=temp;
	   temp->prev=pres->prev;
        temp->next=pres;
        pres->prev=temp;
	    ptr_list->head=temp;
     }
  }

void display(dlist_t *ptr_list)
{
   node_t *pres, *q;

   pres=ptr_list->head;
  if(pres==NULL)
   printf("\nEmpty list..\n");
 else
  {
  q=pres;
   while(q->next!=pres)
   {
      printf("%d<->",q->data);
      q=q->next;
   }
  printf("%d< ->",q->data);//last node
  }
}


  void insert_tail(dlist_t* ptr_list,int x)
 {
    node_t *temp,*pres;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp->prev=temp;

    pres=ptr_list->head;

    if(pres==NULL)
      ptr_list->head=temp;
    else
     {
	pres->prev->next=temp;
	temp->prev=pres->prev;
	temp->next=pres;
	pres->prev=temp;
    }
  }
  
  












