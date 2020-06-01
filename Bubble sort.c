//Implementing Bubble sort in a C Program
 #include<stdio.h>
 void main()
 {
  int count, temp, i, j, number[30];
  printf("Enter the amount of  vlaues (max=30):");
  scanf("%d",&count);
  printf("Enter %d numbers: ",count);
  for(i=0;i<count;i++)
  scanf("%d",&number[i]);
  for(i=1;i<count;i++)
  {
      for(j=0;j<(count-1);j++)
      {
        if(number[j]>number[j+1])
        {
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }
  printf("Sorted elements: ");
  for(i=0;i<count;i++)
  {
    printf(" %d",number[i]);
  }
}