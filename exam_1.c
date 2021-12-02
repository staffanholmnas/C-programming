#include <stdio.h>

int main()
{
	// task 1

	srand(time(NULL)); // randomize for each run
	
	int range1, range2;
	
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
	
	printf("The selected range is %d to %d", range1, range2);

	return 0;
}
