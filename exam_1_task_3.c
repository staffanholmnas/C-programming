#include <stdio.h>

int main()
{
	
	// task 3
	
	// User is asked to give 2 values and your code prints 60 random numbers from given range.
	//E.g user gives values 5 and 50: 60 random values between 5 and 50 are printed.

	srand(time(NULL)); // randomize for each run
	
	int range1, range2;
	int random;
	int interval;
	int i;
	
	printf("give the first value for the beginning of the interval\n");
	scanf("%d", &range1);
	
	do
	{
		printf("give the second value for the end of the interval\n");
		scanf("%d", &range2);
	
		if(range2 <= range1)
			printf("The second value should be bigger than the first\n");
	}
	while(range2 <= range1);
	
	printf("The selected range is %d to %d \n", range1, range2);
	
	for (i = 0; i < 60; i++)
	{
		random = rand();
		interval = range2 - range1;
		random = (random % (interval + 1)) + range1; // scaling
		printf("%d \n", random);
	}
		
	return 0;
}
