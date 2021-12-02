#include <stdio.h>

// declaration of a function, prototype

void printHelsinki(); // function prints Helsinki once
void printThis(char name[]);	// functions prints given name (passed name, char name[] is a string, a parameter or placeholder)
void printThisManyTimes(char name[], int n);	// print text several times
int sumOf5(int a, int b, int c, int d, int e);// returns sum of 5 whole numbers

// passing by reference
// pointer parameters
void multi3(int * v);	// function multiplies given value by 3
// compare!

void multi30(int v); 


int main()
{
	// pointer
	// stores an address
	// address operator is & (used in scanf())
	int * p1; // pointer operator *
	int price = 200;
	p1 = &price;
	printf("price is %d \n", price);
	printf("memory address of variable price is %d \n", &price);
	printf("now pointer p1 has value %d \n", p1);
	*p1 = 300; // *p1 refers to the price memory place (contents)
	printf("price is %d \n", price);
		
	// functions, procedures, subroutines
	
	// call
	printHelsinki();
	printHelsinki();
	
	printThis("Staffan"); // The name passed is an argument
	printThisManyTimes("DFTBA", 6);
	
	int result = sumOf5(22,33,44,55,66);
	printf("Result is %d \n", result);
	printf("Result is %d \n", sumOf5(77,88,99,88,77));
	
	int x1 = 5; int x2 = 5; int x3 = 5; int x4 = 5;
	int x5 = 5; int x6 = 5;
	printf("Result is %d \n", sumOf5(x1 * 2, x2 + 10, x3 / 5, x4 - 2, x5 + 20));
	
	int weight = 100;
	printf("weight is %d \n", weight);
	multi3(&weight);
	printf("weight is %d \n", weight);
	
	weight = 100;
	multi30(weight);
	printf("weight is %d \n", weight);
	
	return 0;
}

void multi3(int * v)
{
	*v = *v * 3;	
}

void multi30(int v)
{
	v = v * 3;
}

// implementation, definition
void printHelsinki()
{
	printf("Helsinki \n");
}

void printThis(char name[])
{
	printf("%s \n", name);
}

void printThisManyTimes(char name[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%s \n", name);
}

int sumOf5(int a, int b, int c, int d, int e)
{
	int s = a + b + c + d + e;
	return s;
}		
