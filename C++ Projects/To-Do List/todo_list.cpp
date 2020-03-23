#include <iostream>
#include <string.h>
#include "todo.h"

/*

TO_DO List Program

array_of_structs = [to_do_item, to_do_item...];

print out to_do list in the following ways:
1. By Priority Number
2. Alphabetical based on item
3. No Order
4. Simple View / Detailed View

Future features:
1. Create several to_do lists
2. More member definitions in to_do_item struct
*/


int main (void) {

  std::string str_task = "Call Dad";
  int priority = 5;
  std::string date = "03/23/2020";
  ListItem *task = new_item(str_task, priority, date);
  print_item(task);
  delete_item(task);

  return 0;
}
