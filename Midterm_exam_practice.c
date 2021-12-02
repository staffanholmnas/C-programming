#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int bool;

int main()
{
	int a = 2;
	if (!a)
		printf("True\n");
	else
		printf("False\n");
	
	
	// Fahrenheit to celsius program
	
	float start;
	float end;
	float increment;
	bool printed = FALSE;
	printf("Type a starting temperature:\n");
	scanf("%f", &start);
	
	printf("Type an ending temperature:\n");
	scanf("%f", &end);
	
	printf("Type an increment:\n");
	scanf("%f", &increment);
	
	while (start <= end)
	{
		if (start > 98.6 && !printed) // not zero will be 1
		{
			printf("Fahrenheit: %2.1f degrees F, Celsius: %2.1f degrees C\n", 98.6, (98.6 - 32.0) * 5.0 / 9.0);
			printed = TRUE;
		}
		printf("Fahrenheit: %2.1f degrees F, Celsius: %2.1f degrees C\n", start, (start - 32.0) * 5.0 / 9.0);
		start = start + increment;
	}	
	
	return 0;
}
