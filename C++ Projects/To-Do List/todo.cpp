#include <iostream>
#include <string>
#include "todo.hpp"
#include <vector>

ListItem *new_item(std::string task, int priority, std::string date, int index) {
  ListItem *todo_item = (ListItem *)malloc(sizeof(ListItem));
  if (todo_item != NULL) {
    todo_item->task_no = index;
    todo_item->task = task;
    todo_item->priority = priority;
    todo_item->date = date;
    return todo_item;
  }
  return NULL;
}

int deleted_item(ListItem **array, int task_number, int size) {
  if (size == 0) {
    return 0;
  }
  for (int i = 0; i < size; i++) {
    if (array[i]->task_no == task_number) {
      return i;
    }
  }
  return -1;
}

void destroy_task(ListItem *item) {
  free(item);
  item = NULL;
  return;
}

void update_item(ListItem **array, int task_number, int size) {
  ListItem *to_update;
  for (int i = 0; i < size; i++) {
    if (array[i]->task_no == task_number) {
      to_update = array[i];
    }
  }
  while (true) {
    int update_choice;
    std::string updated_task; 
    int updated_proirity;
    std::string updated_date;

    std::cout << "What would you like to update: \n";
    std::cout << "1. Task\n";
    std::cout << "2. Priority\n";
    std::cout << "3. Date\n";
    std::cout << "4. Exit\n";
    std::cin >> update_choice;

    if (update_choice == 1) {
      std::cout << "Enter updated task: ";
      std::cin >> updated_task;
      to_update->task = updated_task;
    } else if (update_choice == 2) {
      std::cout << "Enter updated priority: ";
      std::cin >> updated_proirity;
      to_update->priority = updated_proirity;
    } else if (update_choice == 3) {
      std::cout << "Enter updated date: ";
      std::cin >> updated_date;
      to_update->date = updated_date;
    } else if (update_choice == 4) {
      break;
    } else {
      std::cout << "Error: Choice unavailable\n";
      continue;
    }
  }
  return;
}

void print_item(ListItem *item) {
  std::cout << "Task No: " << item->task_no << "\n";
  std::cout << "Task: " << item->task << "\n";
  std::cout << "Priority: " << item->priority << "\n";
  std::cout << "Date: " << item->date << "\n";
  return;
}