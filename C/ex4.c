// Program that converts number of days into years, weeks, days
#include <stdio.h>
#include <string.h>

int main() {
  int inputDays;
  printf("Enter number of days: ");
  scanf("%d", &inputDays);
  printf("\n");

  int convertDays = inputDays;
  int years = 0;
  int weeks = 0;
  int remainingDays = 0;
  while (convertDays > 0) {
    if (convertDays >= 365) {
      convertDays -= 365;
      years += 1;
    }
    if (convertDays >= 7) {
      convertDays -= 7;
      weeks += 1;
    }
    if (convertDays < 7) {
      remainingDays = convertDays;
      convertDays = 0;
    }
}

  printf("Years: %d\n", years);
  printf("Weeks: %d\n", weeks);
  printf("Days: %d\n", remainingDays);
  printf("\n");
  return 0;
}
