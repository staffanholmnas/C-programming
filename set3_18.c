#include <stdio.h>

int main()
{
	
	int i;
	int sum = 0;
	float avg;
	int random;
	
	srand(time(NULL));
	
	for (i = 0; i < 50; i++)
	{
		random = rand();
		random = random % 10 + 1;
		sum += random;
	}
	avg = sum / 50.0;
	printf("sum: %d\navg: %1.1f", sum, avg);
	return 0;
}
