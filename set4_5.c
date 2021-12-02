#include <stdio.h>

int main()
{
	long long int arr[5][2];
	int row, col;
	int input;
	int i;
	
	arr[0][0] = 1970; arr[0][1] = 3706618163;
	arr[1][0] = 1980; arr[1][1] = 4453831714;
	arr[2][0] = 1990; arr[2][1] = 5278639789;
	arr[3][0] = 2000; arr[3][1] = 6082966429;
	arr[4][0] = 2010; arr[4][1] = 6956823603;
	
	for(row = 0; row < 5; row++)
	{
		for (col = 0; col < 2; col++)
		{
			printf("%lld ", arr[row][col]);
		}
		printf("\n");
	}
	
	
	printf("choose decade from 1970s to 2010:");
	scanf("%d", &input);
	printf("you chose %d \n", input);
	
	for (i = 0; i < 5; i++)
		if (input == arr[i][0])
			printf("Population for year %d is %lld\n", input, arr[i][1]);
	
	return 0;
}
