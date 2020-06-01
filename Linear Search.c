//Linear Search
#include<stdio.h>
void main()
{
    int a[50],n,i,key,count=0;
    printf("Enter the amount of  vlaues (max=50) :");
    scanf("%d", &n);
    printf("Input the values (separated by space) :");
   for (i = 0; i <n; ++i) 
   {
    scanf("%d", &a[i]);  
   }
    printf("Enter the element to be searched :");
    scanf("%d",&key);
   for ( i = 0; i <n; i++)
   {
     if(key==a[i])
    {
        count=1;   
        break;
    }
   }
    if(count==1)
  {
    printf("Element is present at index %d",i );
  }
   else
  {
    printf("Element is not present in array");
  }

} 

