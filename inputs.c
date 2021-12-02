#include <stdio.h>

int main()
{
	int a = 50;
	printf("Adress is %d \n", &a); // & before a variable gives the memory address
	printf("Variable contains value %d \n", a);
	
	printf("Give a new value (whole number): \n");
	scanf("%d", &a);
	
	printf("You gave value %d \n", a);
	
	float b;
	double c;
	char d;
	printf("Giva a decimal value (max 7 digits) \n");
	scanf("%f", &b);
	
	printf("Giva a new decimal value (max 12 digits) \n");
	scanf("%lf", &c); // long floating point
	
	getchar(); // remove 'newline' from buffer, wont't work with char without this
	
	printf("Giva a letter \n");
	scanf("%c", &d);
	
	printf("You gave value %f \n", b);
	printf("You gave value %5.9f \n", c); // 5.9 prints 9 digits
	printf("You gave value %c \n", d);

	
	return 0;
}
