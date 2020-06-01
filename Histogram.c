//Histogram for array
#include <stdio.h>
void histogram ( int numbers[], int count );
void main() 
{
   int i, j;
   int inputValue;

   printf("Input the amount of values: (max=5) \n");  
   scanf("%d", &inputValue);
   int numbers[inputValue];

   printf("Input the values between 0 and 9 (separated by space): \n");
   for (i = 0; i < inputValue; ++i) 
   {
    scanf("%d", &numbers[i]);  
   }

    int results[5] = {0};

    for (i = 0; i < 5; ++i) 
    {   
      for(j = 0; j < inputValue; j++) 
      {
         if ( numbers[j] == i)
         {
            results[i]++;
         }
     } 
   }
   printf("\n");
    histogram(numbers, 5);
}

void histogram(int numbers[], int count) 
{
   int i, j;
   for (i = 0; i < count; i++) 
  { 
   printf("[%d] ", i);
     for ( j = 0; j < numbers[i]; ++j)
    {
       printf("*");
    } 
       printf("\n");
  }
}