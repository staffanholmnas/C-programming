#include <stdio.h>

// multiply by 2
void multiplyBy2(int t[], int n);
void print(int t[], int n);

int main()
{
	int vals[] = {2,3,4,555,6666};
	print(vals, 5);
	multiplyBy2(vals, 5);
	printf("\n");
	print(vals, 5);
	
	return 0;
}

void multiplyBy2(int t[], int n)
{
	int i;
	for(i = 0; i < n; i++)  // reference to array is passed, so the array is changed
		t[i] = 2 * t[i];
}

void print(int t[], int n)
{
	int i;
	for(i = 0; i < n; i++) 
		printf("%d ", t[i]);
}

