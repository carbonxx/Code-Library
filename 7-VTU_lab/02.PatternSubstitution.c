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
char s[20],pat[20],rep[20],ans[30];
int i,j,k,l,flag;
void pmatch()
{
for(i=0,k=0;s[i]!='\0';i++)
  {
    flag=1;
    for(j=0;pat[j]!='\0';j++)
    {  
      if(s[i+j]!=pat[j])
       { 
         flag=0;
       }
    }
    l=j;
    if(flag)
    {
      for(j=0;rep[j]!='\0';j++,k++)
      {
        ans[k]=rep[j];
      }
      i+=l-1;
    }
    else
    {
      ans[k++]=s[i];
    }
  }
  ans[k]='\0';
  printf("%s",ans);
}
void main()
{
 printf("Enter string: ");
  scanf("%s",s);
  printf("Enter pattern: ");
  scanf("%s",pat);
  printf("Enter replacement: ");
  scanf("%s",rep);
  pmatch();
}