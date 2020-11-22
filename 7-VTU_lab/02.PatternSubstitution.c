/*
2 Design, Develop and Implement a Program in C for the following operations
on Strings
a. Read a main String (STR), a Pattern String (PAT) and a Replace String
(REP)
b. Perform Pattern Matching Operation: Find and Replace all occurrences of
PAT in STR with REP if PAT exists in STR. Report suitable messages in
case PAT does not exist in STR.
Support the program with functions for each of the above operations. Don't
use Built-in functions.
*/
#include<stdio.h>
int m,n,i,j,k,flag;
char str[100],pat[50],rep[50],b[150];
void pmatch()
{
 while(str[n]!='\0')
 {
     if(str[m]==pat[i])
    { 
       m++;
       i++;
      if(pat[i]=='\0')
      {
        flag=1;
        for(k=0;rep[k]!='\0';k++)
        {
          b[j]=rep[k];
          j++;
          n=m;
          i=0; 
        }
      }
    }
    else
   {
    b[j]=str[n];
    j++;
    n++;
    m=n;
    i=0;
   }
 }
  b[j]='\0';
}
void main()
{
   printf("Enter the string : ");
   gets(str);
   printf("Enter the pattern string : ");
   gets(pat);
   printf("Enter the replacing string : ");
   gets(rep);
   pmatch();
   if(flag==1)
   {
    printf("The new string : ");
    puts(b);
    }
    else
    {
     printf("The pattern is not found\n");
     
    }
}
