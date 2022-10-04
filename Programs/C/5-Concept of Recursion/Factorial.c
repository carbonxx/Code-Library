#include<stdio.h>
int sum(int);
int main()
{
   int x,z;
   printf("Enter the value of x : ");
   scanf("%d",&x);
   z=sum(x);
   printf("The sum of %d numbers is %d.",x,z);
}
int sum(int a)
{
    int s;
    if(a==1)
    {
        return(a);
    }
    else
    {
       s=a*sum(a-1);
       return(s);
    }
}