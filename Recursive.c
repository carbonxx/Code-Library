//Binary to Decimal
#include<stdio.h>
int btod(int binary);
void main()
{									
	int binary, decimal;                                    
	printf("\nEnter the binary number to be converted: ");             
	scanf("%d", &binary);  
    decimal=btod(binary);                                         						
	printf("Decimal of %d is: %d\n\n", binary, decimal);
}
int btod(int binary)
{
	if(binary==0)                      
	{
		return 0;
	}
	else 
	{	
		return(binary%10+2*btod(binary/10));              
	}									
}