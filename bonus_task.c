#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bonus task
// read a textfile to a) an array b) to a linked list
// print the contents

struct Node
{
	char *word;
	struct Node * next;
};

void printNodes(struct Node * head);
void printArray(char * word_arr[], int size);

int main()
{
	// Read a text file word by word to an array, then print every word in the array.
	FILE *myfile;
	char *word_array[1000];
	int size = sizeof(word_array)/sizeof(word_array[0]);
	
	// open
	myfile = fopen("text1.txt", "r");
	
	if(myfile == NULL)
	{
		printf("The file cannot be opened! \n");
		return;
	}
	
	char temp[30]; // store a max 30 letter word temporarily
	
	// read
	int i;
	int word_count = 0;
	for(i = 0; i < size; i++)
	{
		if(fscanf(myfile, "%s", temp) != 1) // read until end of file
			break;
		
		word_array[i] = malloc(sizeof(temp)/sizeof(temp[0])); 
		strcpy(word_array[i], temp);
		word_count++;
	}
	
	// print
	printArray(word_array, word_count);
	printf("\n");
	//-----------------------------------------------------
	
	// Read a text file word by word to a linked list and then print the list.
	
	struct Node * head = malloc(sizeof(struct Node));
	struct Node * temp_node = malloc(sizeof(struct Node));
	struct Node * tail = malloc(sizeof(struct Node));
	
	rewind(myfile); // moves the file pointer back to the beginning of the stream
	
	for(i = 0; i < word_count; i++)
	{
		
		if(fscanf(myfile, "%s", temp) != 1) // read until end of file
			break;
		
		if(i == 0)
		{
			head->word = malloc(sizeof(temp));
			strcpy(head->word, temp);
		}
		else if(i == 1)
		{
			temp_node->word = malloc(sizeof(temp));
			strcpy(temp_node->word, temp);
			head->next = temp_node;
			tail = temp_node;
		}
	
		else
		{
			temp_node = malloc(sizeof(struct Node));
			temp_node->word = malloc(sizeof(temp));
			strcpy(temp_node->word, temp);
			tail->next = temp_node;
			tail = temp_node;
		}
	}
	
	fclose(myfile);
	
	tail->next = NULL;
	
	printNodes(head);
	
	return 0;
}

void printNodes(struct Node * head)
{
	struct Node * p; // counter, a temporary pointer
	printf("\n");
	for(p = head; p != NULL; p = p->next)
		printf("%s ", p->word);
}

void printArray(char * word_arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%s ", word_arr[i]);
}
