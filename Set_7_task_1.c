#include <stdio.h>
#include <math.h>

struct Dot
{
	int x;
	int y;
};

int main()
{	
	// set 7
	// task 1
	// Create a struct that models a Dot. Create the 2 dots in your program. 
	// Add then 20 dots to an array (use random numbers). Print dots, calculate the distance of first and last dots.
	
	srand(time(NULL));
	struct Dot dot_arr[20];
	int size = sizeof(dot_arr)/sizeof(dot_arr[0]);
	
	int i;
	for(i = 0; i < size; i++)
	{
		dot_arr[i].x = rand() % 100 + 1;
		dot_arr[i].y = rand() % 100 + 1;
	}
	
	for(i = 0; i < 20; i++)
		printf("(%d,%d) \n", dot_arr[i].x, dot_arr[i].y);
	
	int a = dot_arr[size - 1].x - dot_arr[0].x;
	int b = dot_arr[size - 1].y - dot_arr[0].y;
	
	float distance = sqrt(a*a + b*b);
	printf("The distance between the first and last dot is: %2.4f \n", distance);
	
	// task 2
	// Program calculates the hypotenuse of an triangle when other sides are given.
	
	int c = 13;
	int d = 34;
	float hypotenuse = sqrt(c*c + d*d);
	printf("The hypotenuse is: %2.4f \n", hypotenuse);
	
	// task 3
	// A stone is dropped down from the top of Pisa tower. 
	// What is the final speed of the stone and how much time does the fall take?
	
	
	return 0;
}
