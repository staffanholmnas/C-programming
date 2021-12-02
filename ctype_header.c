#include <stdio.h>
#include <ctype.h> // isdigit, isalpha, toupper...

int main()
{

	char x = 'a';
	
	printf("%d \n", isdigit(x)); // 0 False
	printf("%d \n", isalpha(x)); // True
	printf("%d \n", islower(x)); // True
	
	x = toupper(x); // convert to upper case
	printf("%d \n", islower(x)); // False

	// a -> A 32 in ASCII code
	printf("x is now %c \n", x);
	x = x + 32;
	printf("x is now %c \n", x);
	
	
	return 0;
}
