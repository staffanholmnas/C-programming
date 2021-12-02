#include <stdio.h>


// passing by reference
// pointer parameters

void multi30(int v); 	// normal function doesn't work

void multi3(int * v);	// pointer function multiplies given value by 3

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
	*p1 = 300; // *p1 refers to the contents of price memory place 
	printf("price is now %d \n", price);
		
	// example with functions
	int weight = 100;
	
	multi30(weight); // without pointer nothing happens
	printf("weight is %d \n", weight);
	
	weight = 100;
	printf("weight is %d \n", weight);
	multi3(&weight);
	printf("weight is %d \n", weight);
	
	return 0;
}

void multi30(int v) // normal function
{
	v = v * 3;
}

void multi3(int * v) // function with pointer
{
	*v = *v * 3;	
}


