#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atof()

int main()
{
	// hints, can be deleted
	char * name1 = "bbb";
	char * name2 = "aaa";
	
	int result = strcmp(name1, name2);
	
	printf("%d \n", result);
	
	// string arrays
	
	char * cities[4];
	
	cities[0] = "Kokkola";
	cities[1] = "Vaasa";
	cities[2] = "Vantaa";
	cities[3] = "Lahti";
	int i;
	for(i = 0; i < 4; i++)
		printf("%s \n", cities[i]);
	
	// atof()
	
	char * val = "123.45";
	float numval = atof(val);
	numval *= 10;
	printf("%f \n", numval);
	
	// strchr
	
	char * email = "kk@kkk.fi";
	char * place = strchr(email, '@');
	printf("%s \n", place);
	int position = place - email;
	printf("%d \n", position);
	printf("%c \n", email[position]);
	
	// task 3 hint. check postcode
	
	char * postcode = "686a00";
	int size = strlen(postcode);
	
	
	for(i = 0; i < size; i++)
		if ( postcode[i] < '0' || postcode[i] > '9')
		{
			printf("not a number");
		}
	
	// task 10 can be found on kauko's youtube or online.
	
	// task 11 can be skipped
	
	
	return 0;
}
