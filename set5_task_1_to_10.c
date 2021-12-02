#include <stdio.h>

// 1. Calculates the sum of 2 integers and prints out the result.
void sumOf2(int a, int b);

// 2. Returns the sum of 2 integers.
int returnedSumOf2(int a, int b);

// 3. Returns the average of 2 integers
float averageOf2(int a, int b);

// 4. Returns the average of 4 floating point values.
float averageOf4(float a, float b, float c, float d);

// 6. Returns the factorial.
int factorial(int f);

// 7. Returns the biggest of 2 integers.
int biggest(int a, int b);

// 8. Returns the biggest of 3 integers.
int biggestOf3(int a, int b, int c);

// 10. Converts inches to centimeters.
float convertInchToCm(float inch);

int main()
{
	// Set 5
	
	sumOf2(55, 99); // task 1
	printf("returned sum is %d \n", returnedSumOf2(34, 53)); // task 2
	printf("returned average is %0.1f \n", averageOf2(34, 15));	// task 3
	printf("returned average is %0.2f \n", averageOf4(71, 52, 63, 84));	// task 4
	printf("returned factorial is %d \n", factorial(7)); // task 6
	printf("the biggest of 2 values is %d \n", biggest(15, 9)); // task 7
	printf("the biggest of 3 values is %d \n", biggestOf3(232, 74, 101)); // task 8
	printf("The value in cm is %0.3f \n", convertInchToCm(32.3)); // task 10
	
	return 0;
}

void sumOf2(int a, int b)
{
	int s = a + b;
	printf("sum is %d \n", s);
}

int returnedSumOf2(int a, int b)
{
	int s = a + b;
	return s;
}

float averageOf2(int a, int b)
{
	float avg = (a + b) / 2.0;
	return avg;
}

float averageOf4(float a, float b, float c, float d)
{
	float avg = (a + b + c + d) / 4.0;
	return avg;
}

int factorial(int f)
{
	int result = 1;
	int i;
	for(i = 1; i <= f; i++)
		result *= i; 	
	return result;
}

int biggest(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}

int biggestOf3(int a, int b, int c)
{
	int biggest = a;
	if (a > b && a > c)
		biggest = a;
	else if (b > c)
		biggest = b;
	else
		biggest = c;
	
	return biggest;
}

float convertInchToCm(float inch)
{
	float cm = inch * 2.54;
	return cm;
}


