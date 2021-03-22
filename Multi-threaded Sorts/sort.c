#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#define SWAP(x, y) {int temp = x; x = y;y = temp;}

int* selection_sort(int *arr, int start, int end) {
  int index = start;
  while (index < end) {
    // Find minimum of arr.
    int min_index = index;
    for (int i = index; i <= end; i++) {
      if (arr[i] < arr[min_index]) {
        min_index = i;
      }
    }
    SWAP(arr[min_index], arr[index]);
    index++;
  }
  return arr;
}

int *bubble_sort(int *arr, int start, int end) {
  int swapped = false;
  do {
    swapped = false;
    for (int i = start + 1; i <= end; i++) {
      if (arr[i-1] > arr[i]) {
        SWAP(arr[i-1], arr[i]);
        swapped = true;
      }
    }
  } while (swapped);
  return arr;
}

int main(void) {
  srand(time(0));
  int length = rand() % 20;
  int *input = (int *) calloc(length, sizeof(int));
  for (int i = 0; i < length; i++) {
    input[i] = rand() % 50;
  }

  int *sorted = selection_sort(input, 0, length);

  for (int i = 0; i < length; i++) {
    printf("%d ", sorted[i]);
  }
  printf("\n");

  free(input);

  return 0;
}
