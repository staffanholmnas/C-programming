#include <stdio.h>

int main()
{

/*	
2
Our programs uses Ohm's law to calculate the resistance.
User gives voltage and current.
3
User gives the speed of the car (km/h) and the distance (km). Program calculates amount of time.
a) in hours
b) in whole hours and minutes
4
Our program calculates BMI.
5
Create a euro converter: dollars to euros.
6
Convert seconds to hours, minutes, seconds.
7
Convert euros to 5, 10, 20, 50, 100, 200, 500 euros bills.	
*/

// 2 
float I = 30;
float U = 100;
float R = U / I;

printf("The resistance is %f ohms \n", R);

// 3

// v = s/t, t = s/v
float v, s, t;
s = 550; // km
v = 72;	// km/h
t = s/v;

// full hours
int hours = (int) t;
// remaining minutes
int minutes = (t - hours) * 60;

printf("It takes %d full hours and %d minutes \n", hours, minutes);

// 4

float bmi, weight, height;

weight = 100;
height = 200;
height  = height/100;

bmi = weight / height * height;
bmi = (int)bmi;

printf("bmi is %f \n", bmi);

// 5

// 6

int all_seconds, hours_, minutes_, seconds;
all_seconds = 8888;
hours_ = all_seconds / 3600;
all_seconds = all_seconds - hours_ * 3600;
minutes_ = all_seconds / 60;
seconds = all_seconds - minutes_ * 60;

printf("%d %d %d \n", hours_, minutes_, seconds);

printf("------------------------------\n");

//7
// convert euros to 5,10,20,50,100,200,500 euro bills

int amount = 45;
int i;

int fives = 0;
int tens = 0;
int twenties = 0;
int fifties = 0;
int hundreds = 0;
int twohundreds = 0;
int fivehundreds = 0;

while (amount > 4)
{
	if (amount >= 500)
	{
		amount -= 500;
		fivehundreds++;
		continue;
	}
	if (amount >= 200)
	{
		amount -= 200;
		twohundreds++;
		continue;
	}
	if (amount >= 100)
	{
		amount -= 100;
		hundreds++;
		continue;
	}
	if (amount >= 50)
	{
		amount -= 50;
		fifties++;
		continue;
	}
	if (amount >= 20)
	{
		amount -= 20;
		twenties++;
		continue;
	}
	if (amount >= 10)
	{
		amount -= 10;
		tens++;
		continue;
	}
	if (amount >= 5)
	{
		amount -= 5;
		fives++;
		continue;
	}
}


printf("Result:\n5 : %d\n10 : %d\n20 : %d\n50 : %d\n100 : %d\n200 : %d\n500 : %d\n", fives, tens, twenties, fifties, hundreds, twohundreds, fivehundreds);

return 0;
}
