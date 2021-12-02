#include <stdio.h>
#include <math.h>

int main()
{
	double x = 5;
	printf("Square root of 5 is %f \n", sqrt(x));
	
	double exponent = 2.5;
	printf("%2.2f ^ %2.2f is %f\n", x, exponent, pow(x, exponent));
	
	printf("Ceiling of %2.2f is %2.f \n", exponent, ceil(exponent));
	
	printf("Floor of %2.2f is %2.f \n", exponent, floor(exponent));
	
	int a = 4.7;	// int a = (int)4.7;
	printf("a is %d \n", a);
	
	printf("pi is %f \n", M_PI); // Pi
	
	printf("pi is %f \n", M_E); // eulers number
	
	// cosine sine tangent are in radians and needs to be converted first
	
	float angle_in_degrees = 50;	// 180 => Pi radians
	float angle_in_radians = angle_in_degrees/180 * M_PI; // convert degrees to radians
	float sine_value = sin(angle_in_radians);
	
	printf("sine of %f is %f\n", angle_in_radians, sine_value); // 0.766044
	
	
	return 0;
}
