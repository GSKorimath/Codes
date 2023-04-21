#include<stdio.h>

#define ROW 3
#define COL 3

int main()
{
    int First[3][3],Second[3][3],Result[3][3];

    int m1,n1,m2,n2,i,j;


    printf("Enter no of row and column for 1st matrix\n");
    scanf("%d%d",&m1,&n1);

    printf("Enter no of row and column for 2nd matrix\n");
    scanf("%d%d",&m2,&n2);

     //check if multiplication is possible, 1st matrix rows must be equal to
     //Second matrix columns
    if(n1==m2)
    {
        printf("Enter First matrix\n");
        matrixInput(First);

        printf("\nEnter Second matrix\n");
        matrixInput(Second);


        matrixMultiply(First,Second,Result);

        printf("Product of entered matrices :-\n");

        //print the resultant matrices
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n2;j++)
                printf("%d\t",*(*(Result + i) + j));
            printf("\n");
        }


    }
    else
    {
       printf("Sorry ! Multiplication is not possible");
    }
    return 0;
}

//Get matrix data
void matrixInput(int mat[][COL])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            scanf("%d", (*(mat + row) + col));
        }
    }
}


//Function to multiply Matrices mat1 * mat2 = res
void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL])
{
    int row, col, i;
    int sum;


    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            sum = 0;
            // find the sum of product of each elements of row for first matirx
            // and columsn of second
            for (i = 0; i < COL; i++)
            {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }


           //save sum in resultant matrix
            *(*(res + row) + col) = sum;
        }
    }
}
