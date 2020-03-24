#include <iostream>
#include <string.h>

typedef struct to_do_list {
  int task_no;
  std::string task;
  int priority;
  std::string date;
} ListItem;

ListItem *new_item(std::string item, int priority, std::string date, int index);

int deleted_item(ListItem **array, int task_number, int size);

void destroy_task(ListItem *);

void update_item(ListItem **array, int task_number, int size);

void print_simple(ListItem *item);

void print_details(ListItem *item);