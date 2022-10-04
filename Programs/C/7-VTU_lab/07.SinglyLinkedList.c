/*
7 Design, Develop and Implement a menu driven Program in C for the
following operations on Singly Linked List (SLL) of Student Data with the
fields: USN, Name, Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of SLL
d. Perform Insertion and Deletion at Front of SLL
e. Demonstrate how this SLL can be used as STACK
f. Exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct stud
{
    char name[25],usn[12],branch[10],phon[11];
    int sem;
    struct stud *next;
};
struct stud *head=0,*temp,*newnode;

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void main()
{
    int choice,i,n;
    while(1)
    {
        printf (" -------------------SLL MENU------------------- \n");
        printf (" |    1   :   Create                           | \n");
        printf (" |    2   :   Display                          | \n");
        printf (" |    3   :   Insert at the begining           | \n");
        printf (" |    4   :   Insert at the end                | \n");
        printf (" |    5   :   Insert at specified position     | \n");
        printf (" |    6   :   Delete from begining             | \n");
        printf (" |    7   :   Delete from the end              | \n");
        printf (" |    8   :   Delete from specified position   | \n");
        printf (" |    9   :   Exit                             | \n");
        printf (" ----------------------------------------------- \n");
        printf("\nEnter your Choice : ");
        scanf("%d",&choice);
        switch(choice)
         {
            case 1: printf("Enter number of students :");
                    scanf("%d",&n);
                    for(i=0;i<n;i++) 
                   {
                      create();
                   }
                        break;
            case 2: display();
                        break;
            case 3: insert_begin();
                        break;
            case 4: insert_end();
                        break;
            case 5: insert_pos();
                        break;
            case 6: delete_begin();
                        break;
            case 7: delete_end();
                        break;
            case 8: delete_pos();
                        break;
            case 9: exit(0);
                        break;
            default: printf("!! Invaild Choice !! \n");
                        break;
        }
    }
}
void create()
{
    newnode=(struct stud *)malloc(sizeof(struct stud));
    printf("<--Enter student details-->\n");
    printf("Name:");
    scanf("%s",newnode->name);
    printf("USN:");
    scanf("%s",newnode->usn);
    printf("Branch:");
    scanf("%s",newnode->branch);
    printf("Phone NO:");
    scanf("%s",newnode->phon);
    printf("SEM:");
    scanf("%d",&newnode->sem);
    newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}
void display()
{
    struct stud *ptr;
    if(head==0)
    {
        printf("!! List is empty !!\n");
    }
    else
    {
        ptr=head;
        printf("<--The List elements are--> \n");
        while(ptr!=0)
        {
            printf("Name     : %s \n",ptr->name);
            printf("USN      : %s \n",ptr->usn);
            printf("Branch   : %s \n",ptr->branch);
            printf("Phone No : %s \n",ptr->phon);
            printf("Semester : %d \n",ptr->sem);
            printf("------------------------------------------------------\n");
            ptr=ptr->next;
        }
    }    
}
void insert_begin()
{
    newnode=(struct stud *)malloc(sizeof(struct stud));
    printf("<--Enter student details-->\n");
    printf("Name:");
    scanf("%s",newnode->name);
    printf("USN:");
    scanf("%s",newnode->usn);
    printf("Branch:");
    scanf("%s",newnode->branch);
    printf("Phone NO:");
    scanf("%s",newnode->phon);
    printf("SEM:");
    scanf("%d",&newnode->sem);
    newnode->next=head;
    head=newnode;
}

void insert_end()
{
    newnode=(struct stud *)malloc(sizeof(struct stud));
    printf("<--Enter student details-->\n");
    printf("Name :");
    scanf("%s",newnode->name);
    printf("USN :");
    scanf("%s",newnode->usn);
    printf("Branch :");
    scanf("%s",newnode->branch);
    printf("Phone NO :");
    scanf("%s",newnode->phon);
    printf("SEM :");
    scanf("%d",&newnode->sem);
    newnode->next=0;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}    

void insert_pos()
{
    newnode=(struct stud *)malloc(sizeof(struct stud));
    int pos,i=1;
    printf("Enter the posistion : ");
    scanf("%d",&pos);
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    printf("<--Enter student details--> \n");
    printf("Name :");
    scanf("%s",newnode->name);
    printf("USN :");
    scanf("%s",newnode->usn);
    printf("Branch :");
    scanf("%s",newnode->branch);
    printf("Phone NO :");
    scanf("%s",newnode->phon);
    printf("SEM :");
    scanf("%d",&newnode->sem);
    newnode->next=temp->next;
    temp->next=newnode;
}
void delete_begin()
{
    if(head==0)
    {
        printf("!! List is empty !!\n");
        return;
    }    
    else
    {
        temp=head;
        head=head->next;
        printf("The Student deleted data is : %s\n",temp->name);
        free(temp);
    }
}
void delete_end()
{
    struct stud *prevnode;
    temp=head;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
        return;
    }    
    else if(temp==head)
    {
        head=0;
        printf("The deleted data from the end : %s\n",temp->name);
        free(temp);    
    }
    else
    {
        prevnode->next=0;
        printf("The deleted element : %s\n",temp->name);
        free(temp);
    }
}
void delete_pos()
{
  struct stud *nextnode;
  int pos,i=1;
  temp=head;
  printf("Enter position :");
  scanf("%d",&pos);
  while(i<pos-1)
  {
      temp=temp->next;
      i++;
  }
  nextnode=temp->next;
  temp->next=nextnode->next;
  printf("The deleted element is : %s\n",nextnode->name);
  free(nextnode);
}