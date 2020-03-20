
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
	int k;
	int numberOfXsInDiaA = 0;
	int numberOfOsInDiaA = 0;
	int l = 0;
	for (k = 0; k < 3; k++) {
	  if (ticTacToe[k][l] == 'O') {
	    numberOfOsInDiaA++;
			l++;
	  }
		if (ticTacToe[k][l] == 'X')  {
	     numberOfXsInDiaA++;
			l++;
	  }
	}

	if (numberOfOsInDiaA == 3) {
	  return 1;
	} else if (numberOfXsInDiaA == 3) {
	  return 2;
	} else {
	  return 0;
	}
}

int matchesDiagonalB(char ticTacToe[3][3]) {
	// Check for any matches on diagonal from bottom left to top right
	int m;
	int numberOfXsInDiaB = 0;
	int numberOfOsInDiaB = 0;
	int n = 2;
	for (m = 0; m < 3; m++) {
		if (ticTacToe[m][n] == 'O') {
			numberOfOsInDiaB++;
			n--;
		}
		if (ticTacToe[m][n] == 'X')  {
			 numberOfXsInDiaB++;
			n--;
		}
	}

	if (numberOfOsInDiaB == 3) {
		return 1;
	} else if (numberOfXsInDiaB == 3) {
		return 2;
	} else {
		return 0;
	}
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
	if (gameMode == 1) {
		int row, column;
		int counter = 1;

		// Display 3 x 3 Grid
		while(counter <= 9) {

			int matchTop = matchesTopRow(ticTacToe);
			int matchMid = matchesMidRow(ticTacToe);
			int matchBottom = matchesBottomRow(ticTacToe);
			int matchFirstCol = matchesFirstCol(ticTacToe);
			int matchSecondCol = matchesSecondCol(ticTacToe);
			int matchThirdCol = matchesThirdCol(ticTacToe);
			int matchDiaA = matchesDiagonalA(ticTacToe);
			int matchDiaB = matchesDiagonalB(ticTacToe);

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

			if (matchTop == 1 || matchMid == 1 || matchBottom == 1 || matchFirstCol == 1 || matchSecondCol == 1 || matchThirdCol == 1 || matchDiaA == 1 || matchDiaB == 1) {
				printf("Player 1 Wins!\n");
				exit(0);
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

			if (matchTop == 2 || matchMid == 2 || matchBottom == 2 || matchFirstCol == 2 || matchSecondCol == 2 || matchThirdCol == 2 || matchDiaA == 2 || matchDiaB == 2) {
				printf("Plauer 2 Wins!\n");
				exit(0);
			}

			counter++;

			if (matchTop == 0 || matchMid == 0 || matchBottom == 0 || matchFirstCol == 0 || matchSecondCol == 0 || matchThirdCol == 0 || matchDiaA == 0 || matchDiaB == 0) {
				if (counter == 9) {
					printf("No One Wins!");
					exit(0);
				}
			}
		}
	} else {
			printf("Invalid game mode");
	}

	return 0;
}
