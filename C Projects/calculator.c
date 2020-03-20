#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Functions that perform mathematical operations 

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
	double resultAvg = (num1 + num2) / 2.0;
	return resultAvg;
}

double absolute(double num1) {
	if (num1 >= 0.0) {
		double resultAbs = num1;
		return resultAbs;
	} else {
		double resultAbs = -(num1);
		return resultAbs;
	}
}

double fToC(double num1) {
	double resultFToC = (((num1 - 32) * 5) / 9);
	return resultFToC;
}

double cToF(double num1) {
	double resultCToF = ((9 * num1) / 5) + 32.0;
	return resultCToF;
}

double tangetOp(double num1) {
	double degToRad = ((3.14159 * num1) / 180);
	double resultTan = tan(degToRad);
	return resultTan; 
}
int main() {

	/* Prompt user with nice greeting */
	printf("\nHello there!\nWelcome to Calculator.exe\n\n");

	/* Prompt user for mathematical operation for the two numbers */
	while (1) {
		char operation;

		printf("List of operations\n\n");
		printf("Multiplication: *\n");
		printf("Division: /\n");
		printf("Addition: +\n");
		printf("Subtraction: -\n");
		printf("Average: v\n");
		printf("Absolute value: a\n");
		printf("Fahrenheit to Celsius: c\n");
		printf("Celsius to Fahrenheit: f\n");
		printf("Tanget: t\n\n");

		printf("Enter an operation: ");
		scanf(" %c", &operation);

		if (operation == '*' || operation == '/' || operation == '+' || operation == '-' || operation == 'v') {

			double num1;
			printf("Enter the first number: ");
			scanf("%lf", &num1);

			double num2;
			printf("Enter the second number: ");
			scanf("%lf", &num2);

			if (operation == '*') {

				printf("Result of (%lf * %lf) : %lf\n\n", num1, num2, multiplication(num1, num2));

			} else if (operation == '/') {

				printf("Result of (%lf / %lf) : %lf\n\n", num1, num2, division(num1, num2));

			} else if (operation == '+') {

				printf("Result of (%lf + %lf) : %lf\n\n", num1, num2, addition(num1, num2));

			} else if (operation == '-') {

				printf("Result of (%lf - %lf) : %lf\n\n", num1, num2, subtraction(num1, num2));

			} else {

				printf("Result of (%lf v %lf) : %lf\n\n", num1, num2, average(num1, num2));

			}

		} else if (operation == 'a' || operation == 'c' || operation == 'f' || operation == 't') {

			double num1;
			printf("Enter a number: ");
			scanf("%lf", &num1);

			if (operation == 'a') {

				printf("Result of |%lf| : %lf\n\n", num1, absolute(num1));

			} else if (operation == 'c') {

				printf("Result of (%lf deg -> C) : %lf\n\n", num1, fToC(num1));

			} else if (operation == 'f') {

				printf("Result of (%lf deg -> C) : %lf\n\n", num1, cToF(num1));

			} else if (operation == 't') {

				printf("Result of tan(%lf): %lf\n\n", num1, tangetOp(num1));

			} 

		} else {

			printf("Invalid operation!\n\n");

		}
	}	
	return 0;
}