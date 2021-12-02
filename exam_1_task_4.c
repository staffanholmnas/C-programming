#include <stdio.h>

int main()
{
	
	// task 4
	
	/*
	Tictactoe
	Create a 3x3 array. 
	Add for example these values (or decide yourself):
	x o x
	x o x
	o x o
	Print the array.
	
	*/
	
	char x = 'x';
	char o = 'o';
	int row,col;
	int turns = 0;
	
	char arr[3][3];
	
	arr[0][0] = x; arr[0][1] = o; arr[0][2] = x;
	arr[1][0] = x; arr[1][1] = o; arr[1][2] = x;
	arr[2][0] = o; arr[2][1] = x; arr[2][2] = o;
		
	// print the array
	for(row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			printf("%c ", arr[row][col]);
		}
		printf("\n");
	}	
	
	// -------------------------------------------------
	
	printf("\nNow let's play!\n \n");
	
	int turn = 1;
	int gameover = 0;
	int winner = 0;
	char who_won;
	int sel_row, sel_col;
	int switch_player = 0;
	char player;
	
	for(row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{	
				arr[row][col] = '_';
			}
		}
		
	
	while(!gameover)
	{
		if (switch_player == 0)
			player = 'x';
		else
			player = 'o';
			
		printf("\nIt's %c turn. In which row do you want to put the %c? 0-2:\n", player, player );
		scanf("%d", &sel_row);
	
		printf("In which column do you want to put the %c ? 0-2:\n", player);
		scanf("%d", &sel_col);
		
		for(row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (row == sel_row && col == sel_col)
					if (arr[row][col] == 'x' || arr[row][col] == 'o')
					{
						printf("Can't play there, the spot is already taken.\n");
						switch_player = !switch_player; // switch player just temporarily
					}
					else
					{
						arr[row][col] = player;
						turns++;
					}
						
			}
		}
		
		// print the array
		printf("\n");
		
		for(row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				printf("%c ", arr[row][col]);
			}
			printf("\n");
		}
		
	
		/*
		arr[0][0] = '_'; arr[0][1] = '_'; arr[0][2] = '_';
		arr[1][0] = '_'; arr[1][1] = '_'; arr[1][2] = '_';
		arr[2][0] = '_'; arr[2][1] = '_'; arr[2][2] = '_';
		*/
		
		// check for winner
		
		for(row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (arr[row][0] == 'x' && arr[row][1] == 'x' && arr[row][2] == 'x' || arr[0][col] == 'x' && arr[1][col] == 'x' && arr[2][col] == 'x')
				{
					winner = 1;
					who_won = 'x';
					turns = 9; // ends the game with x as the winner
				}
				else
				if (arr[row][0] == 'o' && arr[row][1] == 'o' && arr[row][2] == 'o' || arr[0][col] == 'o' && arr[1][col] == 'o' && arr[2][col] == 'o')
				{
					winner = 1;
					who_won = 'o';
					turns = 9; // ends the game with o as the winner
				}
				if (winner == 1)
					break;
			}
			if (winner == 1)
				break;
		}	
		
		switch_player = !switch_player;
		
		if (turns == 9)
			gameover = 1;
			
	}
	
	// check who won
	printf("The game has ended\n");
	
	printf("The winner is %c \n", who_won);
	
	return 0;
}
