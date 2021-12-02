#include <stdio.h>

// struct

typedef struct Fraction	
{
	// properties of the entity, attributes
	int numerator;
	int denominator;
} Fraction;  //typedef

// task
// model a complex number
// create 2 real complex values
// calculate the sum of those values and print

struct ComplexNumber
{
	float real;
	float imaginary;
};
 
int main()
{
	Fraction a; 	// typedef
	a.numerator = 5;
	a.denominator = 6;
	
	printf("fraction a is %d/%d \n", a.numerator, a.denominator);
	
	struct ComplexNumber number1;
	number1.real = 9;
	number1.imaginary = 3; 
	
	printf("Number is %f + %fi \n", number1.real, number1.imaginary);

	// sum of 2 complex values:
	
	struct ComplexNumber number2;
	number2.real = 1;
	number2.imaginary = 5; 
	
	struct ComplexNumber sumNumber;
	sumNumber.real = number1.real + number2.real;
	sumNumber.imaginary = number1.imaginary + number2.imaginary;
	
	printf("Sum of numbers are %f + %fi \n", sumNumber.real, sumNumber.imaginary);
		
	return 0;
}
