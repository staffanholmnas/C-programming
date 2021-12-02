#include <stdio.h>

// recursive functions
// factorial example

int fact(int n)
{
	int k;
	if (n == 0 || n == 1)
		return(1);
	else
		return(n * fact(n - 1));
}

// factorial without recursion

int factNoRec(int n)
{
	int k;
	int f = 1;
	for (k = 1; k <= n; k++)
		f = f * k;
		
	return f;
}


// Fibonacci numbers
// 1 1 2 3 5 8 13 21 34 55

int fibonacci(int n)
{
	int val;
	if (n == 1 || n == 2)
		val = 1;
	else
		val = fibonacci(n - 1) + fibonacci(n - 2);
	return (val);
}


// Tower of Hanoi
// A B C

void move(int x, char V, char O, char K)
{
	if ( x > 0 )
	{
		move(x-1, V, K, O);
		printf("I move a disc from the pillar %c to the pillar %c \n", V, O);
		move(x-1, K, O, V);
	}	
}

// add numbers recursively

int addNumbers(int n)
{
	if (n != 0)
		return n + addNumbers(n - 1);
	else
		return n;	
}

int main()
{
	// factorial
	printf("Factorial of %d is %d \n", 5, fact(5));
	printf("Factorial of %d is %d \n", 5, factNoRec(5));
	
	// fibonacci
	printf("%d. Fibonacci value is %d \n", 6, fibonacci(6));
	
	// tower of Hanoi
	char V = 'A';
	char K = 'B';
	char O = 'C';
	int discs = 3;
	move(discs, V, O, K);
	
	// add numbers recursively
	printf("%d minus 1 added recursively equals %d \n", 6, addNumbers(6));
	
	return 0;
}

