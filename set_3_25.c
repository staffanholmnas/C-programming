#include <stdio.h>

int main()
{
	// set 3 exercise 25
	
	// factorials
	
	int x;
	printf("Give the value :\n");
	scanf("%d", &x);
	
	int i;
	int f = 1;
	
	if (x == 0 || x == 1)
		printf("factorial of %d is %d \n", x , 1);
	else
	{
		for (i = 1; i <= x; i++)
		{
			f = f * i;
		}
		
		printf("factorial is %d \n", f);
	}
	
	// combinations
	// we have 3 students, how many different pairs can we have?
	// Tim Tom Jim
	
	/*
		Tim + Tom
		Tim + Jim
		Tom + Jim
		
		3 combinations
		
		n = 1
		k = 1 (or r)
		combinations formula = n!/(k! * (n-k)!)
	*/
	
	// 10 persons, how many different groups with 3 members?
	// n = 10, k = 3
	// 10!/(3!*7!) = 120
	
	int n = 10;
	int k = 3;
	int n_k = 7;
	
	int s;
	int p1 = 1;
	for (s = 1; s <= n; s++)
	{
		p1 = p1 * s;
	}
	
	int p2 = 1;
	for (s = 1; s <= k; s++)
	{
		p2 = p2 * s;
	}
	
	int p3 = 1;
	for (s = 1; s <= n_k; s++)
	{
		p3 = p3 * s;
	}
	
	int amount = p1/(p2*p3);
	printf("Result is %d \n", amount);
	
	return 0;
}
