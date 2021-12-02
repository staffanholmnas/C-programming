#include <stdio.h>


int main()
{

	// print a triangle of o's
	char o = 'o';
	int num_of_os = 6;
	int i,j;
	
	for(i = 0; i < num_of_os; i++)
	{
		for(j = 0; j < i + 1; j++)
			printf("%c", o);
		printf("\n");	
	}
	for(i = num_of_os - 1; i > 0; i--)
	{
		for(j = 0; j < i; j++)
			printf("%c", o);
		printf("\n");	
	}
	
	// it can also be done simply like this
	char str[] = "oooooo";
	printf("%.1s\n", str);
	printf("%.2s\n", str);
	printf("%.3s\n", str);
	printf("%.4s\n", str);
	printf("%.5s\n", str);
	printf("%.6s\n", str);
	printf("%.5s\n", str);
	printf("%.4s\n", str);
	printf("%.3s\n", str);
	printf("%.2s\n", str);
	printf("%.1s\n", str);
	
	// or like this
	char string[] = "ooooooooooooooooooo";
	for(i = 1; i <= num_of_os; i++)
		printf("%.*s\n", i, string);
	for(i = num_of_os - 1; i > 0; i--)
		printf("%.*s\n", i, string);
		
	return 0;
}
