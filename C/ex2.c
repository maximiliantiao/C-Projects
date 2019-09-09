// Program that prints a word backwards
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *string;
  printf("Enter a WORD: ");
  scanf("%s", string);
  printf("\n");

  int i;
  printf("The word backwards: ");
  for (i = strlen(string); i >= 0; i--) {
    printf("%c", string[i]);
  }
  printf("\n");
  return 0;

}
