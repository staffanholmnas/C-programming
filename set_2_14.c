#include <stdio.h>

int main()
{
	// biggest of 3 values
	int a,b,c;
	printf("Enter a value for a:\n");
	scanf("%d",&a);
	
	printf("Enter a different value for b:\n");
	scanf("%d",&b);
	
	printf("Enter a different value for c:\n");
	scanf("%d",&c);
	
	if(a > b)
	{
		if (a > c)
			printf("A is the biggest!\n");
	}
	else if (b > c)
		printf("B is the biggest!\n");
	else
		printf("C is the biggest!\n");
	
	// alternative 2
	if (a > b && a > c)
		printf("A is the biggest!\n");
	else if (b > a && b > c)
		printf("B is the biggest!\n");
	else
		printf("C is the biggest!\n");
	
		
	printf("biggest value is %d \n", max);
	return 0;	
}
