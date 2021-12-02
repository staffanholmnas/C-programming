#include <stdio.h>
#include <math.h>

int main()
{
	// Set 3
	// 16
	
	// calculate sum of even numbers between 2-40
	
	int i;
	int sum = 0;
	
	for(i = 2; i <= 40; i = i + 2)
	{
		sum = sum + i;
	}
	printf("sum of even numbers is %d \n", sum);
	
	return 0;
}
