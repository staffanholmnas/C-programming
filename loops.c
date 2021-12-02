#include <stdio.h>
#include <math.h>

int main()
{
	// loops
	// for, while, do-while
	
	int i; //counter variable
	
	// print 1 to 10
	for (i = 1; i <= 10; i++)
		printf("i is now %d \n", i);
	
	// print values 3,9,27 ... 243
	for (i = 3; i <= 243; i = i*3)
		printf("i is now %d \n", i);
	
	// print values 0.5, 2.5, 4.5 ... 20.5
	float j;
	for (j = 0.5; j <= 20.5; j = j + 2)
		printf("j is now %f \n", j);
	
	// calculate the sum of values 0.3, 0.9, 2.7, ... 24.3
	float sum = 0;
	for (j = 0.3; j <= 24.3; j = j * 3)
	{	
		sum = sum + j;
		printf("%f \n", sum);
	}
	
	// while loop
	int k = 1;
	while (k <= 10)
	{
		printf("%d \n", k);
		k++;
	}
	
	// do while
	int p = 1;
	do
	{
		printf("%d \n", p);
		p++;
	}
	while (p <= 10);
	
	return 0;
}
