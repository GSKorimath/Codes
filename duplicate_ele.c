#include<stdio.h>
#define MAX 50


void read(int a[MAX],int n)//get the array elements from user//
{    int i;
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void cnt_duplicate(int a[MAX],int n)//count the duplicate elements//
{
     int i,j,k,count,flag;

    for(i=0;i<n;i++)
    {
        count=1;
        flag=0;

        //check if already counted
        for(k=0;k<i;k++)
        {
            if (a[k]==a[i])
            {
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]==a[i])
                {
                    count++;
                }
            }
        }
        if(flag!=1)
            printf("%d occurs %d times\n",a[i],count);
    }

}
int main()
{
    int a[MAX],n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    read(a,n);
    cnt_duplicate(a,n);
}
