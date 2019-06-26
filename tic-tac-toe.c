
#include <stdio.h>
#include <stdlib.h>

int main() {


	char ticTacToe[3][3] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
	char space = ' ';

	printf("Welcome to Tic-Tac-Toe!\n\n");

	int gameMode;

	printf("Which game mode would you like to play? (Enter a number)\n\n");
	printf("1. Player vs. Player\n");
	printf("2. Player vs. Computer (Coming Soon)\n");
	printf("3. Computer vs. Computer (Coming Soon)\n");

	scanf("\n\n%d", &gameMode);

	if (gameMode == 1) {

		int row, column;
		int counter = 0;

		while(counter <= 9) {

			printf("-----------\n");

			int i, j;
			for (i = 0; i < 3; i++) {
				printf("|");
				for (j = 0; j < 3; j++) {
					printf("%c", space);
					printf("%c", ticTacToe[i][j]);
					printf("%c", space);
				}
				printf("|");
				printf("\n");
			}

			printf("-----------\n\n");

			printf("Player 1's Turn\n\n");

			printf("Enter a row number (0, 1, 2): ");
			scanf("%d", &row);

			printf("Enter a column number (0, 1, 2): ");
			scanf("%d", &column);
			printf("\n\n");

			if (ticTacToe[row][column] == '*') {

				ticTacToe[row][column] = '0';

			} else if (ticTacToe[row][column] == 'X') {

				printf("This has already been chosen!");

				while (1) {

					if (ticTacToe[row][column] == 'X') { 
						printf("Enter a row number (0, 1, 2): ");
						scanf("%d", &row);

						printf("Enter a column number (0, 1, 2): ");
						scanf("%d", &column);
						printf("\n\n");

					} else {
						break;
					}
				}

			
			} else if (ticTacToe[row][column] == 'O') {

				printf("This has already been chosen!");

				while (1) {

					if (ticTacToe[row][column] == '0') { 
						printf("Enter a row number (0, 1, 2): ");
						scanf("%d", &row);

						printf("Enter a column number (0, 1, 2): ");
						scanf("%d", &column);
						printf("\n\n");

					} else {
						break;
					}
				}

			} else {

				printf("Invalid row and/or column number!");
				
			}

			printf("-----------\n");

			int k, l;
			for (k = 0; k < 3; k++) {
				printf("|");
				for (l = 0; l < 3; l++) {
					printf("%c", space);
					printf("%c", ticTacToe[k][l]);
					printf("%c", space);
				}
				printf("|");
				printf("\n");
			}

			printf("-----------\n\n");

			printf("Player 2's Turn\n\n");

			printf("Enter a row number (0, 1, 2): ");
			scanf("%d", &row);

			printf("Enter a column number (0, 1, 2): ");
			scanf("\n%d", &column);
			printf("\n\n");


			if (ticTacToe[row][column] == '*') {

				ticTacToe[row][column] = 'X';

			} else if (ticTacToe[row][column] == 'X') {

				printf("This has already been chosen!");

				while (1) {

					if (ticTacToe[row][column] == 'X') { 
						printf("Enter a row number (0, 1, 2): ");
						scanf("%d", &row);

						printf("Enter a column number (0, 1, 2): ");
						scanf("%d", &column);
						printf("\n\n");

					} else {
						break;
					}
				}
			
			} else if (ticTacToe[row][column] == 'O') {

				printf("This has already been chosen!");

				while (1) {

					if (ticTacToe[row][column] == 'O') { 
						printf("Enter a row number (0, 1, 2): ");
						scanf("%d", &row);

						printf("Enter a column number (0, 1, 2): ");
						scanf("%d", &column);
						printf("\n\n");

					} else {
						break;
					}
				}

			} else {

				printf("Invalid row and/or column number!\n\n");
				
			}

			counter++;

		}


	} else if (gameMode == 2) {

		printf("Coming Soon");

	} else if (gameMode == 3) {

		printf("Coming Soon");

	} else {
		printf("Invalid game mode");
	}



	return 0;
}