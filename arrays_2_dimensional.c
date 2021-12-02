#include <stdio.h>

int main()
{
	// arrays
	// 2-dimensional
	// 2 * 3 => 2 rows, 3 columns
	
	int matr1[2][3];
	/*
		2 2 2
		5 5 5
	*/
	
	matr1[0][0] = 2; matr1[0][1] = 2; matr1[0][2] = 2;
	matr1[1][0] = 5; matr1[1][1] = 5; matr1[1][2] = 5;
	
	int r, c;
	
	for(r = 0; r < 2; r++)
		for (c = 0; c < 3; c++)
			printf("%d \n", matr1[r][c]);
	
	// print formatted as array
	for(r = 0; r < 2; r++)
	{
		for (c = 0; c < 3; c++)
		{
			printf("%d ", matr1[r][c]);
		}
		printf("\n");
	}
	
	return 0;
}
