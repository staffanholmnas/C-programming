/*

Student name: Staffan Holmnäs 
Student code: xxxxxx

Name of the codefile: Staffan_2021.c

Date: 23 nov 2021 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rangeOfArray(int arr[], int size);
int sameValuesInArrays(int arr1[], int arr2[], int size1, int size2);
void printIntArray(int arr[], int n);
void BMI_Staffan();

int main()
{
	// task 1
	
	/*
	Function returns the range value of an array that has 5 
	whole numbers and that is passed to the function. Range means: max - min.
	*/
	
	int array[] = {20, 45, 3, 90, 19};
	int size = sizeof(array) / sizeof(array[0]);
	printf("The range of the array is %d\n\n", rangeOfArray(array, size));
	
	// task 2
	/*
	Two int arrays of size 6 are passed to a function that checks how many equal 
	values arrays have and returns that amount.
	*/
	
	int array1[] = {2, 85, 3, 13, 66};
	int array2[] = {6, 3, 75, 66, 13};
	int size1 = sizeof(array1) / sizeof(array1[0]);
	int size2 = sizeof(array2) / sizeof(array2[0]);
	printf("The amount of numbers that are equal in the two arrays is %d\n\n", sameValuesInArrays(array1, array2, size1, size2));
	
	// task 3
	/*
	Textfile contains 3 - 9 names and birthdays, e.g.
	Put your own contents (names and dates) to that file. 
	Name it using your firstname (e.g kauko.txt). 
	Current date is then given in a variable, e.g. "23.11.2021". 
	You can also use 3 different variables: one for days, one for month and one for year... 
	Person's name is given, then file is read and person's age is calculated and printed.
	*/
	
	char date[] = "23.11.2021";
	FILE *birthday_file;
	birthday_file = fopen("Staffan.txt", "r");
	if(birthday_file == NULL)
	{
		printf("Failed to open the file\n");
		return;
	}
	
	// find name
	char name[50];
	printf("Give name: \n");
	fgets(name, sizeof(name), stdin);
	printf("You entered: %s\n", name);
	
	// read file to content
	char *content[6];
	char *birthdays[3];
	char *names[3];
	int i;
	for(i = 0; i < 6; i++)
	{
		content[i] = calloc(100, 1);
		fgets(content[i], 100, birthday_file);
		//printf("content: %s\n", content[i]); // testing
	}
	fclose(birthday_file);
	
	// copy to 2 different arrays
	int j = 0;
	int k = 0;
	for(i = 0; i < 6; i++)
	{
		if(i % 2 == 0)
		{
			names[j] = strdup(content[i]);
			j++;
		}
		else
		{
			birthdays[k] = strdup(content[i]);
			k++;
		}
	}
	for(i = 0; i < 3; i++)
	{
		// test print
		// printf("names: %s\n", names[i]);
		// printf("birthdays: %s\n", birthdays[i]);
	}
	
	char *temp;
	int year = 0;
	// get current time
	time_t time_now = time(NULL);
    struct tm present = *localtime(&time_now);
	for(i = 0; i < 3; i++)
	{
		if(strcmp(name, names[i]) == 0)
		{	
			temp = strrchr(birthdays[i], '.'); // the birth year is assigned to temp
			memmove(temp, temp + 1, strlen(temp)); // remove the dot
			year = atoi(temp);
			printf("Name found!\n");
			printf("%s turns %d years old this year!\n", names[i], present.tm_year - year + 1900);	
		}
	}
	
	// task 4
	/*
	Program has a menu

	1 => print 5 different random numbers that are between 5 and 50. 
	2 => print a multiplication table when value (between 3 and 9) is given 
	3 => calculate BMI 0 = Exit

	Explanations: option 2 If user gives e.g. 5, this is printed

	Explanations: option 3 Use a function named BMI_yourname (e.g. BMI_John_Smith) 
	User's height (cm) and weight (kg)are asked, 
	can be floating point values (decimal values), then bmi is calculated and printed.
	*/
	

	printf("1. print 5 different random numbers that are between 5 and 50.\n");
	printf("2. print a multiplication table when values (between 3 and 9) are given\n");
	printf("3. calculate BMI 0 = Exit\n");
	int input;
	srand(time(NULL));
	scanf("%d", &input);
	if(input == 0)
		return;	
	else if(input == 1)
	{
		int array[5];
		for(i = 0; i < 5; i++)
			printf("%d \n", rand() % 45 + 5);
	}
	else if(input == 2)
	{
		printf("give first and second product \n");
		int inpt;
		scanf("%d", &inpt);
		int inpt2;
		scanf("%d", &inpt2);
		
		int j;
		for(i = 1; i <= inpt; i++)
		{
			for(j = 1; j <= inpt2; j++)
			{
				printf("%d ", i * j);
			}
			printf("\n");
		}
	}
	else if(input == 3)
	{
		BMI_Staffan();
	}
	
	return 0;
}

int rangeOfArray(int arr[], int size)
{
	int min = arr[0];
	int max = arr[0];
	int i;
	for(i = 1; i < size; i++)
	{
		if(arr[i] < min)
			min = arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
	int range = max - min;
	
	return range;
}

int sameValuesInArrays(int arr1[], int arr2[], int size1, int size2)
{
	int same_number = 0;
	int i, j;
	for(i = 0; i < size1; i++)
	{
		for(j = 0; j < size2; j++)
		{
			if(arr1[i] == arr2[j])
				same_number++;
		}
	}
	
	return same_number;
}

void printIntArray(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
		
	printf("\n");
}

void BMI_Staffan()
{
	float weight;
	float height;
	printf("give weight\n");
	scanf("%f", &weight);
	printf("give height\n");
	scanf("%f", &height);
		
	height = height / 100;
	float bmi = weight / (height * height);
	printf("your bmi is %2.2f", bmi);
}
