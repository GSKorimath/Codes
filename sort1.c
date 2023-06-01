#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{   int m;
    if (l < r) {
        m = l+(r-l)/2;  // to find mid

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void display(int arr[],int n,FILE *fp1)
{
      int i;
    for(i=0;i<n;i++)
    {
        fprintf(fp1,"%d\t",arr[i]);

    }

}
int read_ip(int arr[],int n,FILE *fp)
{

    int i;
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&arr[i]);

    }


}



int main()
{
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("input1.txt","w");
    fp2=fopen("output1.txt","w");
    int n,i,a[100],l,m,r;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }

    display(a,n,fp1);
    fclose(fp1);
    fp3=fopen("input1.txt","r");
    read_ip(a,n,fp1);


    fclose(fp3);

    merge_sort(a,0,n-1);
    display(a,n,fp2);
