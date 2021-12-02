#include <stdio.h>
#include <math.h>

int main()
{
	// Set 3
	// exercise 17
	
	// calculate sum 5, 10, 15, ... 100
	
	int i;
	int sum = 0;
	
	for(i = 5; i <= 100; i = i + 5)
	{
		sum = sum + i;
	}
	printf("sum is %d \n", sum);
	
	return 0;
}
