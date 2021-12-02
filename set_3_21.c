#include <stdio.h>
#include <math.h>

int main()
{
	// Set 3
	// 21
	
	/*
	21
	Try to solve this equation:
	3x^3 - 4x^2 + 9x +5 = 0
	Here ^ means exponent
	*/
	
	// can be done in excel with "goal seek" function
	
	float x, y;
	
	// brute force 
	// => try many iterations of x, try to get as close to 0 for y as possible
	for(x = -10; x < 10; x = x + 0.000001)
	{
		y = 3*x*x*x - 4*x*x +9*x +5;
		
		if (y > -0.0001 && y < 0.0001) // when y = close to 0, we get the x value
		break;
	}
	
	printf("x is %f \n", x); // x value
	printf("y is %f \n", y); // should be close to 0
	
	return 0;
}
