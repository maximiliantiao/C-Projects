#include <iostream>
#include <string>
#include "todo.hpp"
#include <vector>

/*
TO_DO List Program

print out to_do list in the following ways:
1. By Priority Number
2. Alphabetical based on item

Future features:
1. More member definitions in to_do_item struct
*/

int main (void) {
  int task_number;
  std::string task;
  int priority;
  std::string date;

  int index = 0;
  ListItem *add_task;
  int del_index;
  bool avail_choice = true;

  ListItem *task_array[100];
  while (true) {
    std::cout << "\n\n***** TO DO List *****\n\n\n";

    int choice;
    std::cout << "Select a choice: \n";
    std::cout << "1. Add a task to list\n";
    std::cout << "2. Delete task from list\n";
    std::cout << "3. Update task from list\n";
    std::cout << "4. Print list\n";
    std::cout << "5. Exit\n\n";
    std::cout << "Enter here: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "\n\n***** Add a task *****\n\n\n";
        std::cout << "Enter task: ";
        std::cin.ignore();
        getline(std::cin, task);
        std::cout << "Enter a priority (1 being lowest, 10 being highest: ";
        std::cin >> priority;
        std::cout << "Enter date (MM/DD/YYYY): ";
        std::cin.ignore();
        getline(std::cin, date);
        add_task = new_item(task, priority, date, index);
        task_array[index] = add_task;
        index += 1;
        break;
      case 2:
        std::cout << "\n\n***** Delete a task *****\n\n\n";
        if (index == 0) {
          std::cout << "Error: Cannot delete task if no tasks exists!\n";
          break;
        }
        std::cout << "Enter task number: ";
        std::cin >> task_number;
        del_index = deleted_item(task_array, task_number, index);
        std::cout << del_index;
        if (del_index != -1) {
          if (index == 1) {
            destroy_task(task_array[del_index]);
          } else {
            for (int i = del_index; i < index-1; i++) {
              destroy_task(task_array[i]);
              task_array[i] = task_array[i+1];
              task_array[i]->task_no -= 1;
            }
          }
          index -= 1;
        }
        break;
      case 3:
        std::cout << "\n\n***** Update a task *****\n\n\n";
        if (index == 0) {
          std::cout << "Error: Cannot update task if no tasks exists!\n";
          break;
        }
        std::cout << "Enter task number: ";
        std::cin >> task_number;
        std::cout << "\n";
        update_item(task_array, task_number, index);
        break;
      case 4:
        std::cout << "\n\n***** Print out tasks *****\n\n\n";
        if (index == 0) {
          std::cout << "No Tasks\n";
          break;
        }
        avail_choice = true;
        int print_choice;
        std::cout << "Print in: \n";
        std::cout << "1. Simple View\n";
        std::cout << "2. Detailed View\n";
        std::cin >> print_choice;

        std::cout << "\n";
        while (avail_choice) {
          if (print_choice == 1) {
            for (int i = 0; i < index; i++) {
              print_simple(task_array[i]);
            }
            avail_choice = false;
          } else if (print_choice == 2) {
            for (int i = 0; i < index; i++) {
              print_details(task_array[i]);
            }
            avail_choice = false;
          } else {
            std::cout << "Error: Choice unavailable\n";
          }
        }
        break;
      case 5:
        if (index != 0) {
          for (int i = 0; i < index; i++) {
            destroy_task(task_array[i]);
          }
        }
        std::cout << "\n\n***** Goodbye *****\n\n";
        return 0;
      default:
        break;
    }
  }
}
