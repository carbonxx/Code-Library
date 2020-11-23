#include<stdio.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if((n/2)*2 == n)
    {
        printf("%d is Even\n", n);
    }
    else
    {
        printf(" %d is Odd\n", n);
    }
    return 0;
}