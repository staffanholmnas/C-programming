#include <stdio.h>
#include <stdlib.h>

int main()
{
	// rand() 0 - 32000
	
	// throw dice 100 times and calculate sum of different values (1,2,3,4,5,6)
	
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
	int i;
	
	srand(time(NULL)); // resetting random number generator
	// time(NULL) is current time started from 1.1.1970
	
	for(i = 0; i < 100; i++)
	{
		int value1 = rand();
		//printf("%d \n", value1);
		int value2 = value1 % 6 + 1; // scaling
		//printf("%d \n", value2);
		if (value2 == 1)
			n1++;
		if (value2 == 2)
			n2++;
		if (value2 == 3)
			n3++;
		if (value2 == 4)
			n4++;
		if (value2 == 5)
			n5++;
		if (value2 == 6)
			n6++;
	}
	
	printf("%d %d %d %d %d %d", n1,n2,n3,n4,n5,n6);
	
	return 0;
}
