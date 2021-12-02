#include <stdio.h>
#include <string.h>
#include <stdlib.h> // calloc

int main()
{
	// strings
	char name[] = "Kekkonen";
	printf("Name is %s \n", name);
	
	char * cityname = "Helsinki";
	printf("City is %s \n", cityname);
	
	char country[12];
	strcpy(country, "Finland");
	printf("Country is %s \n", country);
	
	char band[] = {'A','B','B','A','\0'}; // NULL terminator added manually, previous examples added it automatically
	printf("Band is %s \n", band);
	
	char * car = calloc(12, 1); // each char is 1 byte
	strcpy(car, "Fiat");
	printf("Car is %s \n", car);
	
	char letter = 'a';
	printf("letter is %c \n", letter);
	printf("letter is %d \n", letter); // prints ASCII code
	
	
	return 0;
}
