#include <stdio.h>

int main()
{
	// relational operators: <, <=, ==, !=, >, >=
	
	int a = 10;
	int b = 5;
	printf("a > b? %d \n", (a>b)); // 1 or every other value = TRUE
	printf("a < b? %d \n", (a<b)); // 0 = FALSE
	
	if (a > b)	
		printf("a is bigger than b \n"); // no need for code block with just one statement
	else
		printf("a is not bigger \n");
		
	a = -20;
	   
		
	//	logical operators: &&, ||, !
	
	//Example is a betweeen 0 and 10 or not? [0,10]
	
		// first option
	if (a >= 0) 
		if (a <= 10)
			printf("a is between 0 and 10 \n");
		else
			printf("a is not between 0 and 10 \n");
	else
		printf("a is not between 0 and 10 \n");		
		
		// second option
	if (a >= 0 && a <= 10)
		printf("a is between 0 and 10 \n");
	else 
		printf("a is not between 0 and 10 \n");
		
		// third option
	if (a < 0 || a > 10)
		printf("a is not between 0 and 10 \n");
	else
		printf("a is between 0 and 10 \n");
		
		
	return 0;
}
