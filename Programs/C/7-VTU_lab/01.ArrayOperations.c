/*
1 Design, Develop and Implement a menu driven Program in C for the
following Array operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.
Support the program with functions for each of the above operations
*/
#include<stdio.h>
#include<stdlib.h>
int array[100];
int size,i ;
int element;
int pos;
int ser;
void create()
{
    printf("Enter the size of the array :");
	scanf("%d",&size);
	printf("Enter the %d elements : ",size);
	for(i=0 ; i<size ; i++)
	{
	  scanf("%d",&array[i]);
	}
	printf("The array is created sucessfully \n");

}
void display()
{

	printf("The array elements\n");
	for(i=0 ; i<size ; i++)
	printf("%d\t",array[i]);
}
void insert()
{
    printf("Enter the element to be inserted : ");
	scanf("%d",&element);
	printf("Enter the position :");
	scanf("%d",&pos);
    if(pos>=0&&pos<=size)
	{
	for(i=size-1;i>=pos;i--)
	{
	 array[i+1]=array[i];
	}
     array[pos]=element;
	 size++;
	 printf("Element is inserted sucessfully \n");
    }
	else
        printf("Enter a valid position \n");
}
void del()
{

	printf("Enter the position of the element to be deleted :");
	scanf("%d",&pos);
    if(pos<=size)
	{
	element=array[pos];
	for(i=pos ; i<size ; i++)
	{
	array[i]=array[i+1];
	} 
    size--;
    printf("deleted element is %d \n",element);
    }
    else
    {
    printf("invalid position\n");
    }
}
void main()
{
	int ch ;
    while(1)
	{
    printf("1:create\n2:insert\n3:display\n4:delete\n5:exit\n");
    printf("Choose the operation :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : create(); break ;
		case 2 : insert(); break;
		case 3 : display(); break;
		case 4 : del(); break;
		case 5 : exit(0);
		default: printf("!!Invalid Choice!!");
    }
	}
}