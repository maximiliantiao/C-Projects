
#include <stdio.h>
#include <stdlib.h>

int matchesTopRow(char ticTacToe[3][3]) {
	// Check for any matches on the top row
	int e;
	int numberOfXsInTopRow = 0;
	int numberOfOsInTopRow = 0;
	for (e = 0; e < 3; e++) {
	  if (ticTacToe[0][e] == 'O') {
	    numberOfOsInTopRow++;
	  }
		if (ticTacToe[0][e] == 'X') {
	    numberOfXsInTopRow++;
	  }
	}

	if (numberOfOsInTopRow == 3) {
	  return 1;
	} else if (numberOfXsInTopRow == 3) {
	  return 2;
	} else {
	  return 0;
	}
}

int matchesMidRow(char ticTacToe[3][3]) {
	// Check for any matches on the top row
	int f;
	int numberOfXsInMiddleRow = 0;
	int numberOfOsInMiddleRow = 0;
	for (f = 0; f < 3; f++) {
	  if (ticTacToe[1][f] == 'O') {
	    numberOfOsInMiddleRow++;
	  }
		if (ticTacToe[1][f] == 'X') {
	    numberOfXsInMiddleRow++;
	  }
	}

	if (numberOfOsInMiddleRow == 3) {
	  return 1;
	} else if (numberOfXsInMiddleRow == 3) {
	  return 2;
	} else {
	  return 0;
	}
}

int matchesBottomRow(char ticTacToe[3][3]) {
	// Checks for any matches on the bottom row
	int g;
	int numberOfXsInBottomRow = 0;
	int numberOfOsInBottomRow = 0;
	for (g = 0; g < 3; g++) {
	  if (ticTacToe[2][g] == 'O') {
	    numberOfOsInBottomRow++;
	  }
	 	if (ticTacToe[2][g] == 'X') {
	    numberOfXsInBottomRow++;
	  }
	}

	if (numberOfOsInBottomRow == 3) {
	  return 1;
	} else if (numberOfXsInBottomRow == 3) {
	  return 2;
	} else {
	  return 0;
	}
}

int matchesFirstCol(char ticTacToe[3][3]) {
	// Checks for any matches on the first column
	int h;
	int numberOfXsInFirstColumn = 0;
	int numberOfOsInFirstColumn = 0;
	for (h = 0; h < 3; h++) {
	  if (ticTacToe[h][0] == 'O') {
	    numberOfOsInFirstColumn++;
	  }
		if (ticTacToe[h][0] == 'X') {
	    numberOfXsInFirstColumn++;
	  }
	}

	if (numberOfOsInFirstColumn == 3) {
	  return 1;
	} else if (numberOfXsInFirstColumn == 3) {
	  return 2;
	} else {
	  return 0;
	}
}

int matchesSecondCol(char ticTacToe[3][3]) {
	// Checks for any matches on the second column
	int i;
	int numberOfOsInSecondColumn = 0;
	int numberOfXsInSecondColumn = 0;
	for (i = 0; i < 3; i++) {
	  if (ticTacToe[i][1] == 'O') {
	    numberOfOsInSecondColumn++;
	  }
		if (ticTacToe[i][1] == 'X') {
	    numberOfXsInSecondColumn++;
	  }
	}

	if (numberOfOsInSecondColumn == 3) {
	  return 1;
	} else if (numberOfXsInSecondColumn == 3){
	  return 2;
	} else {
	  return 0;
	}
}

int matchesThirdCol(char ticTacToe[3][3]) {
	// Checks for any matches on the third column
	int j;
	int numberOfXsInThirdColumn = 0;
	int numberOfOsInThirdColumn = 0;
	for (j = 0; j < 3; j++) {
	  if (ticTacToe[j][2] == 'O') {
	    numberOfOsInThirdColumn++;
	  }
		if (ticTacToe[j][2] == 'X')  {
	    numberOfXsInThirdColumn++;
	  }
	}

	if (numberOfOsInThirdColumn == 3) {
	  return 1;
	} else if (numberOfXsInThirdColumn == 3) {
	  return 2;
	} else {
	  return 0;
	}
}

int matchesDiagonalA(char ticTacToe[3][3]) {
	// Check for any matches on diagonal from top left to botton right
}

int matchesDiagonalB(char ticTacToe[3][3]) {
	// Check for any matches on diagonal from bottom left to top right
}


int main() {

	// 3 x 3 Grid Setup
	char ticTacToe[3][3] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
	char space = ' ';

	// Welcome screen + Menu options
	printf("Welcome to Tic-Tac-Toe!\n\n");

	int gameMode;

	printf("Which game mode would you like to play? (Enter a number)\n\n");
	printf("1. Player vs. Player\n");
	printf("2. Player vs. Computer (Coming Soon)\n");
	printf("3. Computer vs. Computer (Coming Soon)\n");

	scanf("\n\n%d", &gameMode);

	// Gamemode 1
	if (gameMode == 1) {/*
		int row, column;
		int counter = 0;

		// Display 3 x 3 Grid
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

			// Player 1's Turn
			printf("-----------\n\n");
			printf("Player 1's Turn\n\n");
			printf("Enter a row number (0, 1, 2): ");
			scanf("%d", &row);

			printf("Enter a column number (0, 1, 2): ");
			scanf("%d", &column);
			printf("\n\n");

			if (ticTacToe[row][column] == '*') {
				ticTacToe[row][column] = 'O';

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
				printf("Invalid row and/or column number!");
			}

			// Player 2's Turn
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
	*/
		//int matchTop = matchesTopRow(ticTacToe);
		//int matchMid = matchesMidRow(ticTacToe);
		//int matchBottom = matchesBottomRow(ticTacToe);
		//int matchFirstCol = matchesFirstCol(ticTacToe);
		//int matchSecondCol = matchesSecondCol(ticTacToe);
		//int matchThirdCol = matchesThirdCol(ticTacToe);

 		printf("%d", matchThirdCol);
	} else {
		printf("Invalid game mode");
	}



	return 0;
}
