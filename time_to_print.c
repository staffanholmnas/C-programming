#include <stdio.h>


int main()
{
	// print benchmark
	int secs1 = time(NULL); // start first timer at seconds since 1.1.1970 00:00
	int i;
	int sum = 0;
	for (i = 0; i < 100000 ;i++)
	{
		sum+=i;
		printf("sum is now \n", sum); // printing 100k iterations
	}
	
	int secs2 = time(NULL); // start second timer
	
	int elapsedtime = secs2 - secs1;
	printf("loop time %d seconds\n", elapsedtime); // printing takes 7 seconds for 100k iterations!!!
	
	return 0;
}
