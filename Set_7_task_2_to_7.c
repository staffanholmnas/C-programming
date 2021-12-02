#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void fillArray(int arr[], int n);
void printArray(int arr[], int n);
int cmpFunc (const void * a, const void * b); // qsort
void bubbleSort(int a[], int size); //bubblesort
int numberOfDigits(int value);
double squareRoot(int value);
double eulersNumber();
double estimatedPi();
double cosine(double value);
int factorial(int value);

int main()
{
	// set 7
	// task 2
	// Program calculates the hypotenuse of an triangle when other sides are given.
	
	// a^2 + b^2 = c^2
	int a = 6;
	int b = 9;
	float hypothenuse = sqrt((float)a * a + b * b);
	
	printf("Hypothenuse: %2.2f\n\n", hypothenuse);

	// task 3
	// A stone is dropped down from the top of Pisa tower. 
	// What is the final speed of the stone and how much time does the fall take?
	
	// v = gt, h = (1/2)gt^2
	const float gravity = 9.8;
	int height = 57;
	float velocity;
	float air_time;
	
	air_time = sqrt(2 * height / gravity);
	velocity = gravity * air_time;
	
	printf("The final speed is %f m/s and the time is %f seconds.\n\n", velocity, air_time);
	
	// task 4
	// Program rounds a double value to a value that has 2 numbers in its fractional part.
	
	double pi = 3.14159265;
	double rounded_pi = roundf(pi * 100)  / 100;
	
	printf("Pi rounded to two decimal places: %2.2f \n\n", rounded_pi);
	
	// task 5
	// Program tells how much time does it take to sort an array of 100000 elements.
	// Compare sorting times to time got from c:s own sort() function.
	
	int size = 100000;
	//int array[size]; // only for smaller arrays
	int * array = calloc(size, 4); // allocate larger arrays on the heap
	
	fillArray(array, size);
	//printArray(array, size); // Do not print large arrays
	
	// timer on
	int time1 = time(NULL);
	
	// bubblesort
	// bubbleSort(array, size); // 30 s
	
	// qsort
	qsort(array, size, sizeof(int), cmpFunc); // 0 s
	
	// timer off
	int time2 = time(NULL);
	int elapsed_time = time2 - time1;
	
	printf("The array was sorted in %d seconds \n\n", elapsed_time);
	
	//printArray(array, size);
	
	// task 6
	// Calculate the square root of some value using numeric method and compare the result
	// to the value got with sqrt() function.
	
	int value = 123456;
	float estimate = squareRoot(value);
	
	printf("The numerically estimated square root is %f and the square root function returns %f \n\n", estimate, sqrt(value));
	
	// task 7
	// Calculate approximations of Nepers's value, pi and cos(0.9) and compare them t values of got from math.h functions.
	
	// e
	printf("The numerically estimated Euler's number is %f and the constant e is %f \n\n", eulersNumber(), M_E);
	
	// pi
	printf("The numerical estimation for Pi using Nilakantha's series is %f and the built-in constant for Pi is %f \n\n", estimatedPi(), M_PI);
	
	// cosine(0.9)
	printf("The numerical estimation for cos (0.9) using Taylor series is %f and the standard function cos (0.9) is %f \n\n", cosine(0.9), cos(0.9));
	return 0;
}

void fillArray(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		arr[i] = rand();
}

void printArray(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
		
	printf("\n");
}

int cmpFunc (const void * a, const void * b)
{
	return ( *(int*)a -*(int*)b);
}

void bubbleSort(int a[], int size)
{
	int t, x, y;
	
	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x -1; y++)
			if (a[y] > a[y + 1])
			{
				t = a[y];
				a[y] = a[y + 1];
				a[y + 1] = t;
			}
	}
}

int numberOfDigits(int value)
{
	int digits = 1;
	while(value > 9)
	{
		value = value / 10;
		digits++;
	}
	return digits;
}

double squareRoot(int value)
{
	// Heron's method
	int digits = numberOfDigits(value);
	double x = digits * 100;
	int i;
	for(i = 0; i < digits - 1; i++)
	{
		x = (x + (value / x)) / 2;
	}
	return x;
}

double eulersNumber()
{
	double x = 100000;
	x = pow((1 + 1/x), x);
	return x;	
}

double estimatedPi()
{
	// Nilakantha's series, 50 iterations
	double x = 3.0;
	
	int i;
	int j = 1;
	for(i = 2; i < 101; i += 2)
	{
		if(j % 2 == 0)
			x -= 4.0/((i)*(i + 1)*(i + 2)); 
		else
			x += 4.0/((i)*(i + 1)*(i + 2));
		j++;
	}
	
	return x;
}

double cosine(double value)
{
	// Taylor series, 4 iterations
	int j = 2;
	int i = 2;
	double x = 1 - pow(value, i)/factorial(i);
	for(i = 4; i < 9; i += 2)
	{
		if(j % 2 == 0)
			x += pow(value, i)/factorial(i);
		else
			x -= pow(value, i)/factorial(i);
		j++;
	}	
	return x;
}

int factorial(int value)
{
	int i;
	int f = 1;
	for(i = value; i > 0; i--)
	{
		f *= i;
	}
	return f;
}



