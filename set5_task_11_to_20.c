#include <stdio.h>
#include <math.h>

// 11. Returns the BMI.
float bmi(int m, int h);

// 12. Function returns the biggest of 5 integers.
int biggestOf5(int a, int b, int c, int d, int e);

//	15. Program with functions calculates amount of combinations.
int combinations(int n, int k);

// 16. Function prints out a lotto row.
void lotto();

// 17. Program with functions calculates the standard deviation.
void standardDeviation(int a[], int size_of_a);

// 18. Functions calculate: - sum of an array - min and max

void sumOfArray(int arr[], int size);
void minMaxArray(int arr[], int size);

// 19. Function searches for a value from an array.

char *findValue(int array[], int value, int size);

// 20. Returns the sum of an array.

int returnSumOfArray(int arr[], int size);

int main()
{
	// Set 5
	
	printf("the BMI is %0.1f \n", bmi(70, 178)); // task 11
	printf("the biggest of 5 values is %d \n", biggestOf5(67, 23, 73, 12, -6)); // task 12
	printf("the number of combinations is %d \n", combinations(20, 9)); // task 15
	lotto(); // task 16
	int a[] = {93, 18, 15, -4, 12, 55, 68, 33}; 
	int size_of_a = sizeof(a)/sizeof(a[0]); 
	standardDeviation(a, size_of_a); // task 17
	sumOfArray(a, size_of_a); // task 18
	minMaxArray(a, size_of_a); // task 18
	printf("%s \n", findValue(a, 68, size_of_a)); // task 19
	printf("the sum of the array is %d \n", returnSumOfArray(a, size_of_a)); // task 20

	
	return 0;
}

float bmi(int m, int h)
{
	float height = h / 100.0;
	float bmi = m / (height * height);
	return bmi;
}

int biggestOf5(int a, int b, int c, int d, int e)
{
	int biggest = a;
	if(a > b && a > c && a > d && a > e)
		biggest = a;
	else if(b > c && b > d && b > e)
		biggest = b;
	else if(c > d && c > e)
		biggest = c;
	else if(d > e)
		biggest = d;
	else biggest = e;
		
	return biggest;
}

int combinations(int n, int k)
{	
	// combinations formula = n!/(k!(n-k)!)
	long long int elements = 1; // sample = n
	long long int objects = 1;	// set of objects = k
	long long int n_minus_k = 1;
	int i;
	
	for(i = 1; i <= n; i++)
		elements *= i; // n!
	for(i = 1; i <= k; i++)
		objects *= i;  // k!
	for(i = 1; i <= (n - k); i++)
		n_minus_k *= i;  // (n - k)!
	
	int result = (elements / (objects * n_minus_k));
	
	return result;	
}

void lotto()
{
	srand(time(NULL)); // reset random to get unique values on every run
	int row[7];
	int randomnumber;
	int found = 0;
	int i, j;
	
	for (i = 0; i < 7; i++)
	{
		int random = rand();
		randomnumber = random % 40 + 1; // scaling to amount of balls
		
		for (j = 0; j < i; j++)	
		{
			if (row[j] == randomnumber) // Check if it's already in the row
			{
				found = 1;
				break;
			}
		}
		if (found == 1) // Don't add it to row if it's already there, try again instead.
		{
			i--;
			found = 0;
		}
		else
			row[i] = randomnumber;
	}

	for (i = 0; i < 7; i++)
		printf("%d \n", row[i]);
}

void standardDeviation(int a[], int size_of_a)
{
	double std_dev;
	int i;
	int sum = 0;
	double var = 0;
	double avg = 0;
	
	// calculate average
	for(i = 0; i < size_of_a; i++)
		sum += a[i];
	
	avg = (double)sum / size_of_a;
	
	// calculate variance
	for(i = 0; i < size_of_a; i++)
		var += (a[i] - avg) * (a[i] - avg);
	
	// calculate standard deviation and print it
	std_dev = sqrt(var / size_of_a);
	
	printf("the standard deviation is %2.5f \n", std_dev);
}

void sumOfArray(int arr[], int size)
{
	int sum = 0;
	int i;
	for(i = 0; i < size; i++)
		sum += arr[i];
	
	printf("the sum of the array is %d \n", sum);
}

void minMaxArray(int arr[], int size)
{
	int min = arr[0];
	int max = arr[0];
	int i;
	for(i = 1; i < size; i++)
	{
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}
	printf("the max value is %d and the min is %d \n", max, min);
}

char *findValue(int array[], int value, int size) // returns pointer to array
{
	int was_found = 0;
	static char found[] = "the value was found"; // must be static
	static char not_found[] = "the value was not found"; // must be static
	int i;
	for(i = 0; i < size; i++)
	{
		if(value == array[i])
			was_found = 1;
	}
	if(was_found == 1)
		return found;
	else
		return not_found;
}

int returnSumOfArray(int arr[], int size)
{
	int sum = 0;
	int i;
	for(i = 0; i < size; i++)
		sum += arr[i];
	
	return sum;
}
