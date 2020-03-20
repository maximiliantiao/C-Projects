#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	printf("Welcome to Hangman!\n\n");

	printf("INSTRUCTIONS\n");
	printf("Select a player to be the host and think of a secret word.\n");
	printf("Select a player to be the guesser.\n");
	printf("If there are 2 or more players, the rest can only spectate.\n\n");


	printf("Rules for Guesser:\n\n");
	printf("Guess the secret word or its letters. You only have 10 chances.\n");
	printf("Indicate your guesses as 'letters' or 'word'.\n\n");

	printf("Rules for Host:\n\n");
	printf("Think of a secret word and type it into console.\n");
    printf("Makes sure no one but the host sees the secret word.\n");
	printf("DO NOT give guesser hints. No mercy :D\n\n");

	char secretWord[45]; 
	printf("Enter secret word: ");
	scanf("%s", secretWord);
	printf("\n");

	int a;
	for (a = 0; a < 10000; a++) {

		printf("===================================================================================\n");

	}

	printf("\n");

	printf("You may begin guessing.\n\n");

	int lives = 10;

	int b;
		for (b = 0; b < strlen(secretWord); b++) {

			printf("_ ");

		}
	
	while(lives >= 0) {

		printf("You have %d lives\n\n" , lives);

		char guessType[6];
		printf("Guess Letter / Word: ");
		scanf("%s", guessType);
		printf("\n\n");


		char guessLetter;
		char guessWord[45];
		if (guessType == "Letter") {

			printf("Guess Letter: ");
			scan("%c", &guessLetter);
			printf("\n\n");

			int c;
			for (b = 0; b < strlen(secretWord); b++) {
				if (guessLetter == secretWord[b]) {

					printf("Correct letter guess!");

				} else {

					printf("Incorrect letter guess!");
					printf("You lost one of your lives.");
					lives--;

				}
			}

		} else {

			printf("Guess Word: ");
			scan("%s", guessWord);
			printf("\n\n");

			if (guessWord == secretWord) {

				printf("Correct word guess!");

			} else {

				printf("Incorrect word guess!");
				printf("You lost one of your lives.");
				lives--;

			}

		}

	}
	
	return 0;
}