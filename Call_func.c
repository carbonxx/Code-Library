//Volume Calculation using call function
#include<stdio.h>
#include <string.h>
void explanation();
void printResults(int ,int ,int ,int);
void volume_calc();
int length,width,height,total=-1;
void printResults(int length,int widht,int height,int volume)
{
	if(total==-1)
	{
		printf("Length: %d\nWidht: %d\nHeight: %d\nVolume: %d\n",length,widht,height,volume);
		total=volume;
	}
	else{
		printf("Length: %d\nWidht: %d\nHeight: %d\nVolume: %d\n",length,widht,height,volume);
		total+=volume;
		printf("Total Volume %d",total);
	}
}
void volume_calc()
{
	printResults(length,width,height,length*width*height);
}
void explanation()
{
	printf("Enter length of the room: ");
	scanf("%d",&length);
	printf("Enter width of the room: ");
	scanf("%d",&width);
	printf("Enter height of the room: ");
	scanf("%d",&height);
}
void main()
{
	int i;
	for(i=1;i<=2;i++)
	{
		explanation();
		volume_calc();
	}
}
