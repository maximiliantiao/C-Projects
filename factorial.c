#include <stdio.h>
#include <stdlib.h>

int main() {

	int number;
	printf("Type in an integer: ");
	scanf("%d", &number);
	printf("\n\n");

	int i;
	int factorial = 1;
	for (i = number; i > 0; i--) {

		factorial *= i;

	}

	printf("%d! = %d", number, factorial);
	printf("\n\n");

	return 0;
}