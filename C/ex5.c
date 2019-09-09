// Program that finds the largest number of 3 number inputs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int first, second, third, maxNum;
  printf("Enter the first number: ");
  scanf("%d", &first);
  printf("\n");

  printf("Enter the second number: ");
  scanf("%d", &second);
  printf("\n");

  printf("Enter the third number: ");
  scanf("%d", &third);
  printf("\n");

  if (first > second & first > third) {
    maxNum = first;
  } else if (second > first & second > third) {
    maxNum = second;
  } else {
    maxNum = third;
  }

  printf("The maximum number is %d", maxNum);
  printf("\n");

  return 0;
}
