#include <stdio.h>

// array functions

void print(int t[], int n);


int main()
{
	int values[] = {2,3,35,45,46};
	print(values, 5); // note missing square brackets from values, actually points to memory address
	
	return 0;
}

void print(int t[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d \n", t[i]);
}
