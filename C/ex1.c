// Programs that returns my name, DOB, and phone number
#include <stdio.h>
#include <stdlib.h>

int main() {

  char name[100] = "First Last";
  char dobMonth[100] = "Month";
  int dobDay = 0;
  int dobYear = 0000;
  int areaCode = 415;
  int phoneNumA = 123;
  int phoneNumB = 4567;

  printf("Name   : %s\n", name);
  printf("DOB    : %s %d, %d\n", dobMonth, dobDay, dobYear);
  printf("Mobile : %d-%d-%d\n", areaCode, phoneNumA, phoneNumB);

  return 0;
}
