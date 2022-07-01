#ifdef _WIN32 // If user is running Windows
#include <Windows.h> // Include Windows header which includes sleep
#else // If the above condition was not met, so user is not running Windows
#include <unistd.h> // Include unistd header which also includes sleep
#endif // End if statement

#include <stdio.h> // Include standard library
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> // Include time header

int playerRoll(int whoseTurn) { // Declare integer function called playerRoll that takes in one integer as a parameter
	printf("It is player %d's turn.\n",whoseTurn); // State which player's turn it is
	printf("Press enter to roll the dice... "); // Prompt the user to press enter (or any key really)
	getchar(); // Get character, this will indicate a key has been pressed

	printf("Rolling first dice...\n"); // State the first dice is "rolling"
	sleep(2); // Wait 2 seconds
	int firstRoll = rand() % 6; // Declare integer variable firstRoll and set it to a random number between 0 and 5
	firstRoll++; // Add 1 because you cannot roll a 0
	printf("First dice rolled %d.\n",firstRoll); // State the first roll

	printf("Rolling second dice...\n"); // Do the same but with the second dice
	sleep(2);
	int secondRoll = rand() % 6;
	secondRoll++;
	printf("Second dice rolled %d.\n",secondRoll);

	int totalRoll = firstRoll + secondRoll; // Declare integer variable totalRoll and set it to the sum of firstRoll and secondRoll
	printf("Player %d rolled %d.\n",whoseTurn,totalRoll); // State the total roll of the player

	return totalRoll; // Return totalRoll
}

int main() { // Declare integer variable called main which will be executed upon running the program
	srand(time(NULL)); // Initialise random

	while (true) { // Execute the following code in a loop until told otherwise
		#ifdef _WIN32 // If user is running Windows
		system("cls"); // Run cls command to clear terminal window
		#else // If the above condition was not met, so user is not running Windows
		system("clear"); // Run clear command to clear terminal window
		#endif // End if statement

		printf("Welcome to DiceRoll!\n"); // Welcome message
		printf("Developed by Chas.\n");
		int rounds; // Declare integer variable rounds
		printf("How many rounds would you like to play? "); // Ask user how many rounds they want to play
		scanf("%d",&rounds); // Get the input and assign it to rounds
		getchar(); // Get character, this is to stop the getchar in playerRoll getting confused in the first round

		int player1Score = 0; // Declare integer variable player1Score and define it as 0
		int player2Score = 0;

		while (rounds > 0) { // While rounds is more than 0
			#ifdef _WIN32
			system("cls");
			#else
			system("clear");
			#endif

			printf("Player 1 score: %d.\n",player1Score); // State player 1's score
			printf("Player 2 score: %d.\n",player2Score);
			printf("Rounds remaining: %d.\n",rounds); // State how many rounds are left

			int player1Roll = playerRoll(1); // Declare an integer variable called player1Roll and define it to the output of playerRoll with 1 substituted in for whoseTurn
			int player2Roll = playerRoll(2);

			if (player1Roll > player2Roll) { // If player 1 rolled a higher total than player 2
				player1Score++; // Increment player1Score by 1
				printf("Player 1 won by a difference of %d.\n",player1Roll-player2Roll); // State the difference by which player 1 won
			}
			else if (player2Roll > player1Roll) { // Otherwise, if player 2 rolled a higher total than player 1
                        	player2Score++;
                        	printf("Player 2 won by a difference of %d.\n",player2Roll-player1Roll);
			}
			else if (player1Roll == player2Roll) { // Otherwise, if player 1 and player 2 rolled the same total
				player1Score++; // Increment both scores
				player2Score++;
				printf("Player 1 and player 2 rolled the same number in total, therefore it is a draw.\n"); // State that it is a draw, no need to compare difference because there is none
			}
			rounds--; // Decrease rounds by 1

			if (rounds == 0) { break; } // If rounds is 0, break to avoid countdown

			printf("Starting next round in "); // State the next round is going to start soon
			for (int i = 5; i > 0; i--) { // Set i to 5, decrease it until it reaches 0
				printf("%d ",i); // Print the value of i
				fflush(stdout); // Flush stdout
				sleep(1); // Wait 1 second
			}
			continue; // Restart loop
		}

		printf("Game over.\n"); // Say the game is finished
		printf("Player 1 scored %d points.\n",player1Score); // State player 1's total score
		printf("Player 2 scored %d points.\n",player2Score);

		if (player1Score > player2Score) { // If player 1's score is more than player 2's score
			printf("Player 1 wins by a difference of %d.\n",player1Score-player2Score); // State player 1 wins and the difference
		}
		else if (player2Score > player1Score) { // Otherwise, if player 2's score is more than player 1's score
                	printf("Player 2 wins by a difference of %d.\n",player2Score-player1Score);
		}
		else if (player1Score == player2Score) { // Otherwise, if player 1's score is equal to player 1's score
			printf("Player 1 and player 2 scored the same number of points, so it is a draw.\n");  // State the two players drew
		}

		int runAgain; // Declare integer variable called runAgain
		printf("Would you like to run again?\n");
		printf("Type 1 for yes, 2 for no.\n");
		while (true) {
			printf("Enter an option: "); // Prompt users for option
			scanf("%d",&runAgain); // Assign input to runAgain
			if (runAgain != 1 && runAgain != 2) { printf("Invalid option.\n"); continue; } // If runAgain is neither 1 nor 2, state it is invalid and restart loop
			else { break; } // If it is 1 or 2, then break out of loop
		}
		if (runAgain == 1) { continue; } // If runAgain is 1, restart loop
		else if (runAgain == 2) { printf("Goodbye.\n"); break; } // If runAgain is 2, say goodbye and break out of loop
	}

	return 0; // Return 0 to show program executed successfully
}
