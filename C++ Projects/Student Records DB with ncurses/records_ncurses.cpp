#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sqlite3.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

std::string str_name;
std::string str_phone_number;
std::string str_email;
std::string str_dept;
std::string str_title;
std::string str_aff;
char name[100];
char phone_number[100];
char email[100];
char dept[100];
char title[100];
char aff[100];

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  if (argc == 0) {
    printw("No Entries\n");
    refresh();
  }
  for(int i = 0; i<argc; i++) {
    printw("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    refresh();
  }
  printw("\n");
  refresh();

  return 0;
}

void add_entry(std::string select, std::string insert, sqlite3 *db, char *error_msg, int rc) {
  init_pair(2, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(2));
  attron(A_BOLD);
  printw("\n\n***** Adding student entry *****\n\n");
  refresh();

  select = "SELECT * FROM RECORDSYS;";
  rc = sqlite3_exec(db, select.c_str(), NULL, 0, &error_msg);
  if (rc != SQLITE_OK) {
    printw("Error: Cannot execute SELECT Query in ADD ENTRY\n");
    refresh();
    exit(-1);
  }
  printw("Enter a name: ");
  refresh();
  getstr(name);
  printw("Enter a phone number: ");
  refresh();
  getstr(phone_number);
  printw("Enter an email: ");
  refresh();
  getstr(email);
  printw("Enter a department: ");
  refresh();
  getstr(dept);
  printw("Enter a title if applicable (otherwise input 'None'): ");
  refresh();
  getstr(title);
  printw("Enter an affiliation (e.g.: undergraduate): ");
  refresh();
  getstr(aff);
  printw("\n");
  refresh();

  str_name = name;
  str_phone_number = phone_number;
  str_email = email;
  str_dept = dept;
  str_title = title;
  str_aff = aff;

  insert = "INSERT INTO RECORDSYS (NAME, PHONE_NUMBER, EMAIL, DEPT, TITLE, AFF) VALUES ('" + str_name + "', '" + str_phone_number + "', '" + str_email + "', '" + str_dept + "', '" + str_title + "', '" + str_aff + "');";
  rc = sqlite3_exec(db, insert.c_str(), NULL, 0, &error_msg);
  if (rc != SQLITE_OK) {
    printw("Error: Cannot execute SQL Query\n");
    refresh();
    exit(-1);
  }
  attroff(COLOR_PAIR(2));
  attroff(A_BOLD);
}

void update_entry(std::string select, std::string update, sqlite3 *db, char *error_msg, int rc) {
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  attron(COLOR_PAIR(3));
  attron(A_BOLD);
  int column;
  std::string column_name;

  char current[100];
  char replace[100];

  std::string str_current;
  std::string str_replace;
  while (true) {
    erase();
    printw("\n\n***** Updating student entry *****\n\n");
    printw("What would you like to update: \n");
    printw("1. Name\n");
    printw("2. Phone number\n");
    printw("3. Email\n");
    printw("4. Department\n");
    printw("5. Title\n");
    printw("6. Affiliation\n");
    printw("7. Exit\n\n");
    refresh();
    column = getch();

    if (column == 49) {
      column_name = "NAME";
    } else if (column == 50) {
      column_name = "PHONE_NUMBER";
    } else if (column == 51) {
      column_name = "EMAIL";
    } else if (column == 52) {
      column_name = "DEPT";
    } else if (column == 53) {
      column_name = "TITLE";
    } else if (column == 54) {
      column_name = "AFF";
    } else {
      printw("\n");
      refresh();
      break;
    }
    printw("\n");
    printw("Enter current value: ");
    refresh();
    getstr(current);
    str_current = current;
    printw("Enter new value: ");
    refresh();
    getstr(replace);
    str_replace = replace;

    update = "UPDATE RECORDSYS SET " + column_name + "='" + str_replace + "' WHERE " + column_name + "='" + str_current + "';";
    rc = sqlite3_exec(db, update.c_str(), NULL, 0, &error_msg);
    if (rc != SQLITE_OK) {
      printw("Error: Cannot execute SQL Query\n");
      refresh();
      exit(-1);
    }
    printw("\n");
  }
  attroff(COLOR_PAIR(3));
  attroff(A_BOLD);
}

void delete_entry(std::string select, std::string del, sqlite3 *db, char *error_msg, int rc) {
  init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
  attron(COLOR_PAIR(4));
  attron(A_BOLD);
  printw("\n***** Delete student entry *****\n\n");
  refresh();
  select = "SELECT * FROM RECORDSYS;";
  rc = sqlite3_exec(db, select.c_str(), NULL, 0, &error_msg);
  if (rc != SQLITE_OK) {
    printw("Error: Cannot execute SQL Query\n");
    refresh();
    exit(-1);
  }
  int delete_choice;
  printw("Delete based on: \n");
  printw("1. Name\n");
  printw("2. Phone number\n");
  printw("3. Email\n");
  printw("4. Department\n");
  printw("5. Title\n");
  printw("6. Affiliation\n");
  printw("7. Exit\n");
  printw("\n");
  refresh();
  delete_choice = getch();
  printw("\n\n");
  refresh();

  if (delete_choice == 49) {
    printw("Enter a name: ");
    refresh();
    getstr(name);
    str_name = name;
    del = "DELETE FROM RECORDSYS WHERE NAME='" + str_name + "';";
  } else if (delete_choice == 50) {
    printw("Enter a phone number: ");
    refresh();
    getstr(phone_number);
    str_phone_number = phone_number;
    del = "DELETE FROM RECORDSYS WHERE PHONE_NUMBER='" + str_phone_number + "';";
  } else if (delete_choice == 51) {
    printw("Enter an email: ");
    refresh();
    getstr(email);
    str_email = email;
    del = "DELETE FROM RECORDSYS WHERE EMAIL='" + str_email + "';";
  } else if (delete_choice == 52) {
    printw("Enter a department: ");
    refresh();
    getstr(dept);
    str_dept = dept;
    del = "DELETE FROM RECORDSYS WHERE DEPT='" + str_dept + "';";
  } else if (delete_choice == 53) {
    printw("Enter a title: ");
    refresh();
    getstr(title);
    str_title = title;
    del = "DELETE FROM RECORDSYS WHERE TITLE='" + str_title + "';";
  } else if (delete_choice == 54) {
    printw("Enter an affiliation: ");
    refresh();
    getstr(aff);
    str_aff = aff;
    del = "DELETE FROM RECORDSYS WHERE AFF='" + str_aff + "';";
  } else if (delete_choice == 55) {

  } else {
    printw("Error: Choice unavailable\n\n");
    refresh();
  }
  rc = sqlite3_exec(db, del.c_str(), NULL, 0, &error_msg);
  if (rc != SQLITE_OK) {
    printw("Error: Cannot execute SQL Query\n");
    refresh();
    exit(-1);
  }
  printw("\n");
  refresh();
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
}

void search(std::string select, sqlite3 *db, char *error_msg, int rc) {
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  attron(COLOR_PAIR(6));
  attron(A_BOLD);
  while (true) {
    erase();
    int search_choice;
    printw("\n\n***** Search for student entry *****\n\n");
    printw("Search based on: \n");
    printw("1. Name\n");
    printw("2. Phone number\n");
    printw("3. Email\n");
    printw("4. Department\n");
    printw("5. Title\n");
    printw("6. Affiliation\n");
    printw("7. Exit\n");
    refresh();
    search_choice = getch();
    printw("\n");
    refresh();

    if (search_choice == 49) {
      printw("Enter a name: ");
      refresh();
      getstr(name);
      str_name = name;
      select = "SELECT * FROM RECORDSYS WHERE NAME='" + str_name +"';";
    } else if (search_choice == 50) {
      printw("Enter a phone number: ");
      refresh();
      getstr(phone_number);
      str_phone_number = phone_number;
      select = "SELECT * FROM RECORDSYS WHERE PHONE_NUMBER='" + str_phone_number +"';";
    } else if (search_choice == 51) {
      printw("Enter a email: ");
      refresh();
      getstr(email);
      str_email = email;
      select = "SELECT * FROM RECORDSYS WHERE EMAIL='" + str_email +"';";
    } else if (search_choice == 52) {
      printw("Enter a department: ");
      refresh();
      getstr(dept);
      str_dept = dept;
      select = "SELECT * FROM RECORDSYS WHERE DEPT='" + str_dept +"';";
    } else if (search_choice == 53) {
      printw("Enter a title: ");
      refresh();
      getstr(title);
      str_title = title;
      select = "SELECT * FROM RECORDSYS WHERE TITLE='" + str_title +"';";
    } else if (search_choice == 54) {
      printw("Enter an affiliation: ");
      refresh();
      getstr(aff);
      str_aff = aff;
      select = "SELECT * FROM RECORDSYS WHERE AFF='" + str_aff +"';";
    } else if (search_choice == 55) {
      break;
    } else {
      printw( "Error: Choice unavailable\n");
      refresh();
      continue;
    }
    erase();
    printw("\n\n***** Search Results *****\n\n");
    rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
    if (rc != SQLITE_OK) {
      printw("Error: Cannot execute SQL Query\n");
      refresh();
      exit(-1);
    } 
    printw("Press any key to continue...");
    getch();
    attroff(COLOR_PAIR(6));
    attroff(A_BOLD);
  }
}

int main(int argc, char **argv) {
  initscr();
  // Database Variables
  sqlite3 *db;
  int rc;
  char *error_msg;
  std::fstream fs;

  // Database Actions
  std::string create;
  std::string insert;
  std::string select;
  std::string del;
  std::string update;
  
  rc = sqlite3_open("records.db", &db);

  // Find out size of database if it exists
  std::ifstream is ("records.db", std::ifstream::binary);
  is.seekg (0, is.end);
  int length = is.tellg();
  is.seekg (0, is.beg);

  // If DB is empty, create table
  if (length == 0) {
    if (rc) {
      printw("Cannot open database!\n");
      refresh();
      return -1;
    }
    // Create a table
    create = "CREATE TABLE RECORDSYS ( "
          "ID INTEGER PRIMARY KEY, "
          "NAME TEXT NOT NULL, "
          "PHONE_NUMBER TEXT NOT NULL, "
          "EMAIL TEXT NOT NULL, "
          "DEPT TEXT, "
          "TITLE TEXT, "
          "AFF TEXT NOT NULL); ";
    rc = sqlite3_exec(db, create.c_str(), NULL, 0, &error_msg);
    if (rc != SQLITE_OK) {
      printw("Error: Cannot create table\n");
      refresh();
      return -1;
    }
  }
  // After DB and table are created, present Main Menu
  while (true) {
    erase();
    // Main Menu
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    printw("\n\n********** Welcome to the Student Records Database **********\n\n\n");
    printw("1. Add student entry\n");
    printw("2. Update student information\n");
    printw("3. Delete student entry\n");
    printw("4. Show student entries\n");
    printw("5. Search\n");
    printw("6. Exit\n\n");
    printw("Enter choice: ");
    refresh();
    int choice = getch();
    printw("\n");
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD);
    refresh();
    erase();
    
    switch (choice) {
    // ADD ENTRY
      case 49:
        add_entry(select, insert, db, error_msg, rc);
        break;
    // UPDATE ENTRY
      case 50:
        update_entry(select, update, db, error_msg, rc);
        break;
    // DELETE ENTRY
      case 51:
        delete_entry(select, del, db, error_msg, rc);
        break;
    // SHOW TABLE ENTRIES
      case 52:
        init_pair(5, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(5));
        attron(A_BOLD);
        select = "SELECT * FROM RECORDSYS";
        printw("\n\n***** Current Student Entries *****\n\n");
        refresh();
        rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
        if (rc != SQLITE_OK) {
          printw("Error: Cannot execute SQL Query\n");
          refresh();
          return -1;
        }
        printw("Press any key to continue...");
        getch();
        refresh();
        attroff(COLOR_PAIR(5));
        attroff(A_BOLD);
        break;
    // SEARCH
      case 53:
        search(select, db, error_msg, rc);
        break;
    // EXIT DB
      case 54:
        sqlite3_close(db);
        printw("\n********** Goodbye! **********\n\n");
        refresh();
        endwin();
        return 0;
    // DEFAULT
      default:
        printw("Error: Choice unavailable\n\n");
        refresh();
        break;
    }
  }
}
