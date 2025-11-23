	/***************************************************************************
This is to certify that this project is my own work, based on my personal efforts
in studying and applying the concepts learned. I have constructed the functions
and their respective algorithms and corresponding code by myself. The program
was run, tested, and debugged by my own efforts. I further certify that I have
not copied in part or whole or otherwise plagiarized the work of other students
and/or persons.

Matthew Miguel S. Fabiala, DLSU ID# 12504343
***************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.c"
#include "Game Logic.c"



int main()
{
	int score = 0;
	int numberofPlayers = 0;
	int Level = 0; // Intialize the level
	int player_turn = 0;
	int last_roll = 0;
	int game_running = 1; //Initialize that the game is running (1 means it's running, 0 means it ended)
	
	//Player Scores
	int scoreP1 = 0;
	int scoreP2 = 0;
	int scoreP3 = 0;
	int scoreP4 = 0;
	
	srand(time(NULL));		// seeds the random number generator
	
	printf("Welcome to A Walk in the Sequence Park!\n");
	printf("A mini-game coded by Matthew Miguel S. Fabiala\n");
	printf("For the CCPROG1 Machine Project\n\n");
	
	numberofPlayers = numPlayers(numberofPlayers);
	Level = selectLevel(Level);
	
	// Running the main game logic
	do{
		// Turn will cycle if the last roll is not 6
		if(last_roll != 6){
			player_turn = player_turn % numberofPlayers;
		}
		else{
			printf("=======================================================================\n\n\n\n\n\n");
			printf(">>> You have rolled a 6 on the dice last turn! You now get an extra turn!!! <<<\n\n\n\n\n\n");
		}
		
		//Run the turn and CAPTURE THE VALUE of the resulting roll
		last_roll = runPlayerTurn(player_turn, numberofPlayers, Level, &scoreP1, &scoreP2, &scoreP3, &scoreP4);
		
		switch(player_turn + 1){
			case 1:
				score = scoreP1;
				break;
			case 2: 
				score = scoreP2;
				break;
			case 3:
				score = scoreP3;
				break;
			case 4:
				score = scoreP4;
				break;
		}
	
		if(score == 50){
			printf("\n\nPlayer %d wins the game by reaching the 50th tile first! Congratulations!!!", player_turn + 1);
			game_running = 0;
		}
			
		if (last_roll != 6 && game_running){
			player_turn++;
		}	
		//If the player did NOT roll a 6, the player turn is incremented
		
	}while(game_running);
	
	printf("\n\nThe game has ended. Thank you for playing! I hope you enjoyed it <3\n");
	
	return 0;
}


/* Dev Notes:
- Will just see how to make each function work first, before I see how I can
connect each function to work with one another
- My brain hurts
- God bless CCPROG1
*/
