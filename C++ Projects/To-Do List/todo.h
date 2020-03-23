#include <iostream>
#include <string.h>

typedef struct to_do_list {
  std::string task;
  int priority;
  std::string date;
} ListItem;

ListItem *new_item(std::string item, int priority, std::string date);

void delete_item(ListItem *);

ListItem *update_item(ListItem *);

void print_item(ListItem *item);