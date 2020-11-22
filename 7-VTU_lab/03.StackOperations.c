
/*
3 Design, Develop and Implement a menu driven Program in C for the
following operations on STACK of Integers (Array Implementation of Stack
with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above
operations
*/

#include <stdio.h>
#define MAXSIZE 5
 
struct stack
{
    int a[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;
 
void push();
int  pop();
void display();
void palindrome();
 
void main ()
{
    int choice;
    int option = 1;
    s.top = -1;
 
   while (option)
    {
       printf (" --------STACK OPERATION------- \n");
        printf (" |    1   :   PUSH            | \n");
        printf (" |    2   :   POP             | \n");
        printf (" |    3   :   DISPLAY         | \n");
        printf (" |    4   :   PALINDROME      | \n");
        printf (" |    5   :   EXIT            | \n");
        printf (" ------------------------------ \n");
        printf ("Enter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3: display();
            break;
        case 4: palindrome();
             break;
        case 5:
             return;
        default : printf("Invalid Input");
        //fflush (stdin);
        }
    }
}
/*  Function to push/add an element to the stack */
void push()
{
    int num;
    if (s.top == (MAXSIZE - 1))
    {
        printf ("!! Stack is Full !!\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed :");
        scanf ("%d", &num);
        s.top = s.top + 1;
        s.a[s.top] = num;
    }
    return;
}
/*  Function to pop/delete an element from the stack */
int pop()
{
    int num;
    if (s.top == - 1)
    {
        printf ("!! Stack is Empty !!\n");
        return(s.top);
    }
    else
    {
        num = s.a[s.top];
        printf ("Poped out element : %d  ", s.a[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}
/*  Function to display the elements of the stack */
void display()
{
    int i;
    if (s.top == -1)
    {
        printf("!! Stack is empty !!\n");
        return;
    }
    else
    {
        printf("<--Stack Elements--> \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.a[i]);
        }
    }
    printf ("\n");
}
/*  Function to check the stack is a palindrome or not */
void palindrome()
{
     int i,j,flag;
    if (s.top==-1)
    {
        printf ("!! Stack is empty !!\n");
        
    }
    else
    {
       for(i=0,j=s.top;i<=((j/2)+1);i++,j--)
       {
          if(s.a[i]==s.a[j])
         {
            continue;
         }
         else
         {
            flag=1;
            break;
         }
       }
      if(flag==1)
      {
        printf("Stack is not a Palindrome \n");
        flag=0;
      }
      else
     {
        printf("Stack is a Palindrome \n");
     }
   }
}