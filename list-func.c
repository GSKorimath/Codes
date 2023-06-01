#include<stdio.h>
typedef struct node
{
    int a;
    char n[20];

    struct node *next;
}LIST;
void menu()
{
    printf("Menu:\n");
    printf("1.Insert at front\n");
    printf("2.Insert at position\n");
    printf("3.Insert at end\n");
    printf("4.Delete from front\n");
    printf("5.Delete at end\n");
    printf("6.Delete at position\n");
    printf("7.Display\n");
    printf("8.Exit\n");
}
//Create the List//
LIST  *createlist(LIST * head,int a)
{
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    if(newnode==NULL)
    {
        printf("Overflow..\n");
        exit(0);
    }

    newnode->a=a;
    newnode->next=NULL;
    if(head==NULL)
        {
            head=newnode;
        }
        else
        {
           LIST *p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
        }

    return head;
}
//inserting node at front//
LIST *insert_front(LIST *head,int a)
{
    LIST *p;
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    if(newnode==NULL)
    {
        printf("Overflow...\n");
        exit(0);
    }
    newnode->a=a;
    newnode->next=head;
    head=newnode;
    return head;

}
//inserting node at end//
LIST *insert_end(LIST *head,int a)
{
    LIST *p=head;
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    if(newnode==NULL)
    {
        printf("Overflow...\n");
        exit(0);
    }
    if(p==NULL)
    {
        p=newnode;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        newnode->a=a;
        p->next=newnode;
        newnode->next=NULL;
    }
    return head;

}
//inserting node at specific position//
LIST *insert_pos(LIST *head,int pos,int a)
{
    LIST *p=head;
    LIST *pp=head;
   LIST *newnode=(LIST*)malloc(sizeof(LIST));
    if(newnode==NULL)
    {
        printf("Overflow...\n");
        exit(0);
    }

    if(p==NULL)
    {
        p=newnode;
    }
    int c=count(head);
    if(pos>=c)
    {
       printf("Invalid position\n");
        return head;
    }
    if(pos==0)
    {
       head=insert_front(head,a);
    }
    else
    {  int i;
      for(i=0;i<pos-1;i++)
{
    p=p->next;
}
newnode->a=a;
newnode->next=p->next;
p->next=newnode;

    }
    return head;


}
//Count the number of nodes//
int count(LIST *head)
{
  LIST *newnode=head;
    int cnt=0;
   if(newnode==NULL)
    {
        printf("No nodes are formed\n");
    }
    while(newnode!=NULL)
    {
        newnode=newnode->next;
        cnt++;

    }
    return cnt;
}
//Deletion from front//
LIST *delete_front(LIST *head)
{
    LIST *p=head;
    if(p==NULL)
    {
        printf("Empty list\n");
        free(p);
    }
    else
    {
        head=head->next;
        p->next=NULL;
        free(p);
    }
    return head;
}
//Deletion from end//
LIST *delete_end(LIST *head)
{
    LIST *p=head;
    LIST *pp=head;
    if(p==NULL)
    {
        printf("Empty list\n");
         return NULL;
    }
    //if list contains only one node//
    if(head->next==NULL)
    {

        free(p);
        return NULL;
    }
    else
    {
        while(p->next!=NULL)
        {    pp=p;
            p=p->next;
        }
        pp->next=NULL;
        free(p);
    }
    return head;
}
//Deletion at specific position//
LIST *delete_pos(LIST *head,int pos)
{
    LIST *p=head;int i,c;
    LIST *pp=head;
    if(p==NULL)
    {
        printf("Empty list\n");
        free(p);
    }
    c=count(head);
    //if position is more than nodes available//
    if(pos>=c)
    {
        printf("Invalid position\n");
        return head;
    }
    if(pos==0)
    {
        head=head->next;
        free(p);
        return head;
    }

    else
    {
        for(i=0;i<pos;i++)
        {
            pp=p;
            p=p->next;
        }
        pp->next=p->next;
        p->next=NULL;
        free(p);
    }
    return head;
}
//Display the list//
void display(LIST *head)
{
    LIST *p=head;
    printf("The list is:\n");
    if(p==NULL)
    {
        printf("empty list\n");
    }
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
}

int main()
{
    LIST *head;
    int a,wish,ch,pos;
    head=NULL;
    do
    {
        printf("Enter the data:\n");
        scanf("%d",&a);
        head=createlist(head,a);
        printf("Wish to continue[1/0]:\n");
        scanf("%d",&wish);
    }while(wish==1);
    do
    {
        menu();
        printf("Enter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
         case 1:printf("Enter the data:\n");
                scanf("%d",&a);
                head=insert_front(head,a);
                break;
         case 2:printf("Enter the data:\n");
                scanf("%d",&a);
                printf("Enter the pos:\n");
                scanf("%d",&pos);
                head=insert_pos(head,a,pos);
                break;
        case 3:printf("Enter the data:\n");
                scanf("%d",&a);
                head=insert_end(head,a);
                break;

        case 4:
                head=delete_front(head);
                break;

       case 5:
                head=delete_end(head);
                break;
        case 6:
                printf("Enter the pos:\n");
                scanf("%d",&pos);
                head=delete_pos(head,pos);
                break;
        case 7:display(head);
                break;

        default:exit(0);
        }


        }while(1);
    }
