#include<stdio.h>
int a,b;
int main()
{
    printf("Enter the two values to find the greatest and smallest number:");
    scanf("%d%d", &a, &b);
    if(a == b)
    {
        printf("Both are equal\n");
    }   
    else if(a < b)
    {
        printf("The largest number is %d \n", b);
        printf("The smallest number is %d \n", a);
        printf("The largest number is %d \n", b);
    }
    else    //Only possibility remaining
    {
        printf("The largest number is %d \n", a);
        printf("The smallest number is %d \n", b);
    }
    return 0;
}