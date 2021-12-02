#include <stdio.h>
#include <math.h>

int main()
{
	// user inputs 3 sides of a triangle, calculate area
	// types of triangles: isosceles, equilateral, right angled, normal
	
	int a;
	int b;
	int c;
	float s;
	float area;
	
	printf("give side lengths \n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	// exit program if not a triangle
	if ((b + c) < a || (a + c) < b || (a + b) < c)
	{
		printf("One side is too long to form a triangle \n");
		return 0;
	}
	
	// calculate area with Heron's formula
	s = (float)(a + b + c) / 2; // cast to float, also just 2.0 instead of (float) works
	area = sqrt(s*(s - a)*(s - b)*(s - c));
	
	// check type of triangle
	if (a == b && a == c)
		printf("equilateral \n");
	else if (a == b || a == c || b == c)
		printf("isosceles \n");
	else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
		printf("right angled triangle \n");
	else
		printf("normal triangle \n");
		
	printf("The area is %f: \n", area);
	
	
	// for area use heron's formula!
	// square root: include math.h and use sqrt()
	
	return 0;
}
