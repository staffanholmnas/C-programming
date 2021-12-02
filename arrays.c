#include <stdio.h>

int main()
{
	// arrays
	
	int values1[4];
	values1[0] = 99;
	values1[1] = -8;
	values1[2] = 1234;
	values1[3] = 0;
	
	int array_size = sizeof(values1); // each int is 4 bytes = 16 bytes
	int element_size = sizeof(values1[0]); // first element is 4 bytes
	int amount = array_size/element_size; // number of elements in array = 16 / 4 = 4
	
	printf("size of whole array is %d \n", array_size);
	printf("size of one element is %d \n", element_size);
	printf("amount of elements in array is %d \n", amount);
	
	int a[] = {1,2,3,4};
	printf("%d \n\n", a[0]);	
	
	int i;
	for (i = 0 ; i < 4; i++)
		printf("%d \n", values1[i]);
	
	// sizeof
	printf("size of datatype double is %d \n", sizeof(double));
	
	int size = 100000; // memory needed 8 * 100000 = 800000 bytes = 800KB
	size = 200000; // 1.6 MB
	size = 250000; // 2 MB
	// size = 260000; // too big array, stack overflow!
	double values3[size];
	values3[0] = 67.88;
	printf("Value is %f \n", values3[0]);
	
	return 0;
}
