#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intConvert(int *int_parts, char *ISBN_string, int size);
void checkISBN10(int *int_parts);
void checkISBN13(int *int_parts);

int main()
{
	
	// Task 10
	// Your program checks if given ISBN is correct.
	
	char ISBN_10[] = "951-762-562-6";
	char ISBN_13[] = "978-0-306-40615-7";
	int int_parts_10[10];
	int int_parts_13[13];
	
	intConvert(int_parts_10, ISBN_10, strlen(ISBN_10)); // 9 5 1 7 6 2 5 6 2 6
	intConvert(int_parts_13, ISBN_13, strlen(ISBN_13)); // 9 7 8 0 3 0 6 4 0 6 1 5 7

	checkISBN10(int_parts_10);
	checkISBN13(int_parts_13);

	return 0;
}

void intConvert(int *int_parts, char *ISBN_string, int size)
{
	int i;
	int j = 0;
	
	for(i = 0; i < size; i++)
	{
			if(ISBN_string[i] != '-')
			{
				int_parts[j] = ISBN_string[i] - 48; // copy converted ASCII characters to integer array,
				j++;
			}
	}
}

void checkISBN10(int *int_parts)
{
	int sum = 0;
	int last = int_parts[9]; // 6

	int i;
	for(i = 1; i < 10; i++)
	{
		int_parts[i - 1] *= i; // 9 10 3 28 30 12 35 48 18
		sum += int_parts[i - 1]; // 193
	}
	
	if((sum % 11) == last)	// 193 / 11 = 17 with a remainder of 6. A correct ISBN has this remainder as the last number.
		printf("ISBN 10 is correct!\n");
	else
		printf("ISBN 10 is wrong!\n");
}

void checkISBN13(int *int_parts)
{
	int sum = 0;
	int i;
	int last = int_parts[12]; // 7
	for(i = 0; i < 12; i++)
	{
		if(i%2 != 0)
			int_parts[i] *= 3; // 9 21 8 0 3 0 6 12 0 18 1 15
		
		sum += int_parts[i]; // 93
	}

	if(10 - (sum % 10) == last) // 93 / 10 = with a remainder of 3. 10 - 3 = 7. This should be the last number for the 13 number ISBN to be correct.
		printf("ISBN 13 is correct!\n");
	else
		printf("ISBN 13 is wrong!\n");
}
