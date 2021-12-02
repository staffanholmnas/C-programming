#include <stdio.h>

void sum(int *a);

void array(int *a); // note that no [] are needed here

int *returnArray();

int main()
{
	// pointers
	int number = 90;
	int *ptr = &number;
	printf("adress of number is %x \n", ptr); // address in hexadecimal %x
	
	*ptr = 120;
	printf("value of number is %d = %d \n", *ptr, number);

	*ptr = 140;
	printf("value of number is %d = %d \n", *ptr, number);
	printf("----\n");
	
	// pointers in sum function
	int num = 3;
	sum(&num);
	printf("%d \n", num );
	printf("----\n");
	
	// function with array pointer
	int arr[4];
	array(arr); // easily do stuff to the array with pointers!!!
	int i;
	
	for(i = 0; i < 4; i++)
		printf("%d \n", arr[i]);
	
	printf("----\n");
	
	// return pointer to an array
	int *a;
	
	a = returnArray();
	
	for(i = 0; i < 6; i++)
		printf("%d \n", a[i]);
	
	return 0;
}

void sum(int *a)
{
	*a = *a + 4;
}

void array(int *a)
{
	int i;
	for(i = 0; i < 4; i++)
		a[i] = i * 2; // no need to point to array here
}

int *returnArray()
{
	static int array[] = {6, 5, 4, 3, 2, 1}; // has to be static here
	return array;
}

