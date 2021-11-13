#include<stdio.h>
int main()
{
   //Nested loops are usually used to print a pattern in c
   //They are also used to print out the matrix using a 2 dimensional array.
    int i,j,k;
    printf("Output of the nested loop is :\n");
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {    
            printf("* ");
            printf("\n");
        }
    }
    return 0;
