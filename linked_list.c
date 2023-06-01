#include<stdio.h>
typedef struct node
{
    int data;
    char n[20];

    struct node *next;
}LIST;
void insert_front(LIST *head,LIST *newnode,LIST *p)
{
    p=head;
    newnode=(LIST*)malloc(sizeof(LIST));
     printf("Enter the new data:\n");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=newnode;

        }
        else
           {
               head=newnode;
             newnode->next=p;
           }
}

int main()
{
    LIST *head,*newnode,*p;
    head=NULL;

    int wish;
    do
    {
        newnode=(LIST*)malloc(sizeof(LIST));
        printf("Enter the data:\n");
        scanf("%d",&newnode->data);
        gets(newnode->n);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            p=newnode;
        }
        else
        {
            p->next=newnode;
            p=newnode;
        }
        printf("Wish to continue[1/0];\n");
        scanf("%d",&wish);

    }while(wish==1);
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        printf("%s\n",p->n);
        p=p->next;
    }
    printf("End of list ....\n");
    //search
    p=head;
    int key;
    printf("Enter the value you want to search:\n");
    scanf("%d",&key);
    while(p!=NULL)
    {
        if(p->data==key)
        {
            printf("found!\n");
            break;
        }
        else
        {
            p=p->next;
        }
    }
    if(p==NULL)
        printf("not found");

    //count the no. of nodes//
    newnode=head;
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
    printf("Number of nodes:%d\n",cnt);
  //insert_front(head,newnode,p);
    p=head;
  newnode=(LIST*)malloc(sizeof(LIST));

     printf("Enter the new data:\n");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=newnode;

        }
        else
           {
               head=newnode;
             newnode->next=p;
           }
     p=head;
     printf("New List is:\n");
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }

printf("End of list ....\n");

//insert at end
newnode=(LIST*)malloc(sizeof(LIST));

     printf("Enter the new data:\n");
        scanf("%d",&newnode->data);
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;
    p=head;
    printf("New List is:\n");
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }

printf("End of list ....\n");
//insert at a position//
int pos,i;
printf("Enter the position:\n");
scanf("%d",&pos);
p=head;
newnode=(LIST*)malloc(sizeof(LIST));
printf("Enter the new data:\n");
scanf("%d",&newnode->data);
for(i=0;i<pos-1;i++)
{
    p=p->next;
}
newnode->next=p->next;
p->next=newnode;

 p=head;
    printf("New List is:\n");
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    //delete at front//
    p=head;
    if(head==NULL)
    {
        free(p);
    }
    else
    {
        head=head->next;
        p->next=NULL;
        free(p);
    }
    p=head;
    printf("List after deletion at front:\n");
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    //delete at end//
    p=head;
    LIST *pp=head;
    if(head==NULL)
    {
        free(p);
    }
    else
    {
        while(p->next!=NULL)
        {
            pp=p;
            p=p->next;
        }
        pp->next=NULL;
        free(p);
    }
    p=head;
    printf("List after deletion at end:\n");
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    //deletion based on element//
    int d;
    printf("Enter the data u want to delete:\n");
    scanf("%d",&d);
    p=head;
    pp=head;
    if(head==NULL)
    {
        free(p);
    }
    else
    {
        while(p->data!=d)
    {
        pp=p;
        p=p->next;
    }
    pp->next=p->next;
    p->next=NULL;
    free(p);
    }
     p=head;
    printf("List after deleting %d :\n",d);
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    //deletion based on position//
printf("Enter the position:\n");
scanf("%d",&pos);
p=head;pp=head;
if(head==NULL)
    {
        free(p);
    }
   else
   {
        for(i=0;i<pos;i++)
    {    pp=p;
        p=p->next;
    }
   }
   pp->next=p->next;
   p->next=NULL;
   free(p);
    p=head;
    printf("List after deleting node at position:\n",d);

    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
