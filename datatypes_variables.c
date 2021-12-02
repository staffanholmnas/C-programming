#include <stdio.h>

int main()
{
	/* 
	Multiline comment
	*/
	
	// One line comment
	
	printf("Hello world! \n");
	

	
	// datatypes and variables
	// integers - short, int, long
	// floating point - float, double
	// character - char
	// text/string - char array
	
	short a1 = -322; // range: -32000 - +32000, 2 bytes of ram needed
	printf("a1 is %d \n", a1);
	
	unsigned short a2 = -5000; // 0 - +64000
	printf("a2 is %d \n", a2);
	
	int a3 = -2000000000;
	printf("a3 is %d \n", a3); // -2000000000 - +2000000000, allocates 4 bytes of memory
	
	unsigned int a4 = 400000000; // 0 -+4000000000
	printf("a4 is %u \n", a4);
	
	// in our environment, long is the same as int
	
	float a5 = 345.345678; // 4 bytes, 7 digits
	printf("a5 is %f \n", a5);
	
	double a6 = 345.3456789; // 8 bytes, 15 digits
	printf("a6 is %f \n", a6); // not all digits are printed
 	
 	char a7 = 'x'; 	// 1 byte, range -128 - +128. Unsigned range 0 - 255
 	printf("a7 is %c \n", a7);
 	
 	char a8 = 65; // ASCII code, A
 	printf("a8 as a numerical value is %d, and as a character it is %c \n", a8, a8);
 	
 	// ASCII, alt + numbers on numpad
 	
 	printf("The capital of Finland is %s \n", "Helsinki");
 	
 	
	return 0;
}

