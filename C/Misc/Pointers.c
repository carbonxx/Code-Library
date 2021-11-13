#include<stdio.h>
#include<math.h>
void main()
{
    int i,n;
    float x[10],*p,mean,variance,sd,sum=0,sum1=0;
    printf("Enter the number of value : ");
    scanf("%d",&n);
    printf("Enter %d elements : ",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }
    p=x;
     for(i=0;i<n;i++)
     {
         sum=sum+*p;
         p++;
     }
     mean=sum/n;
     p=x;
      for(i=0;i<n;i++)
      {
          sum1=sum1+pow((*p-mean),2);
          p++;
      }
      variance=sum1/n;
      sd=sqrt(variance);
      printf("Sum : %f \n", sum);
      printf("Mean : %f \n", mean);
      printf("Variance : %f \n", variance);
      printf("Standard Deviation : %f \n", sd);
}

