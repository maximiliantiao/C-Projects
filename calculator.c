#include <stdio.h>
#include <stdlib.h>

int addition(int num1, int num2) {

	int resultAdd;
	resultAdd = num1 + num2;
	return resultAdd;

}

int subtraction(int num1, int num2) {

	int resultSub;
	resultSub = num1 - num2;
	return resultSub;

}

int multiplication(int num1, int num2) {

	int resultMult;
	resultMult = num1 * num2;
	return resultMult;

}

int division(int num1, int num2) {

	int resultDiv;
	resultDiv = num1 / num2;
	return resultDiv;

}

int main() {

	/* Prompt user for 2 numbers*/
	int num1;
	printf("Enter a number: ");
	scanf("%d", &num1);

	int num2;
	printf("Enter another number: ");
	scanf("%d", &num2);

	/* Prompt user for mathematical operation for the two numbers */
	char operation;
	printf("Enter an operation: ");
	scanf(" %c", &operation);

	/* Based on user's operation, call functions for the operation */
	if (operation == '+') {

		printf("%d + %d = %d\n", num1, num2, addition(num1, num2));

	} else if (operation == '-') {

		printf("%d - %d = %d\n", num1, num2, subtraction(num1, num2));

	} else if (operation == '*') {

		printf("%d * %d = %d\n", num1, num2, multiplication(num1, num2));

	} else if (operation == '/') {

		printf("%d / %d = %d\n", num1, num2, division(num1, num2));

	} else {

		printf("Invalid operation\n");

	}

	return 0;
}