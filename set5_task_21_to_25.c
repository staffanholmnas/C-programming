#include <stdio.h>
#include <windows.h>

// print function

void print(int *a, int size);

// 21. Function multiplies every value in an array by 2.

void multiplyByTwo(int *arr, int size);

// 22. A character is passed to a function: funtion returns True if character is a vowel, otherwise False (0).
// (Five of the 26 alphabet letters are vowels: A, E, I, O, and U. )

char *vowelCheck(char letter);

// 23. A whole number and an array (size is 5, contains integers) are passed to a function
// that checks how many times passed value exists in that passed array and returns the amount.

int timesFound(int *arr, int value);

// 24. Your program defines and fills an array of 10 integers with random numbers that are between 1-5.
// That array is passed to a method that counts the amounts of different values and prints them out.

int *createRandomArray();
void printValueAmount(int arr[], int size);

/*25.
Duration and frequency are passed to a function that plays then that sound (windows.h neeeded).
Function converts the text to morse code characters.
Function checks if the post code includes exactly 5 numbers.
*/

void play(int frequency, int duration);
void morseConvert(char text[], int length);
void checkNumberAmount(char text[], int size);


int main()
{
	int a[] = {22, 15, 88, 73, 1, 44, 66, 91, 14};
	int size = sizeof(a)/sizeof(a[0]); 
	
	multiplyByTwo(a, size); // task 21
	print(a, size);
	
	printf("The character is a vowel: %s \n", vowelCheck('A')); // task 22
	
	int array[] = {4, 5, 4, 6, 4};
	printf("Passed value %d was found in array %d times \n", 4, timesFound(array, 4)); // task 23
	
	printValueAmount(createRandomArray(), 10); // task 24
	
	
	char numberText[] = "c0unt h0w m4ny numb3r5"; // task 25
	int len = sizeof(numberText)/sizeof(numberText[0]);
	checkNumberAmount(numberText, len);
	
	play(300, 2500); // play sound
	
	char text[] = "hello world"; // morse code
	int length = sizeof(text)/sizeof(text[0]);
	morseConvert(text, length);
	
	
	return 0;
}

void print(int *a, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d \n", a[i]);
	}
}

void multiplyByTwo(int *arr, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		arr[i] *= 2;
	}
}

char *vowelCheck(char letter)
{
	static char found[] = "TRUE";
	static char not_found[] = "FALSE";
	if(letter == 'a' || letter == 'e'|| letter == 'i' || letter == 'o' || letter == 'u' ||
	   letter == 'A' || letter == 'E'|| letter == 'I' || letter == 'O' || letter == 'U')
		return found;
	else
		return not_found;
}

int timesFound(int *arr, int value)
{
	int times_found = 0;
	int i;
	for(i = 0; i < 5; i++)
	{
		if(value == arr[i])
			times_found++;
	}
	return times_found;
}

int *createRandomArray()
{
	srand(time(NULL));
	static int array[10];
	int i;
	for(i = 0; i < 10; i++)
		array[i] = rand() % 5 + 1;
		
	return array;
}

void printValueAmount(int arr[], int size)
{
	int ones = 0;
	int twos = 0;
	int threes = 0;
	int fours = 0;
	int fives = 0;
	int i;
	for(i = 0; i < 10; i++)
	{
		if(arr[i] == 1)
			ones++;
		else if (arr[i] == 2)
			twos++;
		else if (arr[i] == 3)
			threes++;
		else if (arr[i] == 4)
			fours++;
		else
			fives++;
	}
	printf("Number of ones: %d \nNumber of twos: %d \nNumber of threes: %d \nNumber of fours:  %d \nNumber of fives: %d\n", ones, twos, threes, fours, fives);
}

void play(int frequency, int duration)
{
	Beep(frequency, duration);
}

void morseConvert(char text[], int length)
{
	/*
	a = ".-" ; b = "-..."; c = "-.-."; d = "-.."; e = "."; f = "..-."; g = "--.";
	h = "...."; i = ".."; j = ".---"; k = "-.-"; l = ".-.."; m = "--"; n = "-.";
	o = "---"; p = ".--."; q = "--.-"; r = ".-."; s = "..."; t = "-"; u = "..-";
	v = "...-"; w = ".--"; x = "-..-"; y = "-.--"; z = "--..";
	*/
	
	char morse[length * 5]; 
	int i;
	int j = 0;
	for(i = 0; i < length; i++)
	{
			switch (text[i])
		{
			case 'a': morse[j] = '.'; morse[j + 1] = '-'; morse[j + 2] = ' '; j = j + 3;   	break;
			case 'b': morse[j] = '-'; morse[j + 1] = '.'; morse[j + 2] = '.'; morse[j + 3] = '.'; morse[j + 4] = ' '; j = j + 5;   	break;
			case 'c': morse[j] = '-'; morse[j + 1] = '.'; morse[j + 2] = '-'; morse[j + 3] = '.'; morse[j + 4] = ' '; j = j + 5;   	break;
			case 'd': morse[j] = '-'; morse[j + 1] = '.'; morse[j + 2] = '.'; morse[j + 3] = ' '; j = j + 4; 	break;
			case 'e': morse[j] = '.'; morse[j + 1] = ' ';j = j + 2; 	break;
			case 'f': morse[j] = '.'; morse[j + 1] = '.'; morse[j + 2] = '-'; morse[j + 3] = '.'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'g': morse[j] = '-'; morse[j + 1] = '-'; morse[j + 2] = '.'; morse[j + 3] = ' '; j = j + 4; 	break;
			case 'h': morse[j] = '.'; morse[j + 1] = '.'; morse[j + 2] = '.'; morse[j + 3] = '.'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'i': morse[j] = '.'; morse[j + 1] = '.'; morse[j + 2] = ' '; j = j + 3; 	break;
			case 'j': morse[j] = '.'; morse[j + 1] = '-'; morse[j + 2] = '-'; morse[j + 3] = '-'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'k': morse[j] = '-'; morse[j + 1] = '.'; morse[j + 2] = '-'; morse[j + 3] = ' '; j = j + 4; 	break;
			case 'l': morse[j] = '.'; morse[j + 1] = '-'; morse[j + 2] = '.'; morse[j + 3] = '.'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'm': morse[j] = '-'; morse[j + 1] = '-'; morse[j + 2] = ' '; j = j + 3; 	break;
			case 'n': morse[j] = '-'; morse[j + 1] = '.'; morse[j + 2] = ' '; j = j + 3; 	break;
			case 'o': morse[j] = '-'; morse[j + 1] = '-'; morse[j + 2] = '-'; morse[j + 3] = ' '; j = j + 4; 	break;
			case 'p': morse[j] = '.'; morse[j + 1] = '-'; morse[j + 2] = '-'; morse[j + 3] = '.'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'q': morse[j] = '-'; morse[j + 1] = '-'; morse[j + 2] = '.'; morse[j + 3] = '-'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'r': morse[j] = '.'; morse[j + 1] = '-'; morse[j + 2] = '.'; morse[j + 3] = ' '; j = j + 4; 	break;
			case 's': morse[j] = '.'; morse[j + 1] = '.'; morse[j + 2] = '.'; morse[j + 3] = ' '; j = j + 4; 	break;
			case 't': morse[j] = '-'; morse[j + 1] = ' '; j = j + 2; 	break;
			case 'u': morse[j] = '.'; morse[j + 1] = '.'; morse[j + 2] = '-'; morse[j + 3] = ' '; j = j + 4; 	break;
			case 'v': morse[j] = '.'; morse[j + 1] = '.'; morse[j + 2] = '.'; morse[j + 3] = '-'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'w': morse[j] = '.'; morse[j + 1] = '-'; morse[j + 2] = '-'; morse[j + 3] = ' '; j = j + 4; 	break;
			case 'x': morse[j] = '-'; morse[j + 1] = '.'; morse[j + 2] = '.'; morse[j + 3] = '-'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'y': morse[j] = '-'; morse[j + 1] = '.'; morse[j + 2] = '-'; morse[j + 3] = '-'; morse[j + 4] = ' '; j = j + 5; 	break;
			case 'z': morse[j] = '-'; morse[j + 1] = '-'; morse[j + 2] = '.'; morse[j + 3] = '.'; morse[j + 4] = ' '; j = j + 5; 	break;
			default: morse[j] = ' ';
		}
			
	}
	printf("Morse code:\n");
	printf("%.*s\n", j, morse);
	
	// play morse code beeps
	for(i = 0; i < j; i++)
	{
		if(morse[i] == '.')
		{
			play(800, 500);
    		
		}
		else if(morse[i] == '-')
		{
			play(800, 900);
    			
		}
		else
		{
			sleep(1);
		}
		
	}
}

void checkNumberAmount(char text[], int size)
{
	int sum = 0;
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 48; j <= 57; j++) // from ASCII table
		{
			if((int)text[i] == j)
				sum++;
		}
	}
	if(sum == 5)
		printf("You have exactly 5 numbers in the text!\n");
	else
		printf("You have %d numbers in the text!\n", sum);
}

