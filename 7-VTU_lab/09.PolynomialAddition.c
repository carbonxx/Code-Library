/*
9 Design, Develop and Implement a Program in C for the following operations
on Singly Circular Linked List (SCLL) with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-
4yz5+3x3yz+2xy5z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and
store the result in POLYSUM(x,y,z)
Support the program with appropriate functions for each of the above
operations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct poly_node
{
	float coef;
	int expx;
	int expy;
	int expz;
	struct poly_node *link;
} POLY;

POLY *getNode();
void read_poly(POLY *head, int n);
void print_poly(POLY *head);
POLY *add_poly(POLY *h1, POLY *h2);
int compare(POLY *temp1, POLY *temp2);
void attach(float cf, POLY *exptemp, POLY **tempres);
POLY* delete(POLY *head, POLY *temp);
void evaluate(POLY *head);

void main()
{
	int n1, n2;
	POLY *POLY1 = getNode();
	POLY *POLY2 = getNode();
	POLY *POLYSUM = getNode();
	
	POLY1->expx = -1;
	POLY1->link = POLY1;
	POLY2->link = POLY2;
	POLYSUM->link = POLYSUM;
	printf("\nEnter the number of terms for both polynomials\n");
	scanf("%d%d",&n1, &n2);
	printf("\nEnter 1st Polynomial\n");
	read_poly(POLY1, n1);
	printf("\n1st Polynomial is\n");
	print_poly(POLY1);
	printf("\nEnter 2nd Polynomial\n");
	read_poly(POLY2, n2);
	printf("\n2nd Polynomial is\n");
	print_poly(POLY2);
	POLYSUM = add_poly(POLY1, POLY2);
	printf("\nThe Resultant polynomial is\n");
	print_poly(POLYSUM);
	evaluate(POLYSUM);
}

POLY *getNode()
{
	POLY *temp = (POLY *) malloc(sizeof(POLY));
	if(temp == NULL)
	{
		printf("No Memory\n");
		exit(0);
	}
	return temp;
}

void read_poly(POLY *head, int n)
{
	int i;
	POLY *new = NULL;
	POLY *temp = head;
	for(i=0; i<n; i++)
	{
		new = getNode();
		printf("Enter Coef and Exps\n");
		scanf("%f%d%d%d", &(new->coef), &(new->expx), &(new->expy), &(new->expz));
		(temp->link) = new;
		temp = temp->link;
	}
	temp->link = head;
	return;
}

void print_poly(POLY *head)
{
	POLY *temp = head->link;
	while(temp != head)
	{
		printf("%f*X^%d*Y^%d*Z^%d\t", temp->coef, temp->expx, temp->expy, temp->expz);
		temp = temp->link;
	}
	printf("\n");
	return;
}

POLY *add_poly(POLY *h1, POLY *h2)
{
	float cf;
	POLY *temp1 = h1->link, *temp2 = NULL;
	POLY *result = getNode();
	POLY *tempres = result;
	while(temp1 != h1)
	{
		temp2 = h2->link;
		while(temp2 != h2)
		{
			switch(compare(temp1, temp2))
			{
				case 1: 
					cf = temp1->coef + temp2->coef;
					if(cf)
					{
						attach(cf, temp1, &tempres);
					}
					temp1 = temp1->link;
					h2 = delete(h2, temp2);
					temp2 = h2->link;
					break;
						
				case 2: 
					temp2 = temp2->link;
					break;
			}
		}
		if(temp1 != h1)
		{
			attach(temp1->coef, temp1, &tempres);
			temp1 = temp1->link;
		}
	}
	temp2 = h2->link;
	while(temp2 != h2)
	{
		attach(temp2->coef, temp2, &tempres);
		temp2 = temp2->link;
	}
	tempres->link = result;
	return result;	
}

int compare(POLY *temp1, POLY *temp2)
{
	if((temp1->expx == temp2->expx) && (temp1->expy == temp2->expy) && (temp1->expz == temp2->expz))
	{
		return 1;
	}
	return 2;
}

void attach(float cf, POLY *exptemp, POLY **tempres)
{
	POLY *new = getNode();
	new->coef = cf;
	new->expx = exptemp->expx;
	new->expy = exptemp->expy;
	new->expz = exptemp->expz;
	(*tempres)->link = new;
	*tempres = new;
	return;
}

POLY* delete(POLY *head, POLY *temp)
{
	POLY *previous = head, *present = head->link;
	while(present != temp)
	{
		previous = present;
		present = present->link;
	}
	previous->link = present->link;
	free(present);
	return head;
}

void evaluate(POLY *head)
{
	float result = 0.0;
	int x,y,z;
	POLY *temp = head->link;
	printf("\nEnter exponents\n");
	scanf("%d%d%d", &x, &y, &z);
	while(temp != head)
	{
		result += (temp->coef)*pow(x, temp->expx)*pow(y, temp->expy)*pow(z, temp->expz);
		temp = temp->link;
	}
	printf("\nResult after evaluation is %f\n", result);
	return;
}
