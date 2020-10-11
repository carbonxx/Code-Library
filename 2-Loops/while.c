#include<stdio.h>
int main()
{
    int i = 0;  // declaration and initialization at the same time
    printf("Printing numbers using while loop from 0 to 9\n");
    /* 
        while i is less than 10 
    */
    while(i<10)
    {
        printf("%d\n",i);
        /* 
            Update i so the condition can be met eventually 
            to terminate the loop 
        */
        i++;    // same as i=i+1;
      }
    return 0;
}