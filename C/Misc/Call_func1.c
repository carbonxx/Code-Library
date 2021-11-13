#include<stdio.h>
int isprime(int num)
 {
	int i;	
	if(num==0||num==1)                         
	{
		return 0;                              
	}
	  for(i=2;i<=num/2;i++)                
	{
		if(num%i==0)                 
		{
		  return 0;                
		}                               
    }                                      
	   return 1;
	}
void main()
{
	int num;
	printf("Enter a number\n");
	scanf("%d",&num);
	if(isprime(num))
	{
		printf("%d is prime number \n",num);
	}
	else
	{
	    printf("%d is not a prime number\n",num);
	}
}