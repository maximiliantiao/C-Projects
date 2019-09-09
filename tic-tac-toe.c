
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

			int a, b;
			for (a = 0; a < 3; a++) {
				printf("|");
				for (b = 0; b < 3; b++) {
					printf("%c", space);
					printf("%c", ticTacToe[a][b]);
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

				printf("This has already been chosen!\n\n");

				while (ticTacToe[row][column] == 'X') {

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

				printf("This has already been chosen!\n\n");

				while (ticTacToe[row][column] == 'O') {

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

			int c, d;
			for (c = 0; c < 3; c++) {
				printf("|");
				for (d = 0; d < 3; d++) {
					printf("%c", space);
					printf("%c", ticTacToe[c][d]);
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

				while (ticTacToe[row][column] == 'X') {

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

				while (ticTacToe[row][column] == 'O') {

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

		int e;
		int numberOfXsInTopRow;
		int numberOfOsInTopRow;
		for (e = 0; e < 3; e++) {
			if (ticTacToe[0][e] == 'O') {
				numberOfOsInTopRow++;
			} else {
				numberOfXsInTopRow++;
			}
		}

		if (numberOfOsInTopRow == 3) {
			printf("Player 1 wins!");
		} else if (numberOfXsInTopRow == 3) {
			printf("Player 2 wins!");
		} else {
			printf("No matches in the top row!");
		}

		int f;
		int numberOfXsInMiddleRow;
		int numberOfOsInMiddleRow;
		for (f = 0; f < 3; f++) {
			if (ticTacToe[1][f] == 'O') {
				numberOfOsInMiddleRow++;
			} else {
				numberOfXsInMiddleRow++;
			}
		}

		if (numberOfOsInMiddleRow == 3) {
			printf("Player 1 wins!");
		} else if (numberOfXsInMiddleRow == 3) {
			printf("Player 2 wins!");
		} else {
			printf("No matches in the middle row!");
		}

		int g;
		int numberOfXsInBottomRow;
		int numberOfOsInBottomRow;
		for (g = 0; g < 3; g++) {
			if (ticTacToe[2][g] == 'O') {
				numberOfOsInBottomRow++;
			} else {
				numberOfXsInBottomRow++;
			}
		}

		if (numberOfOsInBottomRow == 3) {
			printf("Player 1 wins!");
		} else if (numberOfXsInBottomRow == 3) {
			printf("Player 2 wins!");
		} else {
			printf("No matches in the bottom row!");
		}

		int h;
		int numberOfXsInFirstColumn;
		int numberOfOsInFirstColumn;
		for (h = 0; h < 3; h++) {
			if (ticTacToe[h][0]) {
				numberOfOsInFirstColumn++;
			} else {
				numberOfXsInFirstColumn++;
			}
		}

		if (numberOfOsInFirstColumn == 3) {
			printf("Player 1 wins!");
		} else if (numberOfXsInFirstColumn == 3) {
			printf("Player 2 wins!");
		} else {
			printf("No matches in the first column!");
		}

		int i;
		int numberOfOsInSecondColumn;
		int numberOfXsInSecondColumn;
		for (i = 0; i < 3; i++) {
			if (ticTacToe[i][1]) {
				numberOfOsInSecondColumn++;
			} else {
				numberOfXsInSecondColumn++;
			}
		}

		if (numberOfOsInSecondColumn == 3) {
			printf("Player 1 wins!");
		} else if (numberOfXsInSecondColumn == 3){
			printf("Player 2 wins!");
		} else {
			printf("No matches in the second column!");
		}

		int j;
		int numberOfXsInThirdColumn;
		int numberOfOsInThirdColumn;
		for (j = 0; j < 3; j++) {
			if (ticTacToe[j][2]) {
				numberOfOsInThirdColumn++;
			} else {
				numberOfXsInThirdColumn++;
			}
		}

		if (numberOfOsInThirdColumn == 3) {
			printf("Player 1 wins!");
		} else if (numberOfXsInThirdColumn == 3) {
			printf("Player 2 wins!");
		} else {
			printf("No matches in third column!");
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
