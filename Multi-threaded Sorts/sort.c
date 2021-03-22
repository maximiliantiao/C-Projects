#include <stdio.h>
#include <stdbool.h>

#define SWAP(x, y)                                                             \
  {                                                                            \
    int temp = x;                                                              \
    x = y;                                                                     \
    y = temp;                                                                  \
  }

void selection_sort(int arr[], int length) {
  int start = 0;
  while (start < length - 1) {
    // Find minimum of arr.
    int min_index = start;
    for (int i = start; i < length; i++) {
      if (arr[i] < arr[min_index]) {
        min_index = i;
      }
    }
    SWAP(arr[min_index], arr[start]);
    start++;
  }
}

void bubble_sort(int arr[], int length) {
  int swapped = false;
  do {
    swapped = false;
    for (int i = 1; i < length; i++) {
      if (arr[i-1] > arr[i]) {
        SWAP(arr[i-1], arr[i]);
        swapped = true;
      }
    }
  } while (swapped);
}

int main(void) {
  return 0;
}