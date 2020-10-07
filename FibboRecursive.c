// Fibonacci series using recursion
#include<stdio.h> 
int fibonacci(int);
int main(void)
{    
    int terms;
    printf("Enter terms: ");
    scanf("%d", &terms);       
    for(int n = 0; n < terms; n++)
    {
        printf("%d ", fibonacci(n));
    }
    return 0; 
}
 int fibonacci(int num)
{    
    if(num == 0 || num == 1)
    {
        return num;
    }
    else
    {
        return fibonacci(num-1) + fibonacci(num-2);
    }
}
