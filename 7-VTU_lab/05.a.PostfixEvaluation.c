/*
5 Design, Develop and Implement a Program in C for the following Stack
Applications
a. Evaluation of Suffix expression with single digit operands and operators:
+, -, *, /, %, ^
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MS 50
char postfix[50];
struct stack
{
    int top;
    int item[MS];
}s;

void push(int value)
{
    if(s.top==(MS-1))
    {
        printf("Stack s full \n");
    }
    else
    {
        s.item[++s.top]=value;
    }
}
int pop()
{
    if(s.top==-1)
    {
        printf("Stack is Empty \n");
        exit(0);
    }
    return(s.item[s.top--]);
}   
int empty()
{
    if(s.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int operation(int a,int b,char c)
{
    switch(c)
    {
        case '^': return(pow(a,b));
        case '*': return(a*b);
        case '%': return(a%b);
        case '/': return(a/b);
        case '+': return(a+b);
        case '-': return(a-b);
    }
}
int evaluate()
{
    int i,a,b,ans,value;
    char symb;
    for(i=0;postfix[i]!='\0';i++)
    {
        symb=postfix[i];
        if((symb>='0')&&(symb<='9'))
        {
            push((int)(symb-'0'));
        }
        else
        {
            a=pop();
            b=pop();
            value=operation(b,a,symb);
            push(value);
        }
    }
    ans=pop();
return ans;
}
void main()
{
    s.top=-1;
    int ans;
    printf("Enter the postfix expression : ");
    gets(postfix);
    ans = evaluate();
    printf("The resultant ans is %d ",ans);
}