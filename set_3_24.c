#include <stdio.h>
#include <stdlib.h>


int main()
{
	// set 3 exercise 24
	// bonus - generate lotto row
	
	// 40 numbers, choose 7
	
	srand(time(NULL)); // reset random to get unique values on every run
	int row[7];
	int randomnumber;
	int found = 0;
	int i, j;
	
	for (i = 0; i < 7; i++)
	{
		int random = rand();
		randomnumber = random % 40 + 1; // scaling to amount of balls
		
		for (j = 0; j < i; j++)	
		{
			if (row[j] == randomnumber) // Check if it's already in the row
			{
				found = 1;
				break;
			}
		}
		if (found == 1) // Don't add it to row if it's already there, try again instead.
		{
			i--;
			found = 0;
		}
		else
			row[i] = randomnumber;
	}

	for (i = 0; i < 7; i++)
		printf("%d \n", row[i]);
	
	return 0;
}
