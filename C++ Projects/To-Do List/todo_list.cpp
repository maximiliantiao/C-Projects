#include <iostream>
#include <string>
#include "todo.hpp"
#include <vector>

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
  int task_number;
  std::string task;
  int priority;
  std::string date;
  int index = 0;
  ListItem *add_task;
  int del_index;

  ListItem *task_array[100];
  while (true) {
    std::cout << "***** TO DO List *****\n\n";

    int choice;
    std::cout << "Select a choice: \n";
    std::cout << "1. Add a task to list\n";
    std::cout << "2. Delete task from list\n";
    std::cout << "3. Update task from list\n";
    std::cout << "4. Print list\n";
    std::cout << "5. Exit\n";
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "***** Add a task *****\n\n";
        std::cout << "Enter task: ";
        std::cin.ignore();
        getline(std::cin, task);
        std::cout << "Enter a priority (1 being lowest, 10 being highest: ";
        std::cin >> priority;
        std::cout << "Enter date (MM/DD/YYYY): ";
        std::cin.ignore();
        getline(std::cin, date);
        add_task = new_item(task, priority, date);
        task_array[index] = add_task;
        index += 1;
        break;
      case 2:
        std::cout << "Enter task number: ";
        std::cin >> task_number;
        del_index = deleted_item(task_array, task_number, index);
        if (del_index) {
          for (int i = del_index; i < 99; i++) {
            task_array[i] = task_array[i+1];
            task_array[i]->task_no -= 1;
          }
        }
        index -= 1;
        break;
      case 3:
        break;
      case 4:
        if (index == 0) {
          std::cout << "No Tasks\n";
          break;
        }
        for (int i = 0; i < index; i++) {
          print_item(task_array[i]);
        }
        break;
      case 5:
        for (int i = 0; i < index; i++) {
          destroy_task(task_array[i]);
        }
        std::cout << "***** Goodbye *****";
        return 0;
      default:
        break;
    }
  }
}
