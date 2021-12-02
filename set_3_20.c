#include <stdio.h>

int main()
{	
	/*
	20
Account manager with menu:
User can make deposits
Do withdrawal
Check the balance

Create a menu
take money
add money
check balance
exit

Variable for account balance has to be global!
=> declare it outside (above) the while loop 

When user takes money you have to check if there is enough money...
	*/

// infinite loop
	
	int balance = 300;

	while (1)
	{
	
		int sum;
		int choice = -1;
	
		printf("Choose, please \n");
		printf("1 = print the balance \n");
		printf("2 = Do withdrawal \n");
		printf("3 = Make deposit \n");
		printf("0 = Exit \n");
		printf("Your choice \n");
		scanf("%d", &choice);
	
		if (choice == 0)
			break;
		else if (choice == 1)
			printf("Balance is %d \n", balance);
		else if (choice == 2)
		{
			int takethis;
			printf("How much do you want to take? \n");
			scanf("%d", &takethis);
			if (balance >= takethis)
				balance = balance - takethis;
			else
				printf("Not enough money! \n");
		}
		else if (choice == 3)
		{
			int addthis;
			printf("How much do you want to add? \n");
			scanf("%d", &addthis);
			balance = balance + addthis;
		}	
	}	
	
	return 0;
}
