//This is a simple code for understanding data types
#include <stdio.h>
int main()
{
    int test = 5; //dataype used for numbers
    printf("Number = %d \n", test);
     

    float number1 = 13.5;
    double number2 = 12.4;

    printf("number1 = %f \n", number1);
    printf("number2 = %lf \n", number2);
    
     char chr = 'a';    
    printf("character = %c \n", chr);
    
    int testint;
    printf("Enter an integer: ");
    scanf("%d", &testint);  
    printf("Number = %d \n",testint);

    char a;  //datatype used for characters
    printf("Enter a character: ");
    scanf(" %c", &a);     
    printf("You entered %c.\n",a);  
    printf("ASCII value is %d.", a);  
    
    return 0;
}
