#include <stdio.h>

int main()
{
	// nested loops
	
	// multiplication table 1...6
	
	int i, j;
	
	for (i = 1; i <= 6; i++)
	{
		for(j = 1; j <= 6; j++)
			printf("%d \t ", i*j);
			printf("\n");
	}
	return 0;
}
