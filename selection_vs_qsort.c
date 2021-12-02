#include <stdio.h>
#include <stdlib.h>

void fillArray(int t[], int n);

void printArray(int t[], int n);

void sort1(int t[], int n); // selection sort

int cmpFunc (const void * a, const void * b); // qsort


int main()
{
	int size = 100000000; 
	// selection sort: 50000 = 6 sec, 100000 = 19 sec, 200000 = 64 sec
	// quick sort: 10000000 = 1 sec,  100000000 = 9 sec, 1000000000 = 86 sec
	//int values [size];
	int * values = calloc(size, 4);
	fillArray(values, size);
	//printArray(values, size);
	
	int time1 = time(NULL);
	//sort1(values, size); // selection sort
	qsort(values, size, sizeof(int), cmpFunc); // qsort
	int time2 = time(NULL);
	
	int elapsed_time = time2 - time1;
	printf("It took %d secs to sort that array \n", elapsed_time);
	
	//printArray(values, size);
	
	return 0;
}

void fillArray(int t[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		t[i] = rand();
}

void printArray(int t[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", t[i]);
		
	printf("\n");
}

void sort1(int t[], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
		{
			if (t[j] < t[i])
			{
				int temp = t[j];
				t[j] = t[i];
				t[i] = temp;
			}
		}
}

int cmpFunc (const void * a, const void * b)
{
	return ( *(int*)a -*(int*)b);
}

