#include<stdio.h>
#include<stdlib.h>
/*
typedef struct node {
    int data;
    struct node* next;
}node;

int main()
{
    node *head;
    head=(node*)malloc(sizeof(node));
}
*/

typedef struct dnode
{
    int data;
    struct dnode* after;
    struct dnode* before;

}dnode;

void insertfront(dnode** head,int val)
{
    dnode* newnode = (dnode*)malloc(sizeof(dnode));
    newnode->data = val;
    newnode->after  = *head;
    (*head)->before = newnode;
    *head = newnode;
} 

void insertback(dnode**head, int val)
{
    dnode* newnode = (dnode*)malloc(sizeof(dnode));
    newnode->data = val;
    dnode* temp =*head;
    while(temp->after!=NULL)
    {
        temp=temp->after;
    }
    newnode->before = temp;
    newnode->after = NULL;
    temp->after  = newnode;
}

void insertbetween(dnode** head,int pos,int val)
{
    dnode* temp =*head;
    dnode* newnode = (dnode*)malloc(sizeof(dnode));
    newnode->data = val;
    int count = 1;
    while(count+1 != pos)
    {
       temp = temp->after; 
       count = count+1;
    }
    newnode->after = temp->after;
    temp->after = newnode;
    newnode->before = temp;
    newnode->after->before = newnode;
}



void printlist(dnode* head)
{
    while(head!=NULL)
    {
        printf("%d<->",head->data);
        head=head->after;
    }
    printf("NULL");
}

int main()

{
    dnode*head,*middle,*last;
    head = (dnode*)malloc(sizeof(dnode));
    middle = (dnode*)malloc(sizeof(dnode));
    last = (dnode*)malloc(sizeof(dnode));

    head->after = middle;
    middle->after = last;
    last->after = NULL;

    head->before = NULL;
    middle->before = head;
    last->before = middle;

    head->data = 1;
    middle->data = 2;
    last->data = 3;

    printlist(head);
    printf("\n");
    insertfront(&head,0);
    printlist(head);
    insertback(&head,5);
    printf("\n");
    printlist(head);
    printf("\n");
    insertbetween(&head,5,4);
    printlist(head);
}


