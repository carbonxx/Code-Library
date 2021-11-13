/*
6 Design, Develop and Implement a menu driven Program in C for the
following operations on Circular QUEUE of Characters (Array
Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above
operations
*/

#include<stdio.h>
#include<stdlib.h>
#define size 10

void cqinsert(char queue[], int *rear, int *count);
void cqdelete(char queue[], int *front, int *count);
void display(char queue[], int front, int count);

void main()
{
	char queue[size];
	int front = 0, rear = -1, ch, count = 0;
	for(;;)
	{
		printf("\nMenu\n");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				if(count == size)
					printf("Queue is Full\n");
				else
					cqinsert(queue, &rear, &count);
				break;
			case 2:
				if(count == 0)
					printf("Queue is Empty\n");
				else
					cqdelete(queue, &front, &count);
				break;
			case 3:
				if(count == 0)
					printf("Queue is Empty\n");
				else
					display(queue, front, count);
				break;
			case 4:
				exit(0);
		}
	}
}

void cqinsert(char queue[], int *rear, int *count)
{
	char ele;
	printf("Enter a Character\n");
	scanf(" %c", &ele);
	*rear = (*rear + 1) % size;
	queue[*rear] = ele;
	(*count)++;
}

void cqdelete(char queue[], int *front, int *count)
{
	printf("Deleted Character is %c\n", queue[*front]);
	*front = (*front + 1) % size;
	(*count)--;
}

void display(char queue[], int front, int count)
{
	int i;
	printf("The Characters are\n");
	for(i=0; i<count; i++)
	{
		printf("%c\t", queue[front]);
		front = (front + 1) % size;
	}
	printf("\n");
}
