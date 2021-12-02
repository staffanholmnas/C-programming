#include <stdio.h>

int main()
{
	// exercise 1
	
	int sec = 47;
	int min = 58;
	int hour = 2;
	int sec2 = 0;
	int sec3 = 0;
	int sec4 = 0;
	int input = 0;
	
	sec2 = sec + (min * 60) + (hour * 3600);
	
	printf("The time is now %d : %d : %d \n", hour, min, sec);
	
	do
	{
		printf("Give seconds between 300 and 3000 to add to time: \n");
		scanf("%d", &input);
	}
	while (input < 300 || input > 3000);
	
	sec3 = input + sec2; // add user-given seconds to time
		
	hour = sec3 / 3600;
	sec3 = sec3 - hour * 3600;
	min = sec3 / 60;
	sec4 = sec3 - min * 60; 
	
	printf("%d : %d : %02d", hour, min, sec4); // %02d adds leading zeroes
	printf("\n----------------------\n");
	
	//---------------------------------------
	// exercise 2
	
	
	int input2;
	int sum = 0;
	double avg = 0;
	int biggest = 0;
	int total = 0;
	
	while (1)
	{
		printf("Give whole numbers, 0 quits:\n");
		scanf("%d", &input2);
		if (input2 < 0)
		{
			printf("No negative numbers!\n");
			continue;
		}
		if (input2 == 0)
			break;
		sum += input2;
		if (input2 > biggest)
			biggest = input2;
		total++;
	}
	
	avg = 1.0 * sum / total;
	
	printf("The sum is: %d\n", sum);
	printf("The avgerage is: %f\n", avg);
	printf("The biggest value is: %d\n", biggest);
	
	printf("\n----------------------\n");
	
	//---------------------------------------
	// exercise 3
	
	char a, b, c;
	int row,col;
	
	getchar();
	printf("Play Sukoku!\nGive the first letter:\n");
	scanf("%c", &a);
	
	getchar();
	printf("Give the second letter:\n");
	scanf("%c", &b);
	
	getchar();
	printf("Give the third letter:\n");
	scanf("%c", &c);
	
	// printf("%c %c %c\n",a ,b ,c);
	
	char arr[3][3];
	
	arr[0][0] = a; arr[0][1] = b; arr[0][2] = c;
	arr[1][0] = b; arr[1][1] = c; arr[1][2] = a;
	arr[2][0] = c; arr[2][1] = a; arr[2][2] = b;
		
	// print sudoku solution
	for(row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			printf("%c ", arr[row][col]);
		}
		printf("\n");
	}	
	
	// create table with only 3 values
	printf("\n");
	
	arr[0][0] = a; arr[0][1] = '_'; arr[0][2] = '_';
	arr[1][0] = '_'; arr[1][1] = '_'; arr[1][2] = a;
	arr[2][0] = '_'; arr[2][1] = '_'; arr[2][2] = b;
		
	// print sudoku table with 3 values
	for(row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			printf("%c ", arr[row][col]);
		}
		printf("\n");
	}	
	
	return 0;
}
