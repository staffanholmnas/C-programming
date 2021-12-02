#include <stdio.h>
#include <stdlib.h> // random

int main()
{
	// set 4 exercise 1
	
	/*
	1
	Create a program that
	a) fills an array with random numbers
	b) prints an array
	c) calculates the sum
	d) calculates the average
	e) finds the max and min
	f) finds a spesific values
	g) tells how many times some value exists in an array
	*/
	
	//a-b)
	int table1[6];	
	int i;
	for (i = 0; i < 6; i++)
		table1[i] = rand();
	
	for (i = 0; i < 6; i++)
		printf("%d \n", table1[i]);
	//c)	
	int sum = 0;
	for (i = 0; i < 6; i++)
		sum += table1[i];
		
	printf("sum is %d \n", sum);
	
	//d)
	float avg = sum/6.0;
	printf("avg is %f \n", avg);
	
	//e)
	int min = table1[0];
	int max = table1[0];
	for (i = 1; i < 6; i++)
	{
		if (table1[i] < min)
			min = table1[i];
		if (table1[i] > max)
			max = table1[i];
	}
	printf("min value is %d and max value is %d \n", min, max);
	
	//f)
	
	int findthis = table1[1];
	int position = -1;
	for (i = 0; i < 6; i++)
	{
		if (table1[i] == findthis)
		{
			position = i;
			break;
		}
		
	}
	
	if (position == -1)
		printf("The value was not found :( \n");
	else
		printf("The value was found, place is %d \n", position);
		
	//g)
	
	int table2[] = {10, 20, 2, 5, 3, 10, 5, 5};
	
	int amount = 0;
	findthis = 5;
	for (i = 0; i < 8; i++)
	{
		if (table2[i] == findthis)
		amount++;
	}
	printf("Value %d occured %d times \n", findthis, amount);
	return 0;
}
