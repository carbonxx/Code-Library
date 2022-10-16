#include <stdio.h>
int main()
{
    int mat1[30][30], mat2[30][30], mat3[30][30], sum=0, i, j, k,r,c;
    printf("Enter the number of rows\n");
    scanf("%d",&r);
    printf("Enter the number of columns\n");
    scanf("%d",&c);
    //Entering the first matrix
    printf("Enter the  first matrix \n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            scanf("%d", &mat1[i][j]);
    }
    //Enter the second matrix
    printf("Enter the second  matrix  \n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            scanf("%d", &mat2[i][j]);
    }
  //multiplying both the matrices
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            sum=0;
            for(k=0; k<c; k++)
                sum = sum + mat1[i][k] * mat2[k][j];
            mat3[i][j] = sum;
        }
    }
    //printg the result matrix
    printf("\nMultiplication result of the two given Matrix is: \n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d\t", mat3[i][j]);
        printf("\n");
    }
}
