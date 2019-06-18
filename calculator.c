#include <stdio.h>
#include <stdlib.h>

double multiplication(double num1, double num2) {
	double resultMult = num1 * num2;
	return resultMult;
}

double division(double num1, double num2) {
	double resultDiv = num1 / num2;
	return resultDiv;
}

double addition(double num1, double num2) {
	double resultAdd = num1 + num2;
	return resultAdd;
}

double subtraction(double num1, double num2) {
	double resultSub = num1 - num2;
	return resultSub;
}

double average(double num1, double num2) {
	double resultAvg = (num1 + num2) / 2;
	return resultAvg;
}

double absolute(double num1) {
	double resultAbs = abs(num1);
	return resultAbs;
}

double cToF(double num1) {
	double resultCToF = ((9/5) * num1) + 32;
	return resultCToFl
}

double fToC(double num1) {
	double resultFToC = (32 - num1) * (5/9);
	return resultFToC;
}

double tanget(int)

int main() {

	/* Prompt user with nice greeting */
	printf("\nHello there!\nWelcome to Calculator.exe\n\n");

	/* Prompt user for mathematical operation for the two numbers */
	char operation;

	printf("List of operations\n\n");
	printf("Multiplication: *\n");
	printf("Division: /\n");
	printf("Addition: +\n");
	printf("Subtraction: -\n");
	printf("Average: v\n");
	printf("Absolute value: a\n");
	printf("Celsius to Fahrenheit: c\n");
	printf("Fahrenheit to Celsius: f\n");
	printf("Tanget: t\n\n");

	printf("Enter an operation: ");
	scanf(" %c", &operation);

	/* Prompt user for 2 numbers*/
	double num1;
	printf("Enter the first number: ");
	scanf("%d", &num1);

	double num2;
	printf("Enter the second number: ");
	scanf("%d", &num2);

	/* Display result header */
	printf("\nResult\n\n");

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