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

void PvP() {

	int Player1_Number;
	printf("Player 1 type in a number between 1 and 20: ");
	scanf("%d", &Player1_Number);
	printf("\n\n");

	printf("Player 2 has 5 guesses to get the right number.\n\n");
	printf("Begin guessing...\n\n");

	int Player2_GuessesLeft = 5;	
	while (Player2_GuessesLeft == 0) {

		int Player2_Guess;
		printf("Guess: "); 
		scanf("%d", &Player2_Guess);
		print("\n\n");

		if (Player2_Guess == Player1_Number) {
			printf("Correct Guess")
			Player2_GuessesLeft = 0;
		} else {
			printf("Incorrect Guess\n");
			printf("Try Again");
			Player2_GuessesLeft--;
		}
	}
}

void PvC() {

	printf("Computer is randomly selecting a number...\n\n");
	int randomNumber = rand() % 20;

	printf("Player 2 has 5 guesses to get the right number.\n\n");
	printf("Begin guessing...\n\n");

	int Player2_GuessesLeft = 5;	
	while (Player2_GuessesLeft == 0) {

		int Player2_Guess;
		printf("Guess: "); 
		scanf("%d", &Player2_Guess);
		print("\n\n");

		if (Player2_Guess == randomNumber) {
			printf("Correct Guess")
			Player2_GuessesLeft = 0;
		} else {
			printf("Incorrect Guess\n");
			printf("Try Again");
			Player2_GuessesLeft--;
		}
	}
}

void CvC() {

	printf("Computer 1 is randomly selecting a number...\n\n");
	int randomNumber = rand() % 20;

	printf("Computer 2 has 5 guesses to get the right number.\n\n");
	printf("Begin guessing");

	int Computer2_GuessesLeft = 5;	
	while (Computer2_GuessesLeft == 0) {

		int Computer2Guess = rand() % 20;

		if (Computer2_Guess == randomNumber) {
			printf("Correct Guess")
			Computer2_GuessesLeft = 0;
		} else {
			printf("Incorrect Guess\n");
			printf("Try Again");
			Computer2_GuessesLeft--;
		}
	}

}

int main() {

	printf("Welcome to Guess the Number!\n\n");

	printf("3 Gamemodes\n\n");

	printf("1) Player vs. Player\n");
	printf("Player 1 will type in a number between 1 and 20,\nPlayer 2 will guess Player 1's number.
	Player 2 has 5 guesses.\n\n");

	printf("2) Player vs. Computer\n\n");
	printf("Computer will randomly select a number,\nPlayer will guess the Computer's number.\n\n");

	printf("3) Computer vs. Computer\n\n");
	printf("Computer 1 will randomly select a number,\nComputer 2 will guess the Computer 1's number.\n\n");

	int gamemode_choice;
	printf("Select a gamemode and type the number --> ");
	scanf("%d", &gamemode_choice);

	if (gamemode_choice == 1) {
		PvP();
	} else if (gamemode_choice == 2) {
		PvC();
	} else if (gamemode_choice == 3) {
		CvC();
	} else {
		printf("Please enter a valid gamemode!");
	}



	return 0;
}






