#include <stdio.h>


int main()
{

	// set 4 exercise 8
	/*
	Your array has these values
	1, 2, 5, 8, 4, 2, 3, 22, 33, 11, 0, 5	

	Write a program that tells how many values are bigger than 10.
	*/
	
	int vals[] = {1, 2, 5, 8, 4, 2, 3, 22, 33, 11, 0, 5};
	int over_10 = 0;
	int i;
	int amount = sizeof(vals)/sizeof(vals[0]); // size of array
	printf("amount of elements in array is %d \n", amount);
	
	for(i = 0; i < amount; i++)
		if(vals[i] > 10)
			over_10++;
			
	printf("We have %d values over 10 \n", over_10);
	
	
	return 0;
}
