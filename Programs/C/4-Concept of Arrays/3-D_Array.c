#include<stdio.h>
int main()
{
  int arr[3][4][3];

  printf("Enter the array elements: \n");

  for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 4; ++j)
    {
      for(int k = 0; k < 3; ++k)
      {
        scanf("%d", &arr[i][j][k]);
      }
    }
  }

  printf("\nThe elements of the array: \n");
  for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 4; ++j)
    {
      for(int k = 0; k < 3; ++k)
      {
        printf("The element in arr[%d][%d][%d] is: %d\n", i, j, k, arr[i][j][k]);
      }
    }
  }

  return 0;
}
