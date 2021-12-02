#include <stdio.h>
#include <stdlib.h> // for malloc

int main()
{
	// dynamic memory allocation
	// malloc allocates memory
	int * p1 = malloc(4); // sizeof(int) = 4 bytes
	*p1 = 99;
	
	printf("memoryplace p1 has address %d and in that place there is a value %d \n", p1, *p1);
	
	free(p1); // deallocate or free memory
	
	short * p2 = malloc(2); // sizeof(short)
	printf("memoryplace p1 has address %d\n", p2);
	
	int * array1 = calloc(5, 4); // calloc is used for arrays, (<elements>, <size of each element>)
	
	// calloc can be used to dynamically resize arrays. Stored in memory heap, meaning more RAM available.
	
	int i;
	for (i = 0; i < 5; i++)
		array1[i] = rand();
		
	for (i = 0; i < 5; i++)
		printf("%d ", array1[i]);
	
	printf("\n");
	
	int size = 250000; // stack overflow if over about 250000
	double values1[size]; // 250000 * 8 => over 2 megabytes, local stack is used, meaning less memory. 
	// Local variables are also stored in the stack. Too big arrays will overflow the stack.
	values1[0] = 123;
	printf("%f \n", values1[0]);
	
	// compare with calloc, no stack overflow
	
	int size2 = 2000000000;
	
	double * values2 = calloc(size2, 8); // memory needed is 2000000000 * 8 => 16 000 megabytes = 16 gigabytes
	values2[0] = 456;
	printf("%f \n", values2[0]);
	
	return 0;
}
