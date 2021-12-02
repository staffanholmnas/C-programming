#include <stdio.h>
#include <math.h>

typedef struct Point
	{
		int x;
		int y;
	} Point;

int main()
{
	
	// 1) Bits
	// Try bit operations using 2 bit queues. Check a bit state: ask user the position. Invert a bit: ask user for the position.
	
	// bit state
	
	int number;
	int position;
	int state;
	printf("Which number do you want to check the bit state on? \n");
	scanf("%d", &number);
	printf("Which bit position do you want to check? (<32) \n");
	scanf("%d", &position);
	
	state = (number >> (position - 1)) & 1;
	printf("The state of the chosen bit is %d \n", state);
	
	// Invert a bit
	
	printf("Which number do you want to perform a bit invert operation on? \n");
	scanf("%d", &number);
	printf("Give the position of the bit you want to invert? (<32) \n");
	scanf("%d", &position);
	
	int mask = 1 << (position - 1);
	number = number ^ mask;
	printf("The result of the inverted bit is %d \n\n", number);
	
	// 2) Create a struct that models a 2D point. Create 2 points and calculate the distance. 
	
	Point point1;
	Point point2;
	int a;
	int b;
	float distance;
	point1.x = 2;
	point1.y = 3;
	point2.x = 6;
	point2.y = 5;
	a = point2.y - point1.y;
	b = point2.x - point1.x;
	
	distance = sqrt(a*a + b*b);
	
	printf("The distance between points is %2.2f \n", distance);
	
	// Add 20 random points to an array and print them in format (x,y), e.g (5,7)
	
	srand(time(NULL));
	Point arr[20];
	int i;
	for(i = 0; i < 20; i++)
	{
		arr[i].x = rand() % 10 + 1; // between 1-10
		arr[i].y = rand() % 10 + 1;
	}
	
	for(i = 0; i < 20; i++)
	{
		printf("(%d,%d) \n", arr[i].x, arr[i].y);
	}
	
	return 0;
}
