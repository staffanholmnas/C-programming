#include <stdio.h>
#include <math.h>

int main()
{
	// Set 3
	// 15
	// sum of 1 to 5 with different loops
	
	int i;
	int sum = 0;
	for (i = 1; i <= 5; i++)
		sum += i; 
		
	printf("sum is %d \n", sum);
	
	int j = 1;
	int sum2 = 0;
	while (j <= 5)
	{
		sum2 += 1;
		j++;
	}
	
	printf("sum is %d \n", sum2);
	
	int k = 1;
	int sum3 = 0;
	do
	{
		sum3 += k;
		k++;
	}
	while (k <= 5);
	
	printf("sum is %d \n", sum3);
	
	return 0;
}
