#include<stdio.h>
int main()
{
    int num1, num2;  
    float fraction;     
    char character;
    
    printf("Enter two numbers number : ");
    // Taking two numbers as input from the user
    scanf("%d%d", &num1, &num2);
    printf("The two numbers You have entered are %d and %d\n", num1, num2);

    // Taking float or fraction as input from the user eg: 1.23
    printf("Enter a Decimal number : ");
    scanf("%f", &fraction); 
    printf("The float or fraction that you have entered is %f \n", fraction);

    // Taking Character as input from the user
    printf("Enter a Character : ");
    scanf("%c",&character);
    printf("The character that you have entered is %c\n", character);
    return 0;
}
