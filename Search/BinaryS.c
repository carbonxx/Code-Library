//Binary Search
#include <stdio.h>
void main() 
{
   int a[50],n,i,key,count,low,mid,high;
   printf("Enter the amount of  vlaues (max=50) :");
    scanf("%d", &n);
    printf("Input the values (separated by space) :");
   for (i = 0; i <n; ++i) 
   {
    scanf("%d", &a[i]);  
   }
    printf("Enter the element to be searched :");
      scanf("%d",&key);
       count=0;
       low=0;
       high=n-1;
       while (low<=high)
      {
         mid=(low+high)/2;
            if(key==a[mid])
           {
            count=1;
             break;
           }
            if(key<a[mid])
           {
              high=mid-1;
           }
            if(key>a[mid])
           {
             high=mid+1;
            }
        }
   if(count==1)
  {
    printf("Element is present at index %d",mid+1);
  }
   else
  {
    printf("Element is not present in array");
  }
}
