//Taylor Series
#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
    int i,n;
    float x,sum,term;
    printf("Enter the value for X :");
    scanf("%f",&x);
    printf("Enter the number of terms :");
    scanf("%d",&n);
    x=(x*3.141592)/180;
    printf("The mathematical sin value : %f \n",sin(x));
    term=x;
    sum=x;
    for(i=1;i<=n;i++)
    {
        term=(-term*x*x)/(2*i*(2*i++));
        sum=sum+term; 
    } 
    printf("The calulated sin value : %f \n",sum);   
}
