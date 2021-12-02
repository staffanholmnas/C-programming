#include <stdio.h>


int main()
{
	// Sorting
	// Selection sort
	
	int a[] = {2, 3, 4, 888, -8, 900, 67};
	int i, j;
	for (i = 0; i < 7; i++)
		for (j = i + 1; j < 7; j++)
			if (a[j] < a[i])
			{
				// swap
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
	
	for (i = 0; i < 7; i++)
		printf("%d ", a[i]);
		
	return 0;
}
