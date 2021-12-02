#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *myfile;  // pointer to file
	char row1[256];
	
	char filename_1[] ="file_folder\\read.txt"; // note 2 backslashes
	
	// open for reading
	myfile = fopen(filename_1, "r"); // read mode
	
	// check if it can be opened
	if(myfile == NULL)
	{
		printf("Cannot open now \n");
		return;
	}
	
	// read
	fgets(row1, 200, myfile); // fgets
	fclose(myfile);
	
	printf("print content of file: \n%s \n", row1);
	
	// open for writing
	char *filename_2 = "file_folder\\write.txt";
	myfile = fopen(filename_2, "w");
	
	// check if it can be opened
	if(myfile == NULL)
	{
		printf("Cannot open!!! \n");
		return;
	}
	
	// write
	fprintf(myfile, "%s", "Greetings from me!");
	fclose(myfile);
	
	return 0;
}
