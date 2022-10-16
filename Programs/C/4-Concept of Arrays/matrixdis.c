// C program to store marks of different students and display it.
#include <stdio.h>
int main()
{
  int marks[100][100],n,m;
  printf("Enter the number of students\n");
  scanf("%d",&m);
   printf("Enter the number of subjects\n");
  scanf("%d",&n);
  printf("Enter the marks of all subjects of each student");
  // Using nested loop to store values in a 2d array
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      printf("Student  %d, Subject %d: ", i + 1, j + 1);
      scanf("%d", &marks[i][j]);
    }
  }
  printf("\nDisplaying values: \n\n");

  // Using nested loop to display vlues of a 2d array
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      printf("Student %d, Subject %d = %d\n", i + 1, j + 1, marks[i][j]);
    }
  }
  return 0;
}
