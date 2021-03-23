#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#include <assert.h>

typedef struct args {
  int *arr;
  int start;
  int end;
} args_t;

#define SWAP(x, y) {int temp = x; x = y;y = temp;}

bool is_sorted(int *arr, int start, int end) {
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] < arr[i-1]) {
      return false;
    }
  }
  return true;
}

void *selection_sort(void *param) {
  args_t *args = (args_t *) param;
  int *arr = (int *) args->arr;
  int start = (int) args->start;
  int end = (int) args->end;

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
  pthread_exit(NULL);
}

void *bubble_sort(void *param) {
  args_t *args = (args_t *) param;
  int *arr = (int *) args->arr;
  int start = (int) args->start;
  int end = (int) args->end;

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
  pthread_exit(NULL);
}

void *insertion_sort(void *param) {
  args_t *args = (args_t *) param;
  int *arr = (int *) args->arr;
  int start = (int) args->start;
  int end = (int) args->end;

  for (int i = start + 1; i <= end; i++) {
    int current = i;
    while (current > start && arr[current - 1] > arr[current]) {
      SWAP(arr[current - 1], arr[current]);
      current--;
    }
  }
  pthread_exit(NULL);
}

void merge(int *arr, int start, int middle, int end) {
  int copy[end + 1];
  for (int i = 0; i <= end; i++) {
    copy[i] = arr[i];
  }
  int first = start;
  int second = middle + 1;
  int index = 0;
  while (first <= middle && second <= end) {
    if (copy[first] <= copy[second]) {
      arr[index] = copy[first];
      first++;
    } else {
      arr[index] = copy[second];
      second++;
    }
    index++;
  }
  while (first <= middle) {
    arr[index] = copy[first];
    first++;
    index++;
  }
  while (second <= end) {
    arr[index] = copy[second];
    second++;
    index++;
  }
}

int main(void) {
  clock_t begin, end;
  srand(time(0));
  pthread_t pt[3];
  int length = (rand() % 20) + 1;
  int middle = length / 2;
  int *input = (int *) calloc(length, sizeof(int));
  for (int i = 0; i < length; i++) {
    input[i] = rand() % 50;
  }

  args_t to_pass_a;
  to_pass_a.arr = input;
  to_pass_a.start = 0;
  to_pass_a.end = middle;

  args_t to_pass_b;
  to_pass_b.arr = input;
  to_pass_b.start = middle + 1;
  to_pass_b.end = length - 1;  

  begin = clock();

  pthread_create(&pt[0], NULL, insertion_sort, (void *) &to_pass_a);
  pthread_create(&pt[1], NULL, insertion_sort, (void *) &to_pass_b);

  pthread_join(pt[0], NULL);
  pthread_join(pt[1], NULL);

  // assert(is_sorted(to_pass_a.arr, to_pass_a.start, to_pass_a.end) == true);
  // assert(is_sorted(to_pass_b.arr, to_pass_b.start, to_pass_b.end) == true);

  for (int i = middle + 1; i < length; i++) {
    to_pass_a.arr[i] = to_pass_b.arr[i];
  }
  to_pass_a.start = 0;
  to_pass_a.end = length - 1;

  merge(to_pass_a.arr, 0, middle, length - 1);

  end = clock();

  // assert(is_sorted(to_pass_a.arr, to_pass_a.start, to_pass_a.end) == true);

  for (int i = 0; i < length; i++) {
    printf("%d ", to_pass_a.arr[i]);
  }
  printf("\n");

  printf("Duration: %ld clock ticks\n", end - begin);

  free(input);

  return 0;
}
