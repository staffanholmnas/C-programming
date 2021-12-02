#include <stdio.h>
#include <stdlib.h>

struct Element
{
	int data;
};

struct Node
{
	int data;
	struct Node * next;
};

int main()
{
	struct Element first;
	first.data = 100;
	
	printf("%d \n", first.data);
	printf("\n");	
	
	struct Element datalist[10];
	
	int i;
	for(i = 0; i < 10; i++)
		datalist[i].data = i;
		
	for(i = 0; i < 10; i++)
		printf("%d \n", datalist[i].data);
	
	printf("\n");
	
	
	// let's create a Linked List of nodes that is more flexible than an array, which has fixed size.
	
	// 3, 44, 777, -99, 0
	struct Node * start = malloc(sizeof(struct Node)); // allocate memory to the first node
	start->data = 3; 
	// arrow operator is used instead of a dot to access a member of a struct which is referenced by a pointer
	// example: foo->bar is only shorthand for (*foo).bar
	
	struct Node * temp = malloc(sizeof(struct Node));
	temp->data = 44;
	
	// connect
	start->next = temp;
	
	struct Node * last = temp; // temp is the last node
	
	temp = malloc(sizeof(struct Node)); // allocate more memory for a new node
	temp->data = 777; // create another node outside of the list
	
	// connect
	last->next = temp;
	
	last = temp; // last points at the temp node
	
	// Add, connect, and change last pointer for a new node
	temp = malloc(sizeof(struct Node));
	temp->data = -99;
	last->next = temp;
	last = last->next;
	
	temp = malloc(sizeof(struct Node));
	temp->data = 0;
	last->next = temp;
	last = last->next;
	
	last->next = NULL; // last node always points to NULL
	
	printf("Linked list:\n");
	
	// print nodes
	printf("%d \n", start->data); // 3
	printf("%d \n", start->next->data); // 44
	printf("%d \n", start->next->next->data); // 777
	printf("%d \n", start->next->next->next->data); // -99
	printf("%d \n", last->data); // 0
	
	// print nodes with a loop
	printf("\n");
	printf("Linked list:\n");
	
	struct Node * p; // counter, a temporary pointer
	for(p = start; p != NULL; p = p->next)
		printf("%d \n", p->data);
	
	// Linked list manipulations
	// add new node to the beginning 12345
	temp = malloc(sizeof(struct Node));
	temp->data = 12345;
	temp->next = start;
	start = temp;
	
	// print to check that it's in the beginning
	printf("\n");
	for(p = start; p != NULL; p = p->next)
		printf("%d \n", p->data);
		
	// add new node to place after the node that has value 44
	temp = malloc(sizeof(struct Node));
	temp->data = -987;
		
	struct Node * previous; // temporary pointers
	struct Node * next;
	for(p = start; p != NULL; p = p->next) 
		if(p->data == 44) // find the node with value 44
		{
			previous = p;
			next = p->next;
			break;
		}
		
	previous->next = temp;
	temp->next = next;
	
	// print
	printf("\n");
	for(p = start; p != NULL; p = p->next)
		printf("%d \n", p->data);
		
	// remove from the beginning by moving the start to the next one
	start = start->next;
	
	// print
	printf("\n");
	for(p = start; p != NULL; p = p->next)
		printf("%d \n", p->data);
	
	// remove the last node by finding the second to last, which is 2 places before null
	for(p = start; p != NULL; p = p->next)
		if(p->next->next == NULL)
			break;
	
	last = p;
	last->next = NULL;
	
	// print
	printf("\n");
	for(p = start; p != NULL; p = p->next)
		printf("%d \n", p->data);
	
	return 0;
}
