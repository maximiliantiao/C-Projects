#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sqlite3.h>
#include <string.h>
#include <ncurses.h>

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

void setZero(char *info) {
  for (int i = 0; i < sizeof(info); i++) {
    info[i] = 0;
  }
  return;
}

int main(int argc, char **argv) {
  initscr();
  // Database Variables
  sqlite3 *db;
  int rc;

  // Database Actions
  std::string create;
  std::string insert;
  std::string select;
  std::string del;
  std::string update;

  // Column Names
  char name[100];
  setZero(name);
  char phone_number[100];
  setZero(phone_number);
  char email[100];
  setZero(email);
  char dept[100];
  setZero(dept);
  char title[100];
  setZero(title);
  char aff[100];
  setZero(aff);

  std::string str_name;
  std::string str_phone_number;
  std::string str_email;
  std::string str_dept;
  std::string str_title;
  std::string str_aff;

  // UPDATE variables
  int column;
  std::string column_name;

  char current[100];
  setZero(current);
  char replace[100];
  setZero(replace);

  std::string str_current;
  std::string str_replace;

  // MISC variables
  char *error_msg;
  std::fstream fs;
  
  rc = sqlite3_open("copy.db", &db);

  // Find out size of database if it exists
  std::ifstream is ("copy.db", std::ifstream::binary);
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
    create = "CREATE TABLE BANKSYS( "
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
    printw("\n\n********** Welcome to the Student Records Database **********\n\n\n");
    printw("1. Add student entry\n");
    printw("2. Update student information\n");
    printw("3. Delete student entry\n");
    printw("4. Show student entries\n");
    printw("5. Exit\n\n");
    printw("Enter choice: ");
    refresh();
    int choice = getch();
    printw("\n");
    refresh();
    erase();
    
    switch (choice) {
    // ADD ENTRY
      case 49:
        printw("\n\n***** Adding student entry *****\n\n");
        refresh();

        select = "SELECT * FROM BANKSYS;";
        rc = sqlite3_exec(db, select.c_str(), NULL, 0, &error_msg);
        if (rc != SQLITE_OK) {
          printw("Error: Cannot execute SELECT Query in ADD ENTRY\n");
          refresh();
          return -1;
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

        insert = "INSERT INTO BANKSYS (NAME, PHONE_NUMBER, EMAIL, DEPT, TITLE, AFF) VALUES ('" + str_name + "', '" + str_phone_number + "', '" + str_email + "', '" + str_dept + "', '" + str_title + "', '" + str_aff + "');";
        rc = sqlite3_exec(db, insert.c_str(), NULL, 0, &error_msg);
        if (rc != SQLITE_OK) {
          printw("Error: Cannot execute SQL Query\n");
          refresh();
          return -1;
        }
        break;
    // UPDATE ENTRY
      case 50:
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

          update = "UPDATE BANKSYS SET " + column_name + "='" + str_replace + "' WHERE " + column_name + "='" + str_current + "';";
          rc = sqlite3_exec(db, update.c_str(), NULL, 0, &error_msg);
          if (rc != SQLITE_OK) {
            printw("Error: Cannot execute SQL Query\n");
            refresh();
            return -1;
          }
          printw("\n");
        }
        break;
    // DELETE ENTRY
      case 51:
        printw("\n***** Delete student entry *****\n\n");
        refresh();
        select = "SELECT * FROM BANKSYS;";
        rc = sqlite3_exec(db, select.c_str(), NULL, 0, &error_msg);
        if (rc != SQLITE_OK) {
          printw("Error: Cannot execute SQL Query\n");
          refresh();
          return -1;
        }
        int delete_choice;
        printw("Delete based on: \n");
        printw("1. Name\n");
        printw("2. Phone number\n");
        printw("3. Email\n");
        printw("4. Department\n");
        printw("5. Title\n");
        printw("6. Affiliation\n");
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
          del = "DELETE FROM BANKSYS WHERE NAME='" + str_name + "';";
        } else if (delete_choice == 50) {
          printw("Enter a phone number: ");
          refresh();
          getstr(phone_number);
          str_phone_number = phone_number;
          del = "DELETE FROM BANKSYS WHERE PHONE_NUMBER='" + str_phone_number + "';";
        } else if (delete_choice == 51) {
          printw("Enter an email: ");
          refresh();
          getstr(email);
          str_email = email;
          del = "DELETE FROM BANKSYS WHERE EMAIL='" + str_email + "';";
        } else if (delete_choice == 52) {
          printw("Enter a department: ");
          refresh();
          getstr(dept);
          str_dept = dept;
          del = "DELETE FROM BANKSYS WHERE DEPT='" + str_dept + "';";
        } else if (delete_choice == 53) {
          printw("Enter a title: ");
          refresh();
          getstr(title);
          str_title = title;
          del = "DELETE FROM BANKSYS WHERE TITLE='" + str_title + "';";
        } else if (delete_choice == 54) {
          printw("Enter an affiliation: ");
          refresh();
          getstr(aff);
          str_aff = aff;
          del = "DELETE FROM BANKSYS WHERE AFF='" + str_aff + "';";
        } else {
          printw("Error: Choice unavailable\n\n");
          refresh();
          continue;
        }
        rc = sqlite3_exec(db, del.c_str(), NULL, 0, &error_msg);
        if (rc != SQLITE_OK) {
          printw("Error: Cannot execute SQL Query\n");
          refresh();
          return -1;
        }
        printw("\n");
        refresh();
        break;
    // SHOW TABLE ENTRIES
      case 52:
        select = "SELECT * FROM BANKSYS";
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
        break;
    // EXIT DB
      case 53:
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
