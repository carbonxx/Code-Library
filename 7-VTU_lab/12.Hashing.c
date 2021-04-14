/*12. Given a File of N employee records with a set K of Keys(4-digit) which uniquely determine the records in file F. 
Assume that file F is maintained in memory by a Hash Table(HT) of m memory locations with L as the set of memory addresses (2-digit) of locations in HT. 
Let the keys in K and addresses in L are Integers. 
Design and develop a Program in C that uses Hash function H: K → L as H(K)=K mod m (remainder method), and implement hashing technique to map a given key K to the address space L.
Resolve the collision (if any) using linear probing.*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int *ht,c,n,m,flag;
void create()
{
	int i;
	ht=(int*)malloc(m*sizeof(int));
	if(ht==NULL||m==0)
	{
		printf("Hash table is not present\n");
	}
for(i=0;i<m;i++)
	ht[i]=-1;
}
void display()
{
	int i;
	printf("The hash table is\n");
	for(i=0;i<m;i++)
	{
		printf("%d %d\n",i,ht[i]);
	}
}
void insert(int key)
{
	int j;
	j=key%m;
	while(ht[j]!=-1)
	{
		j=(j+1)%m;
		flag=1;
	}
	if(flag)
	{
		printf("Collision is detected and it is solved using linear probing\n");
		flag=0;
	}
	ht[j]=key;
	display();
	c++;
}
void main()
{
	int i,key;
	printf("Enter the number of employees\n");
	scanf("%d",&n);
	printf("Enter the memory size\n");
	scanf("%d",&m);
	create();
	for(i=0;i<n;i++)
	{
		if(c!=m)
		{
			printf("Enter the key\n");
			scanf("%d",&key);
			insert(key);
		}

else
			printf("The hash table is full\n");
	}
}

