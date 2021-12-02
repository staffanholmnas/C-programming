#include <stdio.h>
#include <stdlib.h>

int main()
{
	// rand() 0 - 32000
	
	// print 10 random numbers
	
	int i;
	for(i = 0; i <= 10; i++)
		printf("%d \n", rand());
		
	// print 5 random numbers that are between 1 and 5
	printf("\n");
	
	for(i = 0; i < 10; i++)
	{
		int value1 = rand();
		printf("%d \n", value1);
		int value2 = value1 % 5 + 1; // scaling
		printf("%d \n", value2);
	}
	
	return 0;
}
