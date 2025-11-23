#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int runLevelOne(int *score){
	int first_num, current_num;
	int first_letter, current_letter;
	int sequence_length, common_diff;
	
	int player_guess, correct_answer;
	char player_char_guess;
	
	int sequence_type = rand() % 2;
	int min = 1, max = 10;
	
	promptRoll();
	
	int roll = diceRoll(); // Getting the points for the player's turn
	
	*score += roll; //Player moves up __ spaces
	printf("\t\t>>> Current score: %d <<<\n\n", *score);
	
	// Generating a random number sequence
	if(sequence_type == 1){
		
		first_num = rand() % 100 + 1;
		common_diff = giveRandNums(min, max);
		current_num = first_num;

		printf("=======================================================\n");	
	    printf("Find the next number in the sequence: ");
		    
		for(sequence_length = 0; sequence_length < 5; sequence_length++){
		
			printf("%d ", current_num);
		
			current_num = current_num + common_diff;
			
		}
		printf("\n=======================================================\n");
		
		correct_answer = current_num;
	}
	//Generating a random letter sequence
	else{
		common_diff = giveRandNums(min, max);
		
		first_letter = (rand() % ('W' - 'A' + 1) + 'A');
		
		current_letter = first_letter;
		
		printf("=======================================================\n");
		printf("Find the next letter in the sequence: ");
		
		for (sequence_length = 0; sequence_length < 5; sequence_length++) {
	            
	            printf("%c ", current_letter);
	            
	            // Calculate the next term
	            current_letter = current_letter + common_diff;
	            
	            // Handle wrap-around: If past 'Z', loop back to 'A'
	            if (current_letter > 'Z') {
	                current_letter = current_letter - ('Z' - 'A' + 1); // Subtract 26
	            }
	        }
	    printf("\n=======================================================\n");
	    
        correct_answer = current_letter;
	}
    
	// Getting the player's answer 
    printf("\n\nWhat is the next number/letter? ");
    
    // Changes the scanf type since we will be getting two possible types of inputs
	if(sequence_type == 1){
		scanf("%d", &player_guess);
	}
	else {
		// Reads char value, converts to uppercase, then to integer
		scanf(" %c", &player_char_guess);
		player_char_guess = toupper(player_char_guess);
		player_guess = (int)player_char_guess;
	}
	
	// Scoring
	
	// The player gets the right answer
    if (player_guess == correct_answer) {
        printf("Correct! You guessed it right!\n\n\n");
        printf("\t>>> You have successfully moved up %d spaces! <<<\n\n", roll);
    } 
    // The player gets the wrong answer
	else{
        printf("Incorrect. The next term in the sequence was: ");
        
        if(sequence_type == 1){
        	printf("%d\n", correct_answer);
		}
		else{
			printf("%c\n", (char)correct_answer);
		}
        
    	*score = playerPunish(*score);
    }
    
	printf("\t     >>> Your current score is now: %d <<<\n\n", *score);
	
	return roll;
}

int runLevelTwo(int *score){
	int first_num, current_num;
	int first_letter, current_letter;
	int sequence_length, common_diff;
	
	int player_guess1, player_guess2;
	int correct_answer1, correct_answer2;
	char player_char_guess1, player_char_guess2;
	
	int sequence_type = rand() % 2;
	int min = 1, max = 10;
	
	promptRoll();
	
	int roll = diceRoll(); // Getting the points for the player's turn
	
	*score += roll; //Player moves up __ spaces
	printf("\t\t>>> Current score: %d <<<\n\n", score);
		
	// Generating a random number sequence
	if(sequence_type == 1){
		
		first_num = rand() % 100 + 1;
		common_diff = giveRandNums(min, max);
		current_num = first_num;

		printf("=======================================================\n");	
	    printf("Find the next TWO numbers in the sequence: ");
		    
		for(sequence_length = 0; sequence_length < 5; sequence_length++){
		
			printf("%d ", current_num);
		
			current_num = current_num + common_diff;
			
		}
		printf("\n=======================================================\n");
		
		correct_answer1 = current_num;
		current_num = current_num + common_diff; //Getting the seventh term
		correct_answer2 = current_num;
	}
	//Generating a random letter sequence
	else{
		common_diff = giveRandNums(min, max);
		
		first_letter = (rand() % ('W' - 'A' + 1) + 'A');
		
		current_letter = first_letter;
		
		printf("==========================================================\n");
		printf("Find the next TWO letters in the sequence: ");
		
		for (sequence_length = 0; sequence_length < 5; sequence_length++) {
	            
	            printf("%c ", current_letter);
	            
	            // Calculate the next term
	            current_letter = current_letter + common_diff;
	            
	            // Handle wrap-around: If past 'Z', loop back to 'A'
	            if (current_letter > 'Z') {
	                current_letter = current_letter - ('Z' - 'A' + 1); // Subtract 26
	            }
	        }
	    printf("\n==========================================================\n");
	    
        correct_answer1 = current_letter;
        current_letter = current_letter + common_diff;
        if(current_letter > 'Z'){
        	current_letter = current_letter - ('Z' - 'A' + 1);
		}
		correct_answer2 = current_letter;
	}
    
	// Getting the player's FIRST answer 
    printf("\n\nWhat is the sixth number/letter in the sequence? ");
    	// Changes the scanf type since we will be getting two possible types of inputs
		if(sequence_type == 1){
			scanf("%d", &player_guess1);
		}
		else {
			// Reads char value, converts to uppercase, then to integer
			scanf(" %c", &player_char_guess1);
			player_char_guess1 = toupper(player_char_guess1);
			player_guess1 = (int)player_char_guess1;
		}
	// Getting the player's SECOND answer
	printf("What is the seventh number/letter in the sequence? ");
    	// Changes the scanf type since we will be getting two possible types of inputs
		if(sequence_type == 1){
			scanf("%d", &player_guess2);
		}
		else {
			// Reads char value, converts to uppercase, then to integer
			scanf(" %c", &player_char_guess2);
			player_char_guess2 = toupper(player_char_guess2);
			player_guess2 = (int)player_char_guess2;
		}
	
	
	// Scoring
	
	// The player gets the right answer
    if (player_guess1 == correct_answer1 && player_guess2 == correct_answer2) {
        printf("Correct! You got both terms right!\n\n");
        printf("\t>>> You have successfully moved up %d spaces! <<<\n\n", roll);
    } 
    // The player gets the wrong answer
	else{
        printf("Incorrect. The next two terms in the sequence are: ");
        
        if(sequence_type == 1){
        	printf("%d and %d\n", correct_answer1, correct_answer2);
		}
		else{
			printf("%c and %c\n", (char)correct_answer1, (char)correct_answer2);
		}
        
    	*score = playerPunish(*score);
    }
    
    printf("\t     >>> Your current score is now: %d <<<\n\n", score);
		
	return *score;
}

int runLevelThree(int *score){
	int first_num, current_num;
	int first_letter, current_letter;
	int sequence_length, common_diff;
	
	int player_guess1, player_guess2;
	int player_guess_char1, player_guess_char2; 
	char char_input1, char_input2; //We need this for the raw scanf input
	
	int correct_num1, correct_num2;
	int correct_char1, correct_char2;
	
	int min = 1, max = 3;

	common_diff = giveRandNums(min, max);
    
    first_num = rand() % 10 + 1; // Start with any of the numbers 1-10
    first_letter = (rand() % ('W' - 'A' + 1) + 'A');
    
    current_num = first_num;
    current_letter = first_letter;
	
	
	promptRoll();	// Prompts user to roll
	int roll = diceRoll(); // Getting the points for the player's turn
	
	*score += roll; //Player moves up __ spaces
	printf("\t\t>>> Current score: %d <<<\n\n", score);
	
	printf("===========================================================================\n");	
    printf("Find the next TWO terms in this combined sequence: ");
    
    for(sequence_length = 0; sequence_length < 5; sequence_length++){
    	printf("%c%d ", (char)current_letter, current_num);
    	
    	current_num = current_num + common_diff;
    	current_letter = current_letter + common_diff;
    	
    	if(current_letter > 'Z'){
    		current_letter = current_letter - ('Z' - 'A' + 1);
		}	
	}
	
	printf("\n===========================================================================\n");
	
	//Getting the 6th Term Answer
	correct_char1 = current_letter;
	correct_num1 = current_num;
	
	//Getting the 7th Term
	current_num = current_num + common_diff;
	current_letter = current_letter + common_diff;
	if(current_letter > 'Z'){
		current_letter = current_letter - ('Z' - 'A' + 1);
	}
	
	//Getting the 7th Term Answer
	correct_char2 = current_letter;
	correct_num2 = current_num;
	
	// Getting the player's FIRST answer 
    printf("\n\nWhat is the SIXTH term in the sequence? (e.g. enter a letter then a number, like G10)\n");
	printf("Take note that answers with spaces in between, like 'G 10' will not work\n\n");
	printf("Your Answer: ");
	scanf(" %c%d", &char_input1, &player_guess1);
	
	//Converting to uppercase
	char_input1 = toupper(char_input1);
	player_guess_char1 = (int)char_input1;

		// Getting the player's SECOND answer 
    printf("\n\nWhat is the SEVENTH term in the sequence? (e.g. enter a letter then a number, like G10)\n");
	printf("Remember that answers with spaces in between, like 'G 10' will not work\n\n");
	printf("Your Answer: ");
	scanf(" %c%d", &char_input2, &player_guess2);
	
	//Converting to uppercase
	char_input2 = toupper(char_input2);
	player_guess_char2 = (int)char_input2;
	
	
	//Scoring
	
	// Player gets all terms right
    if (player_guess_char1 == correct_char1 && 
        player_guess1 == correct_num1 &&
        player_guess_char2 == correct_char2 &&
        player_guess2 == correct_num2) {
        
        printf("Correct! You got both complex terms right!\n\n");
        printf("\t>>> You have successfully moved up %d spaces! <<<\n\n", roll);
    }
    
    // Player gets the wrong answer
	else{
        printf("Incorrect. The next two terms in the sequence are: ");
        
        printf("%c%d and %c%d\n", (char)correct_char1, correct_num1,(char)correct_char2, correct_num2);
        
        *score = playerPunish(*score);
    }
    
    printf("\t     >>> Your current score is now: %d <<<\n\n", score);
        
    return *score;
}

int selectLevel(int Level){	
	int check_scanf; // Checking if the given input is valid
	
	do{
		
		printf("=======================================================================\n");
		printf("\t\t   Pick any of the levels below!\n\n");
		printf("\t --- LEVEL 1     (Number & Letter Sequences)      ---\n");
		printf("\t --- LEVEL 2     (Number & Letter Sequences)      ---\n");
		printf("\t --- LEVEL 3 (Combined Number & Letter Sequences) ---\n\n");
		printf("=======================================================================\n\n");
		printf("Select the game difficulty: ");
		
		check_scanf = scanf("%d", &Level);
		
		
		if(check_scanf == 1)
			switch(Level)
			{
				case 1:
					printf("\n\n\t\t>>> You have selected the Easy Difficulty <<<\n\n");
					printf("\tThe following sequence problems will deal with numbers and letters\n");
					printf("\tWhile asking for the next term in the sequence!(e.g. A B C D __)\n\n\n");
					return 1;
				case 2:
					printf("n\n\t\t>>> You have selected the Medium Difficulty <<<\n\n");
					printf("\tThe following sequence problems will deal with numbers and letters\n");
					printf("\tWhile asking for the next term in the sequence!(e.g. 1 3 5 7 __ __)\n\n\n");
					return 2;
				case 3:
					printf("\n\n\t\t>>> You have selected the Hard Difficulty <<<\n\n");
					printf("\tThe following sequence problems will deal with combined letter and number sequences\n");
						printf("\tWhile asking for the next TWO terms in the sequence!(e.g. A1 C3 E5 G7 __ __)\n\n\n");
					return 3;
				default:
					break;
			}
		else {
			printf("ERROR: Invalid Input! Please try again...");
			
			Level = 0;
		}
	}while(Level < 1 || Level > 3);
}

int numPlayers(int nPlayers){
	int check_scanf;
	
    printf("========================================================\n");
	printf("How many players will be playing the game?\n\n");
    printf("\tSingle Player\n");
    printf("\t2 Players\n");
    printf("\t3 Players\n");
    printf("\t4 Players\n");

	do {
        printf("\nPlease input a value between 1 and 4: ");
        check_scanf = scanf("%d", &nPlayers);

        if (check_scanf == 1) {
            // Check if the inputs given are correct
            switch (nPlayers) {
                case 1:
                case 2:
                case 3:
                case 4:
                    // If the given input is 1, 2, 3, or 4, it passes the check
                    printf("\n\nYou will now play in %d player mode.\n", nPlayers);
                    return nPlayers;
                default:
                    // Otherwise
                    printf("========================================================\n");
					printf("\n!!! Please pick within the options given !!!\n\n");
    				printf("\tSingle Player\n");
				    printf("\t2 Players\n");
				    printf("\t3 Players\n");
				    printf("\t4 Players\n");
				    printf("========================================================\n");
                    break;
            }
        } else {
            // ERROR INPUT
            printf("\nInvalid input! Please only enter a number between 1 and 4...\n");
            
            nPlayers = 0; // Reset value to redo the loop
        }
    } while (true); // Loop runs until a valid number is returned
}

int runPlayerTurn(int player_turn, int numberofPlayers, int Level, int *scoreP1, int *scoreP2, int *scoreP3, int *scoreP4){
	int score_display;
	int current_player = player_turn + 1;
	int roll_result = 0; //we are using this to catch if the player rolls a 6

	int *scoreToUpdate = NULL;
	
	switch(current_player){
		case 1:
			scoreToUpdate = scoreP1;
			break;
		case 2:
			scoreToUpdate = scoreP2;
			break;
		case 3:
			scoreToUpdate = scoreP3;
			break;
		case 4:
			scoreToUpdate = scoreP4;
			break;
		default:
			printf("!!! ERROR: Invalid player count !!!");
			break;
	}
	
	score_display = *scoreToUpdate;
	
	printf("=======================================================================\n\n");
	printf("\n\t  =======================================================\n");
    printf("\t    >>> It is now Player %d's turn! Current Score: %d <<<\n", current_player, score_display);
    printf("\t  =======================================================\n\n");
    
    switch(Level){
    	case 1:
    		roll_result = runLevelOne(scoreToUpdate);
    		break;
    	case 2:
    		roll_result = runLevelTwo(scoreToUpdate);
    		break;
    	case 3:
    		roll_result = runLevelThree(scoreToUpdate);
    		break;
    	default:
    		break;
	}
	
	return roll_result;
}

