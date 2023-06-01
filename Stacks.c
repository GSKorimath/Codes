// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Stack {
	int top;
	int array[MAX];
}ST;

void display(FILE *fp)
{
    int item;
    do
    {
        fscanf(fp,"%d",&item);
        if(!feof(fp))
            printf("%d\t",item);
        else
            break;
    }while(1);

}

void createStack(ST *s)
{
	s->top = -1;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
	if(stack->top == MAX - 1)
        return 1;
    else
        return 0;
}


// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    if(stack->top == -1)
        return 1;
    else
        return 0;
}
// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item)
{
    if(isFull(stack))
    {
        printf("stack is full...\n");
        return;
    }
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n", item);
}
void write_stack(FILE *stackfile,FILE *pushlog,int item)
{
    //write to stack file
    fprintf(stackfile,"%d\n",item);

    //write to pushlog
    fprintf(pushlog,"%d\n",item);
}

void write_pop(FILE *poplog,int item)
{
    fprintf(poplog,"%d\n",item);
}
// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack)
{
    if(!isEmpty(stack))
        return stack->array[stack->top--];
    else{
        printf("stack is empty...\n");
        return 0;
    }
}

//main
int main()
{
	int u,l,a[100],i,n,item,*x,c;
    FILE *fp1,*fp2,*fp3,*fp4;
    ST s;

    /* *********initialize new stack****** */
    createStack(&s);

    /* ************* write random numbers to input file */
    fp1=fopen("input.txt","w");
    printf("Enter the lower and upper limit:\n");
    scanf("%d%d",&l,&u);
    printf("Enter the count of random no's u want to generate:\n");
    scanf("%d",&n);
    srand((time(0)));
    for(i=0;i<n;i++)
    {
        a[i]=((rand()%(u-l)+1)+l);
        fprintf(fp1,"%d\n",a[i]);
    }
    fclose(fp1);
    printf("input file created.....\n");

    /* ************ bring items from input file to stack file and pushlog file ******* */
    fp1=fopen("input.txt","r");
    fp2=fopen("stack.txt","w");
    fp3=fopen("push.log","w");

    do
    {
        fscanf(fp1,"%d",&item);
        if(!feof(fp1))
        {
                push(&s,item);
                write_stack(fp2,fp3,item);
        }
        else
            break;
    }while(1);
    fclose(fp2);
    fclose(fp3);



    /* ***************add some more items to stack ***** */
    fp2=fopen("stack.txt","a");
    fp3=fopen("push.log","a");





    /* **************display all files **********/
    fp1=fopen("push.log","r");
    printf("\npush log file=\n");
    display(fp1);
    fclose(fp1);


   printf("\n\nEnter 1 to push the elements\nEnter 2 to pop the elements\nEnter 0 to exit\n");
  do
  {
     scanf("%d",&c);
    if(c==1)
    {   fp4=fopen("push.log","a");
        printf("Enter the no u want to push:\n");
        scanf("%d",&item);
        push(&s,item);
        write_stack(fp2,fp3,item);
        fclose(fp2);
        fclose(fp3);

    }
    else if(c==2)
    {
         fp4=fopen("pop.log","w");
         item=pop(&s);
        write_pop(fp4,item);
        printf("popped item=%d\n",item);
        fclose(fp4);
    }
    else
        break;
    } while(c!=0);
    fp1=fopen("push.log","r");
    printf("\nnew push log file=\n");
    display(fp1);
    fclose(fp1);

    fp2=fopen("pop.log","r");
    printf("\n new pop log file=\n");
    display(fp2);
    fclose(fp2);
    return 0;
}
