#include<stdio.h>
void main()
{
    int num;
    printf("Enter you Number : ");\
    scanf("%d",num);
    if(num<100)
    {
        printf("Number is less than 100!");
    }
    else if(num==100)
    {
        printf("Number is equal to 100!");
    }
    else
    {
         printf("Number is more than 100!");
    }
    
}