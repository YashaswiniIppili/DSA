//program to implement multi list to store a sparse matrix
#include<stdio.h>
#include<stdlib.h>
struct col_node {
	int col;
	int data;
	struct col_node *next_col;
};

struct row_node {
	int row;
	struct col_node *next_col;
	struct row_node *next_row;
};

typedef struct row_node rownode_t;
typedef struct col_node colnode_t;

rownode_t *create_rows(int); // create rows
void insert_end(rownode_t*, int,int); 
void insert_matrix(rownode_t*, int(*)[],int, int); 
void display(rownode_t*);

int main()
{
  int a[10][10];
  int i,j,row,col;
  rownode_t *head,*p;
  head=NULL;
  printf("Enter the row and cols..\n");
  scanf("%d %d",&row, &col);

  
  printf("Enter the data for the matrix..\n");
  for(i=0;i<row;i++)
  {
     for(j=0;j<col;j++)
      scanf("%d",&a[i][j]);
  }
  //storing the matrix as a multi list...;
  
  head=create_rows(row);
  insert_matrix(head,a,row,col);
  //displaying the matrix as a list

  display(head);
}

  void display(rownode_t *head)
  {
	  colnode_t *pres;
	  printf("Displaying Sparse Matrix as a multi List\n");
	  if(head==NULL)
		  printf("Empty Multi List");
	  else
	  {
		  while(head!=NULL)
		  {
			  printf("%d ->",head->row);
			  pres=head->next_col;
			  while(pres!=NULL)
			  {
				  printf("%d ,%d->",pres->col, pres->data);
			      pres=pres->next_col;
		    }
			head=head->next_row;
			printf("\n");
		  }
	  }		  
	   
  }			  
		  
	  
  rownode_t* create_rows(int row)
  {
	  int i;
	  rownode_t *temp, *p, *q;
	  p=q=NULL;
	  
	   for(i=0;i<row;i++)
	   {
		   temp=(rownode_t*)malloc(sizeof(rownode_t));
		   temp->row=i;
		   temp->next_row=NULL;
		   temp->next_col=NULL;
		   
		   if(p==NULL)
			   p=q=temp;
		   else
			   q->next_row=temp;
		       q=temp;   
	   }
	   
	   return p;
	   
  }
		   
  void insert_matrix(rownode_t* head, int(*a)[10],int row, int col)
  {
    int i,j;
	rownode_t *p;
	
	p=head;
	
	for(i=0;i<row;i++)
	{
      for(j=0;j<col;j++)
	  {
		  if (a[i][j]!=0)
			  insert_end(p,j,a[i][j]);
	  }
	  p=p->next_row;
	}
	
  }
  
  void insert_end(rownode_t* head, int col, int key)
  {
      colnode_t *temp,*pres;
	
    temp=(colnode_t*)malloc(sizeof(colnode_t));
	temp->col=col;
	temp->data=key;
	temp->next_col=NULL;
	
	pres=head->next_col;
	
	if(pres==NULL) //first value of the row
	  head->next_col=temp;
	else
		//insert at the end of the row
		{
			while(pres->next_col!=NULL)
				pres=pres->next_col;
		    pres->next_col=temp;
		}
		
  }
	
	  
		  
		  
		  
		  
		   



















