//Program with use of 3 functions
#include<stdio.h>
int slen(char s[])
{
    int i,len=0;
    for(int i=0;s[i]!='\0';i++)
    {
        len++;
    }
    return len;
}
int scomp(char s1[], char s2[])
{
    int i, j;
    if(slen(s1)!=slen(s2))
    {
        return 0;
    }
    for(i=0; s1[i]!='\0'; i++)
    {
        if(s1[i]!=s2[i])
        {
            return 0;
        }
    }
    return 1;
}
int scat(char s1[], char s2[])
{
    int i, j;
    for(i=slen(s1), j=0; s2[j]!='\0'; j++ )
    {
        s1[i]=s2[j];
    }
    s1[i]='\0';
    return 0;
}
void main()
{
    char s1[200],s2[200];
    printf("Enter String 1 : ");
    gets(s1);
    printf("Enter String 2 : ");
    gets(s2);
    printf("\n Length of String 1 : %d",slen(s1));
    printf("\n Length of String 2 : %d",slen(s2));
    if(scomp(s1,s2))
    {
        printf("\n The Strings '%s','%s' are equal",s1,s2);
    }
    else
    {
        printf("\n The Strings '%s','%s' are not equal",s1,s2);
    }
    scat( s1, s2);
    printf("\n The Concatenated String is %s \n",s1);
}
