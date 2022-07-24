#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;;

void InsertFirst(PPNODE head,int no)
{
   PNODE newn = NULL;

   newn = (PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;

   if(*head==NULL)  //LL is empty
   {
       *head=newn;
   }
   else    //LL is at list one node
   {
       newn->next=*head;
       newn->prev=*head;
       *head=newn;
   }
}
void InsertLast(PPNODE head,int no)
{
   PNODE temp=NULL;
   PNODE newn = NULL;

   newn = (PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;
   newn->prev=NULL;

   if(*head==NULL)
   {
       *head=newn;
   }
   else
   {
       temp=*head;

       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=newn;
       newn->prev=temp;
   }
}
void Display(PNODE head)
{
  printf("Elemnts are\n");
  while(head!=NULL)
  {
      printf("<-|%d|->",head->data);
      head=head->next;
  }
  printf("\n");
}
int Count(PNODE head)
{
    int iCnt=0;
    while(head!=NULL)
    {
        iCnt++;
        head=head->next;
    }
    return iCnt;
}
DeleteFirst(PPNODE head)
{
   if(*head==NULL)
   {
       return;
   }
   if((*head)->next==NULL)
   {
      free(*head);
      *head=NULL;
   }
   else
   {
       *head=(*head)->next;
       free((*head)->prev);
       (*head)->prev=NULL;
   }
}
void DeleteLast(PPNODE head)
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
    PPNODE temp=NULL;
    PPNODE newn=NULL;

    int size=0,iCnt=0;

    size=Count(*head);

    if((pos<1)||(pos>(size+1)))
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==1)
    {
        InsertFirst(head,no);
    }
    else if(pos==(size+1))
    {
        InsertLast(head,no);
    }
   
}
int main()
{
  int iRet=0;
  PNODE first=NULL;  
  InsertFirst(&first,11);
  InsertFirst(&first,21);
  InsertFirst(&first,51);

  Display(first);
  iRet=Count(first);
  printf(" Number of Node %d",iRet);
  return 0;
}
