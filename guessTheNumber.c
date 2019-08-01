// Guess the Number game


// 3 gamemodes

/*
1. Player vs. Player (PvP)

	Player 1 will type in a number between 1 and 100, Player 2 will guess Player 1's number
	Player 2 has 10 guesses

2. Player vs. Computer (PvC)

	Computer will randomly select a number, Player will guess the Computer's number

3. Computer vs. Computer (CvC)

	Computer 1 will randomly select a number, Computer 2 will guess the Computer 1's number

Gamemode 1 -- PvP

	scanf for Player 1 number
	hide the number
	prompt Player 2 for guesses (10 guesses)

Gamemode 2 -- PvC

	Computer uses random number generator between 1 and 50 and select the random number
	prompt Player for guesses (10 guesses)

Gamemode 3 -- CvC

	Computer 1 uses random number generator between 1 and 50 and select the random number
	Computer 2 also uses a random generator between 1 and 50 and guesses the right number
	For this gamemode, Computer 2 will have unlimited guesses, Player can watch how many guesses
	it took for Computer 2 to guess Computer 1's number

Win condition -- correctGuesses

	Player / Computer guesses the correct number

Lose condition -- wrongGuesses

	Player guesses the incorrect number

Option to play game again -> use while loop or something


*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void PvP() {

	int Player1_Number;
	printf("Player 1 type in a number between 1 and 20: ");
	scanf("%d", &Player1_Number);
	printf("\n");

	
	if (Player1_Number < 1 || Player1_Number > 20) {

		while (Player1_Number < 1 || Player1_Number > 20) {

			printf("Enter a valid number!\n\n");

			int Player1_Number;
			printf("Player 1 type in a number between 1 and 20: ");
			scanf("%d", &Player1_Number);
			printf("\n");

			if (Player1_Number > 0 && Player1_Number < 21) {
				break;
			}
		}
	}

	sleep(2);

	printf("Player 2 has 5 guesses to get the right number.\n\n");
	printf("Begin guessing...\n\n");

	int Player2_GuessesLeft = 5;	
	while (Player2_GuessesLeft > 0) {

		int Player2_Guess;
		printf("Guess: "); 
		scanf("%d", &Player2_Guess);
	    printf("\n");

		if (Player2_Guess == Player1_Number) {
			printf("Correct Guess! You win!\n\n");
			Player2_GuessesLeft = 0;
		} else if (Player2_Guess != Player1_Number) {
			printf("Incorrect Guess! Try again.\n\n");
			Player2_GuessesLeft--;
			sleep(0);
		} else {
			printf("Please enter a number between 1 and 20");

			while(Player2_Guess < 1 || Player2_Guess > 21) {

				int Player2_Guess;
				printf("Guess: "); 
				scanf("%d", &Player2_Guess);
			    printf("\n");

				if (Player2_Guess == Player1_Number) {
					printf("Correct Guess! You win!\n\n");
					Player2_GuessesLeft = 0;
				} else if (Player2_Guess != Player1_Number) {
					printf("Incorrect Guess! Try again.\n\n");
					Player2_GuessesLeft--;
					sleep(1);
				} else {
					printf("Please enter a number between 1 and 20");
				}
			}
		}
	}
}

void PvC() {

	srand(time(0)); 

	printf("Computer is randomly selecting a number...\n\n");
	int randomNumber = rand() % 20;

	printf("Player 2 has 5 guesses to get the right number.\n\n");
	printf("Begin guessing...\n\n");

	int Player2_GuessesLeft = 100;	
	while (Player2_GuessesLeft > 0) {

		int Player2_Guess;
		printf("Guess: "); 
		scanf("%d", &Player2_Guess);
		printf("\n");

		if (Player2_Guess == randomNumber) {
			printf("Correct Guess! You win!\n\n");
			Player2_GuessesLeft = 0;
		} else {
			printf("Incorrect Guess! Try Again\n\n");
			Player2_GuessesLeft--;
		}
	}
}
/*
void CvC(int Computer1Guess) {

	printf("Computer 2 has 5 guesses to get the right number.\n\n");
	printf("Begin guessing\n\n");

	int Computer2_GuessesLeft = 100;	
	while (Computer2_GuessesLeft > 0) {

		srand(1); 

		int Computer2Guess = rand() % 20;

		printf("Computer 2 guess: %d", Computer2Guess);
		printf("\n\n");

		if (Computer2Guess == Computer1Guess) {
			printf("Correct Guess! you win!\n\n");
			Computer2_GuessesLeft = 0;
		} else {
			printf("Incorrect Guess! Try again\n\n");
			Computer2_GuessesLeft--;
		}
	}

}
*/
int main() {

	printf("\n");

	printf("Welcome to Guess the Number!\n\n");

	sleep(1);

	printf("================================================================================================================================================\n\n");

	printf("3 Gamemodes\n\n");

	printf("1) Player vs. Player\n");
	printf("Player 1 will type in a number between 1 and 20,\nPlayer 2 will guess Player 1's number. Player 2 has 5 guesses.\n\n");

	printf("2) Player vs. Computer\n");
	printf("Computer will randomly select a number,\nPlayer will guess the Computer's number.\n\n");

	printf("3) Computer vs. Computer\n");
	printf("Computer 1 will randomly select a number,\nComputer 2 will guess the Computer 1's number.\n\n");

	printf("================================================================================================================================================\n\n");

	sleep(1);

	int gamemode_choice;
	printf("Select a gamemode and type the number --> ");
	scanf("%d", &gamemode_choice);
	printf("\n");

	if (gamemode_choice == 1) {

		PvP();

	} else if (gamemode_choice == 2) {

		PvC();
	/*
	} else if (gamemode_choice == 3) {

		srand(time(NULL)); 

		printf("Computer 1 is randomly selecting a number...\n\n");
		int randomNumber = rand() % 20;

		printf("Computer 1 number: %d", randomNumber);
		printf("\n\n");

		CvC(randomNumber);
	*/
	} else {

		printf("Please enter a valid gamemode!");

	}

	char playAgain;
	printf("Play again? Y / N ");
	scanf("%c", &playAgain);
	printf("\n");

	while(playAgain == 'Y' || playAgain == 'y') {

		printf("Welcome to Guess the Number!\n\n");

		sleep(2);

		printf("================================================================================================================================================\n\n");

		printf("3 Gamemodes\n\n");

		printf("1) Player vs. Player\n");
		printf("Player 1 will type in a number between 1 and 20,\nPlayer 2 will guess Player 1's number. Player 2 has 5 guesses.\n\n");

		printf("2) Player vs. Computer\n");
		printf("Computer will randomly select a number,\nPlayer will guess the Computer's number.\n\n");

		printf("3) Computer vs. Computer\n");
		printf("Computer 1 will randomly select a number,\nComputer 2 will guess the Computer 1's number.\n\n");

		printf("================================================================================================================================================\n\n");

		sleep(2);

		int gamemode_choice;
		printf("Select a gamemode and type the number --> ");
		scanf("%d", &gamemode_choice);
		printf("\n");

		if (gamemode_choice == 1) {

			PvP();

		} else if (gamemode_choice == 2) {

			PvC();
		/*
		} else if (gamemode_choice == 3) {

			srand(time(NULL)); 

			printf("Computer 1 is randomly selecting a number...\n\n");
			int randomNumber = rand() % 20;

			printf("Computer 1 number: %d", randomNumber);
			printf("\n\n");

			CvC(randomNumber);
		*/
		} else {

			printf("Please enter a valid gamemode!");

		}

		char playAgain;
		printf("Play again? Y / N ");
		scanf("%c", &playAgain);
		printf("\n");
	}

	return 0;

}






