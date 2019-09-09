// Program that gets indices of two numbers of a given array such that
// the sum of the two numbers equal to a specific target number
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int array[] = {4, 2, 1, 5};
  int target = 3;

  int i, j;
  int indexA;
  int indexB;
  for (i = 0; i < sizeof(array); i++) {
    for (j = 1; j < sizeof(array)-i; j++) {
      if (array[i] + array[j] == target) {
        if (i > j) {
          indexA = i;
          indexB = j;
          printf("Indices: %d and %d\n", indexA, indexB);
          exit(0);
        } else {
          indexA = j;
          indexB = i;
          printf("Indices: %d and %d\n", indexB, indexA);
          exit(0);
        }
      }
    }
  }

  return 0;
}
