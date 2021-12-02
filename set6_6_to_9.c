#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atof() 

float converter(char coordinates[], char direction[], int is_latitude); // task 8
void commaPositions(int *arr, char *values, int size); // task 8 and 9
void NMEA(char *gpgga, int size); // task 8

int main()
{
	// Set 6
	
	// task 6
	// Program prints out the protocol of an url.
	
	char url[] = "https://www.google.com";
	strtok(url,":");
	printf("%s\n\n", url);
	//----------------------------------------------
	// task 7
	// Program tells if a string is a palindrome.
	
	char palindrome[] = "racecar";
	int len = strlen (palindrome);
	char firstpart[30] = ""; 
	char secondpart[30] = "";
	strncpy(firstpart, palindrome, len / 2);
	strrev(palindrome); // reverses the string. If it's a palindrome, it should be the same.
	strncpy(secondpart, palindrome, len / 2);
	
	if(strcmp(firstpart, secondpart) == 0)
		printf("It's a palindrome!\n\n");
	else
		printf("Not a palindrome!\n\n");
	//----------------------------------------------	
	// task 8
	// NMEA sentence ($GPGGA)is given and your program prints the longitude and latitude.
	// Then an url is created by using google's map url: latitude and longitude are added to that url.
	// Copy url then to web browser: where is the place?
	
	
	char gpgga1[] = "$GPGGA,134658.00,5106.9792,N,11402.3003,W,2,09,1.0,1048.47,M,-16.27,M,08,AAAA*60"; //NMEA message
	char gpgga2[] = "$GPGGA,092750.000,5321.6802,N,00630.3372,W,1,8,1.03,61.7,M,55.2,M,,*76"; // second example
	int str_len1 = strlen(gpgga1);
	int str_len2 = strlen(gpgga2);
	printf("\nTask 8 example 1:\n");
	NMEA(gpgga1, str_len1);
	printf("\nTask 8 example 2:\n");
	NMEA(gpgga2, str_len2);
	
	// The first coordinates point to an office building in Calgary, Canada. It belongs to a software company called Hexagon.
	// The second coordinates are in Leixlip, County Kildare, Ireland.
	
	//----------------------------------------------
	// task 9
	// String variable contains 5 measures separated by commas. Your program calculates the average
	// of those values. (E.g. "2, 3.5, 1, 5.8, 10") is given.)
	
	char * values = "11.5, 55, 123, -5.9, 36";
	int length = strlen(values);
	int pos[4];
	
	// find comma positions
	commaPositions(pos, values, length); 
	
	// position lengths
	int one_length = pos[0];
	int two_length = pos[1] - pos[0];
	int three_length = pos[2] - pos[1];
	int four_length = pos[3] - pos[2];
	int five_length = length - pos[3];
	
	// allocate memory for each string
	char * one = calloc(one_length, 1);
	char * two = calloc(two_length, 1);
	char * three = calloc(three_length, 1);
	char * four = calloc(four_length, 1);
	char * five = calloc(five_length, 1);
	
	// copy values to strings
	memcpy(one, &values[0], one_length);
	memcpy(two, &values[pos[0] + 1], two_length - 1);
	memcpy(three, &values[pos[1] + 1], three_length - 1);
	memcpy(four, &values[pos[2] + 1], four_length - 1);
	memcpy(five, &values[pos[3] + 1], five_length - 1);
	
	// convert to floats
	float first = atof(one);
	float second = atof(two);
	float third = atof(three);
	float fourth = atof(four);
	float fifth = atof(five);
	
	float avg = (first + second + third + fourth + fifth) / 5;
	printf("\naverage: %2.2f\n", avg);
	
	//----------------------------------------------
	// task 10 is in a separate file.
	
	return 0;
}

float converter(char coordinates[], char direction[], int is_latitude)
{
	// convert latitude and longitude from NMEA format (Degree.Minutes) to DMS (degrees, minutes, seconds) and print
	if (is_latitude == 1)
		printf("Latitude:\n");
	else
		printf("Longitude:\n");
	char D[4] = "";
	char M[3] = "";
	char S[6] = "";
	if (is_latitude == 1)
	{
		memcpy(D, &coordinates[0], 2);
		memcpy(M, &coordinates[2], 2);
		memcpy(S, &coordinates[4], 5);
	}
	else
	{
		memcpy(D, &coordinates[0], 3);
		memcpy(M, &coordinates[3], 2);
		memcpy(S, &coordinates[5], 5);
	}
	float d = atof(D);
	float m = atof(M);
	float s = (atof(S) * 60); // convert from decimal minutes to minutes and seconds
	
	printf("%2.0f\370 %2.0f\' %2.2f\" %c\n", d, m, s, direction[0]);
	
	// returns the coordinates in decimal form
	m = m / 60;
	s = s / 60 / 60;
	float deci = d + m + s;
	if (direction[0] == 'W' || direction[0] == 'S') // south and west directions are negated
		deci = deci * -1;
	return deci;
}

void commaPositions(int *arr, char *values, int size)
{
	int i;
	int j = 0;
	
	for(i = 0; i < size; i++)
	{
			if(values[i] == ',')
			{
				arr[j] = i;
				j++;
			}
	}
}

void NMEA(char *gpgga, int size)
{
	// First extract the latitude and longitude with respective directions so it's easier to work with.
	
	char latitude[10] = "";
	char latitude_direction[2] = "";
	char longitude[11] = "";
	char longitude_direction[2] = "";
	
	int comma_pos[14];
	
	commaPositions(comma_pos, gpgga, size); // find comma positions
	
	memcpy(latitude, &gpgga[comma_pos[1] + 1], 9);
	memcpy(latitude_direction, &gpgga[comma_pos[2] + 1], 1);
	memcpy(longitude, &gpgga[comma_pos[3] + 1], 10);
	memcpy(longitude_direction, &gpgga[comma_pos[4] + 1], 1);
	
	// The converter function converts latitude and longitude from Degree.Minutes (NMEA) to DMS and prints them. 
	// The function also converts the coordinates to decimal format and returns the values. 

	float lat = converter(latitude, latitude_direction, 1);
	float lon = converter(longitude, longitude_direction, 0);
	
	// convert back to string and copy them into the url
	char url_lat[12];
	char url_lon[12];
	gcvt(lat, 8, url_lat);
	gcvt(lon, 9, url_lon);
	
	char maps_url[] = "https://www.google.com/maps/search/?api=1&query=";
	strcat(maps_url, url_lat);
	strcat(maps_url, ",");
	strcat(maps_url, url_lon);
	printf("%s \n", maps_url);
}
