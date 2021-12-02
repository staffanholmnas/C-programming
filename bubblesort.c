#include <stdio.h>

#define MAX 10 

int a[MAX];
int rand_seed = 10;
int rand(void);

// produces a random number between 0 and 32767
int rand(void)
{
	rand_seed = rand_seed * 1103515245 + 12345;
	return (unsigned int)(rand_seed / 65536) % 32768;
}

int main()
{
	int i, t, x, y;
	
	// fill arrray
	for (i = 0; i < MAX; i++)
	{
		a[i] = rand();
		printf("%d\n", a[i]);
	}
	
	for (x = 0; x < MAX - 1; x++)
	{
		for (y = 0; y < MAX - x -1; y++)
			if (a[y] > a[y + 1])
			{
				t = a[y];
				a[y] = a[y + 1];
				a[y + 1] = t;
			}
	}
	
	// print array
	
	printf("--------------------\n");
	
	for (i = 0; i < MAX; i++)
		printf("%d\n", a[i]);
	
	return 0;
}
