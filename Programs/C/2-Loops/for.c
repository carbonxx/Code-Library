#include<stdio.h>

int main()
{
  int i = 0;   // declaration and initialization at the same time
    for(i = 0; i < 10; i++)
    {
        printf("i = %d\n", i);         //Remember that the loop condition checks the conditional statement before it loops again
        /*
            consequently, when i equals 10, the loop breaks.
            i is updated before the condition is checked-
            hence the value of i after exiting the loop is 10 
        */
     }

    printf("The value of i after exiting the loop is %d\n\n", i);                                                          
    return 0;
