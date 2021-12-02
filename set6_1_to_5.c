#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

// task 2
void morseConvert(char text[], int length); // I did this before going through the task in the class, I assumed we had to actually convert, not only print.
void toMorse(char message[], int size); // kauko's version done during lecture

// task 3
void checkPostcode(char text[], int size);

// task 4
void checkEmail(char text[], int size);

int main()
{
	// Set 6
	
	// task 1
	srand(time(NULL));
	int input;
	printf("Give the amount of values:\n");
	scanf("%d", &input);
	int * arr = calloc(input, 4); // int => 4 bytes, calloc allows for bigger arrays because it's stored in memory heap instead of stack
	int i;
	for(i = 0; i < input; i++)
		arr[i] = rand() % 1000 + 1; // between 1 and 1000
		
	for(i = 0; i < ((input < 10) ? input : 10); i++) // up to 10 are printed
		printf("%d\n", arr[i]);
	
	// task 2
	
	char text[] = "hello world"; // morse code converter
	int length = sizeof(text)/sizeof(text[0]);
	// function call comes last because beeps take so long
	
	//task 2 kauko's version
	
	char * message = "HELLO WORLD";
	toMorse(message, strlen(message));
	
	// task 3
	
	char postchars[] = "68600";
	int len = strlen(postchars);
	checkPostcode(postchars, len);	// check if it's exactly 5 numbers long
	
	// task 4
	
	char email[] = "john.smith@tmail.com";
	int size = strlen(email);
	checkEmail(email, size);
	
	// task 5
	
	char url[] = "www.centria.fi";
	char * domain;
	domain = strrchr(url, '.');
	memmove(domain, domain + 1, strlen(domain)); // remove the dot by moving the array forward one element
	printf("%s\n", domain);
	
	// task 2: morse with beeps
	
	morseConvert(text, length);
	
	return 0;
}

void morseConvert(char text[], int length)
{
	/*
	a = ".-" ; b = "-..."; c = "-.-."; d = "-.."; e = "."; f = "..-."; g = "--.";
	h = "...."; i = ".."; j = ".---"; k = "-.-"; l = ".-.."; m = "--"; n = "-.";
	o = "---"; p = ".--."; q = "--.-"; r = ".-."; s = "..."; t = "-"; u = "..-";
	v = "...-"; w = ".--"; x = "-..-"; y = "-.--"; z = "--..";
	*/
	
	char * morse = calloc(length * 5, 1);
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
	printf("Morse code with beeps:\n");
	printf("%.*s\n", j, morse); // prevents printing out of bound (not needed because of null terminator) 
	
	// play morse code beeps, but it takes a while!
	
	for(i = 0; i < j; i++)
	{
		if(morse[i] == '.')
		{
			Beep(800, 500);
    		
		}
		else if(morse[i] == '-')
		{
			Beep(800, 900);
    			
		}
		else
		{
			sleep(1);
		}		
	}
}

void toMorse(char message[], int size) // kauko's version
{
	printf("Morse code:\n");
	int i;
	for(i = 0; i < size; i++)
		switch (message[i])
		{
			case 'A': printf(".- "); break;
			case 'B': printf("-... "); break;
			case 'C': printf("-.-. "); break;
			case 'D': printf("-.. "); break;
			case 'E': printf(". "); break;
			case 'F': printf("..-. "); break;
			case 'G': printf("--. "); break;
			case 'H': printf(".... "); break;
			case 'I': printf(".. "); break;
			case 'J': printf(".--- "); break;
			case 'K': printf("-.- "); break;
			case 'L': printf(".-.. "); break;
			case 'M': printf("-- "); break;
			case 'N': printf("-. "); break;
			case 'O': printf("--- "); break;
			case 'P': printf(".--. "); break;
			case 'Q': printf("--.- "); break;
			case 'R': printf(".-. "); break;
			case 'S': printf("... "); break;
			case 'T': printf("- "); break;
			case 'U': printf("..- "); break;
			case 'V': printf("...- "); break;
			case 'W': printf(".-- "); break;
			case 'X': printf("-..- "); break;
			case 'Y': printf("-.-- "); break;
			case 'Z': printf("--.. "); break;
		}
	printf("\n");
}

void checkPostcode(char text[], int size)
{
	int sum = 0;
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 48; j <= 57; j++) // numbers positions from ASCII table
		{
			if((int)text[i] == j)
				sum++;
		}
	}
	if(sum == 5)
	{
		printf("Yes! You have exactly 5 numbers in the postal code!\n");
		if(size != 5)
			printf("However, you seem to have extra letters or whitespaces in your postal code.\n");
	}	
		
	else
		printf("Wrong amount! You have %d numbers in the post code, it should be 5!\n", sum);
}

void checkEmail(char text[], int size)
{
	int i;
	int found = 0;
	for(i = 0; i < size; i++)
		if(text[i] == '@')
		{
			found = 1;
		}
	
	if(found == 1)	
		printf("your email contains @\n");
	else
		printf("you forgot @ in your email\n");	
}


