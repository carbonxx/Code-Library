#include<stdio.h>
int main()
{
   int i = 10;     // declaration and initialization at the same time
    do // do contains the actual code and the updation
    {
        printf("i = %d\n",i);
        i = i-1;    // updation
    }
    // while loop doesn't contain any code but just the condition
    while(i > 0);
    printf("he value of i after exiting the loop is %d \n", i);
    return 0;
}