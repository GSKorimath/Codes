#include<stdio.h>
typedef struct Tdetails
{
    int T_id;
    int U_id;
    float amnt;
    int B_id;
}DT;
void read(DT x[],int n)
{    int i;
     printf("Enter the transaction details of %d people:\n",n);
    for(i=0;i<n;i++)
    {   printf("enter the details of person %d\n",i+1);
        scanf("%d",&x[i].T_id);
    scanf("%d",&x[i].U_id);
    scanf("%f",&x[i].amnt);
    scanf("%d",&x[i].B_id);
    }
}
void display(DT x[],int n)
{  int i;
    printf("Transaction details are:\n");
    for(i=1;i<=n;i++)
    {
       printf("%d\t%d\t%f\t%d\n",x[i].T_id,x[i].U_id,x[i].amnt,x[i].B_id);

    }
}
void transaction(DT x[],int id,int n)
{    int i,cnt=0;
    for(i=0;i<n;i++)
    {
         if(id==x[i].U_id)
        {   printf("ID found\n");
            printf("%d\t%d\t%f\t%d\n",x[i].T_id,x[i].U_id,x[i].amnt,x[i].B_id);
            cnt++;
        }

    }
     printf("%d has made %d transactions today",id,cnt);
}
void search_Tid(DT x[],int tid,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(tid==x[i].T_id)
        {   printf("Transaction ID found\n");
            printf("%d\t%d\t%f\t%d\n",x[i].T_id,x[i].U_id,x[i].amnt,x[i].B_id);
            break;
        }
    }
}
main()
{
    DT x[100];
    int n,id,tid;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    read(x,n);
    display(x,n);
     printf("Enter the User_ID to know the transaction detail:\n");
    scanf("%d",&id);
    transaction(x,id,n);
    printf("\n");
    printf("Enter the transaction id to search:\n");
    scanf("%d",&tid);
    search_Tid(x,tid,n);
}
