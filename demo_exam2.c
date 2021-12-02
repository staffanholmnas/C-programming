# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

typedef struct Circle	
{
	int radius;
	int x;
	int y;
} Circle;

typedef struct Animal
{
	char *name;
	int lifespan;
} Animal;

void fractionStringToInt(char * fractions, int *arr);
void checkPlate(char plate[]);
void fractionSumProduct(char fraction1[], char fraction2[]);
void carList(int cars[][8], int size);
void dartResults(int scores[][5]);
void printCircle(struct Circle c);


int main()
{
	// 1. Two fractions are given in format "x/y", e.g. "6/11". 
	// Calculate the product and sum of those fractions. (Avoid using division..)
	
	char fraction1[] = "6/11";
	char fraction2[] = "-5/15";
	
	fractionSumProduct(fraction1, fraction2);
	
	// 2.
	// Cars in Finland are shown in the list below. Make it a 2 dimensional array. Print the array. 
	// Search amount of cars when year is given. 1950 200000 1960 300000 1970 700000 1980 1300000 1990 2100000 2000 2300000 
	
	int cars[2][8];
	int size_of_columns = sizeof(cars[0])/sizeof(cars[0][0]);
	carList(cars, size_of_columns);
	
	// 3.
	/*
	Jekaterina Käkkäräinen was throwing dart.
	There are 5 darts and 2 rounds. Give values as random numbers (0-10).
	Analyse series: how many times did Jeka get 10? Which of sums was better?
	*/
	
	srand(time(NULL));
	int scores[2][5];
	// 5 random scores for each of the 2 rounds
	int i;
	for(i = 0; i < 5; i++)
	{
		scores[0][i] = rand() % 10 + 1;
		scores[1][i] = rand() % 10 + 1;
	}
	
	dartResults(scores);
	
	// 4.
	/*
	Register plate
	In Finland tractors and other similar work vehicles have maximum of three numbers and maximum of three letters, 
	separated by a middot, with black on reflective yellow background.E.g. "123-ABC"
	User gives the plate nr: it is passed to the function that tells if number can be accepted.
	*/
	char plate[7];
	printf("\n");
	printf("Please enter your vehicle registration plate here to verify (ex 123-ABC):\n");
	scanf("%s", &plate); // use a hyphen(dash) instead of middot(interpunct)!
	//strcpy(plate, "123-ABC"); // used for testing
	checkPlate(plate);
	
	/*
	license plates examples

	123-ABC  // correct
	12-AB	 // correct
	1-A 	 // technically correct
	- 		 // incorrect
	123 ABC  // incorrect
	ABC-123  // incorrect
	123-abc  // incorrect
	1234-ABC // incorrect
	123-ABCD // incorrect
	*/
	
	// 5.
	// Create a struct that models a circle that is shown on an xy-coordinate system.
	
	Circle circle;
	circle.x = 15;
	circle.y = 10;
	circle.radius = 7; // a circle with the center at (15,10) and radius 7
	
	printCircle(circle);
	printf("---------------------------------------------------------------------->\n");
	printf("\n");
	
	// 6.
	/*
	Animals and lifespans
	Choose some 10 animals names and lifespans e.g from
	https://www.futurelearn.com/info/courses/maths-linear-quadratic/0/steps/12167
	and add them to a file.
	Read the file. Choose the data structure freely.
	Search for given animal's lifespan.
	*/
	
	FILE *animal_file;
	animal_file = fopen("animals.txt", "r");
	if(animal_file == NULL)
	{
		printf("Failed to open the file\n");
		return;
	}
	
	Animal animal_arr[10]; 
	char *animals[10];
	char *animals_copy[10];
	char *temp;
	
	// read
	
	int word_count = 0;
	for(i = 0; i < 10; i++)
	{
		animals[i] = malloc(30);
		fgets(animals[i], 30, animal_file);	// read from file to string array
		animals_copy[i] = strdup(animals[i]); // make a copy
		temp = strrchr(animals_copy[i], ','); // the animal lifespan is assigned to temp
		memmove(temp, temp + 1, strlen(temp)); // remove the comma
		animal_arr[i].lifespan = atoi(temp); // convert to integer
		animal_arr[i].name = strdup(strtok(animals[i],",")); // copy just the animal name string part to the struct 
	}
	fclose(animal_file);
	
	// print
	printf("Lifespan:\tAnimal: \n");
	for(i = 0; i < 10; i++)
	{
		printf("%d", animal_arr[i].lifespan);
		printf("\t\t%s\n",  animal_arr[i].name);
			
	}
	
	// find lifespan by searching for animal
	char find_animal[50];
	printf("\n");
	printf("Which animal's lifespan do you want to search for?\n");
	fflush(stdin); // remove the newline from the buffer
	fgets(find_animal, sizeof(find_animal), stdin);
	int len = strlen(find_animal);
	find_animal[len - 1] = '\0'; // remove the new line from the given string and add a null terminator
	int found = 0;
	
	for(i = 0; i < 10; i++)
	{
		if(strcmp(animal_arr[i].name, find_animal) == 0)
		{
			printf("The %s can live to an age of %d years! \n", animal_arr[i].name, animal_arr[i].lifespan);
			found = 1;
			break;
		}	
	}
	
	if(found == 0)
		printf("The animal was not on the list!\n");
	
	return 0;
}

void fractionSumProduct(char fraction1[], char fraction2[])
{
	// convert to int
	int fract_arr_1[] = {0,0}; 
	fractionStringToInt(fraction1, fract_arr_1);
	int fract_arr_2[] = {0,0};
	fractionStringToInt(fraction2, fract_arr_2);
	
	// assign to variables with more descriptive names
	int fract_1_numerator = fract_arr_1[0];
	int fract_1_denominator = fract_arr_1[1];
	int fract_2_numerator = fract_arr_2[0];
	int fract_2_denominator = fract_arr_2[1];
	
	printf("First fraction = %d/%d \n", fract_1_numerator, fract_1_denominator);
	printf("Second fraction = %d/%d \n", fract_2_numerator, fract_2_denominator);
	
	// check for division by zero
	if(fract_1_denominator == 0 || fract_2_denominator == 0)
	{
		printf("Cannot divide by zero!");
		return;
	}
	
	int sum[2];
	int product[2];
	int max = 0;
	int lcd = 0; // least common denominator.
	
	// multiply
	product[0] = fract_1_numerator * fract_2_numerator;
	product[1] = fract_1_denominator * fract_2_denominator;
	
	// two negatives cancel
	if(product[0] < 0 && product[1] < 0)
	{
		product[0] *= -1;
		product[1] *= -1;
	}
	
	// perform addition
	if (fract_1_denominator == fract_2_denominator)
	{
		sum[0] = fract_1_numerator + fract_2_numerator;
		sum[1] = fract_1_denominator;
	}
	else
	{
		// find the LCD
		if(fract_1_denominator > fract_2_denominator)
			max = fract_1_denominator;
		else
			max = fract_2_denominator;
		
		while (1)
		{
			if(max % fract_1_denominator == 0 && max % fract_2_denominator == 0)
			{
			 	lcd = max;
			 	break;
			}	
			else
				max++;	
		}
		
		fract_1_numerator = fract_1_numerator * (lcd / fract_1_denominator);
		fract_1_denominator = lcd;
		fract_2_numerator = fract_2_numerator * (lcd / fract_2_denominator);
		fract_1_denominator = lcd;
		
		sum[0] = fract_1_numerator + fract_2_numerator;
		sum[1] = fract_1_denominator;
	}
	
	// simplify with absolute values of the product fraction
	int negate_num = 0;
	int negate_den = 0;
	if(product[0] < 0)
	{
		product[0] *= -1;
		negate_num = 1; 
	}
	if(product[1] < 0)
	{
		product[1] *= -1;
		negate_den = 1; 
	}
	
	// simplify
	int i;
	int simplify = 1;
	while(simplify == 1)
	{	
		simplify = 0;
		for(i = 2; i < sum[1]; i++)
		{
			if(sum[0] % i == 0 && sum[1] % i == 0)
			{
				sum[0] /= i; 
				sum[1] /= i;
				simplify = 1;
			}
		}
		
		for(i = 2; i < product[1]; i++)
		{
			if(product[0] % i == 0 && product[1] % i == 0)
			{
				product[0] /= i; 
				product[1] /= i;
				simplify = 1;
			}
		}
	}
	
	// if minus sign was removed when simplifying, put it back
	if(negate_num == 1 || negate_den == 1)
		product[0] *= -1;
		
	printf("sum: %d/%d \n", sum[0], sum[1]);
	printf("product: %d/%d \n", product[0], product[1]);
}

void fractionStringToInt(char * fractions, int arr[])
{
	char * fract_str;
	fract_str = strtok(fractions, "/");
	arr[0] = atoi(fract_str);
	fract_str = strtok(NULL, "/");
	arr[1] = atoi(fract_str);
}

void carList(int cars[][8], int size)
{
	int i;
	int j = 1950;
	// add years to list
	for(i = 0; i < size; i++) 
	{
		cars[0][i] = j;
		j += 10;
	}
	
	// add number of cars to list
	cars[1][0] = 60000;
	cars[1][1] = 250000;
	cars[1][2] = 800000;
	cars[1][3] = 1400000;
	cars[1][4] = 2200000;
	cars[1][5] = 2500000;
	cars[1][6] = 3400000;
	cars[1][7] = 4300000;
	
	// print the results
	printf("\nNumber of automobiles in Finland:\nyear \tamount\n----------------\n");	
	for(i = 0; i < size; i++)
		printf("%d \t%d\n", cars[0][i], cars[1][i]);
		
	// search and print the results for a specific year
	
	int year;
	printf("Which decade do you want to search? 1950-2020\n");
	scanf("%d", &year);
	
	for(i = 0; i < size; i++)
	{
		if(year == cars[0][i])
		{
			printf("The number of cars in %d was %d\n", cars[0][i], cars[1][i]);
		}
	}
}

void dartResults(int scores[][5])
{
	// find amount of tens, which round had a better score and print the result
	printf("\n");
	printf("Dart results:\n");
	int round1 = 0;
	int round2 = 0;
	int tens = 0;
	int i;
	printf("round 1 \t round 2\n");
	for(i = 0; i < 5; i++)
	{
		round1 += scores[0][i];
		round2 += scores[1][i];
		if(scores[0][i] == 10 || scores[1][i] == 10)
			tens++;
		printf("%d \t\t %d\n", scores[0][i], scores[1][i]);
	}
	
	if(tens == 0)
		printf("Jekaterina did not score any tens\n");
	else
		printf("Jekaterina hit a bullseye %d time%c\n", tens, tens == 1 ? 32 : 's');
	
	if(round1 > round2)
		printf("The first round was her best, she got a total score of %d\n", round1);
	else if(round1 == round2)
		printf("Both rounds resulted in the same total, %d points\n", round1);
	else
		printf("Jekaterina performed her best in the second round, where her total score was %d\n", round2);
}

void checkPlate(char plate[])
{
	printf("You entered: %s\n", plate);
	int i;
	int place_of_dash = 0;
	int invalid = 0;
	for(i = 0; i < strlen(plate); i++)
		if(plate[i] == 45)
			place_of_dash = i;	
	// missing hyphen
	if(place_of_dash == 0)
	{
		printf("The license plate needs a hyphen in between numbers and letters!\n");
		invalid = 2;
	}
	// max 3 digits
	if(place_of_dash > 3 && invalid != 2)
	{
		printf("Max 3 digits before the hyphen!\n");
		invalid = 1;
	}
	// max 3 letters
	if((strlen(plate) - place_of_dash - 1) > 3 && invalid != 2)
	{
		printf("Max 3 letters after the hyphen!\n");
		invalid = 1;
	}
	// only digits
	if(invalid!= 2)
	{
		for(i = 0; i < place_of_dash ; i++)
		{
			if(plate[i] < 48 || plate[i] > 57)
			{
				printf("Only numbers are allowed in the beginning!\n");
				invalid = 1;
				break;
			}
		}
	}
	// only letters and they need to be upper case
	if(invalid!= 2)
	{
		for(i = place_of_dash + 1; i < strlen(plate); i++)
		{
			if(plate[i] < 65 || plate[i] > 90)
			{
				printf("Only upper case letters are allowed in the end!\n");
				invalid = 1;
				break;
			}
		}
	}
	
	if(invalid == 0)
		printf("Your vehicle registration plate is valid!\n");
	else
		printf("Your vehicle registration plate is invalid!\n");
	
	printf("\n");
}

void printCircle(struct Circle c)
{
	
	printf("A circle in an xy coordinate system:\n");
	
	c.y = 30 - c.y; // flip the y axis
	
	char arr[30][30];
	
	// fill with whitespaces
	int i, j;
	for(i = 0; i < 30; i++)
	{
		for(j = 0; j < 30; j++)
		{
			arr[i][j] = ' ';
		}	
	}
	
	// draw circle
	
	float radius;
	int a, b;
	// arr[c.y][c.x] = '*'; // show center point
	int x, y;
	for(x = 0; x < 30; x++)
    {
        for(y = 0; y < 30; y++)
        {
        	a = c.y - y;
        	b = c.x - x;
            radius = sqrt((float)a * a + b * b); // calculate the radius to the middle point
            
            if (radius > c.radius - 0.5 && radius < c.radius + 0.5)  // only draw the dots where the radii are roughly the same
            {
                arr[y][x] = '*';
            }
        }
    }
	
	// print
	for(x = 0; x < 30; x++)
	{
		for(y = 0; y < 30; y++)
		{	
			printf("%c ", arr[x][y]);
		}
		printf("\n");		
	}	
}

