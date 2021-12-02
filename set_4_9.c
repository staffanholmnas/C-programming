#include <stdio.h>
#include <math.h>

int main()
{
	// set 4 exercise 9 bonus
	// calculate standard deviation
	int a[] = {93, 18, 15, -4, 12, 55, 68, 33};
	int size_of_a = sizeof(a)/sizeof(a[0]); // number of elements in array 
	printf("size %d \n", size_of_a);
	double std_dev;
	int i;
	int sum = 0;
	double var = 0;
	double avg = 0;
	// calculate average
	for(i = 0; i < size_of_a; i++)
		sum += a[i];
	
	printf("sum: %d \n", sum);
	avg = 1.0*sum / size_of_a;
	printf("avg: %f \n", avg);
	
	// calculate variance
	for(i = 0; i < size_of_a; i++)
		var += (a[i] - avg)*(a[i] - avg);
	
	printf("variance: %f \n", var);
	
	// calculate standard deviation
	std_dev = sqrt(var/size_of_a);
	printf("standard deviation: %f\n", std_dev);
		
	return 0;
}
