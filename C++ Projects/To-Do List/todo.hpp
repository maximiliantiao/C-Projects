#include <iostream>
#include <string.h>

typedef struct to_do_list {
  int task_no;
  std::string task;
  int priority;
  std::string date;
} ListItem;

ListItem *new_item(std::string item, int priority, std::string date);

int deleted_item(ListItem **array, int task_number, int size);

void destroy_task(ListItem *);

ListItem *update_item(ListItem *);

void print_item(ListItem *item);