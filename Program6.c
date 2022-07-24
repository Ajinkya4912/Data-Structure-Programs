
#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **  PPNODE;

void InsertFirst(PPNODE head,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*head==NULL) //LL is empty
    {
        *head=newn;
    }
    else
    {
        newn->next=*head;
        *head=newn;
    }
}
void InsertLast(PPNODE head,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*head==NULL)
    {
        *head=newn;
    }
    else
    {
        PNODE temp=NULL;
        temp=*head;

        while(temp->next!=NULL)   
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
}
void Display(PNODE head)
{
    printf("Elements are Linked Liste are\n");
    while(head!=NULL)
    {
       printf("| %d |->",head->data);

       head=head->next;
    }
    printf("\n");
}

void Count(PNODE head)
{
    int iCnt=0;
    while(head!=NULL)
    {
        iCnt++;
       head=head->next; 
    }
}
void DeleteFirst(PPNODE head)
{
    PNODE temp=NULL;
    
    if(*head==NULL)
    {
        return;
    }
    else
    {
        temp=*head;
       *head=temp->next;
       free(temp);
    }
}
DeleteLast(PPNODE head)
{
    PNODE temp=NULL;
    if(*head==NULL)
    {
        return;
    }
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
   }
   else
   {
        temp=*head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
   }
}
void InsertAtPosition(PPNODE head,int no,int pos)
{
     
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,101);
    InsertFirst(&first,51);
    InsertLast(&first,1);
    InsertFirst(&first,21);
    InsertFirst(&first,11);
 
    Display(first);
}