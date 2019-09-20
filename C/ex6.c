// Program that calculates Euclidean distance of two points given x1, x2, y1, y2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  int x1, y1, x2, y2;
  printf("Enter x1: ");
  scanf("%d", &x1);
  printf("\n");

  printf("Enter y1: ");
  scanf("%d", &y1);
  printf("\n");

  printf("Enter x2: ");
  scanf("%d", &x2);
  printf("\n");

  printf("Enter y2: ");
  scanf("%d", &y2);
  printf("\n");

  double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

  printf("Distance between the said points: %lf\n", distance);

  return 0;
}