#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sqlite3.h>
#include <string>

/*
TODO:
Update Table



*/
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  for(int i = 0; i<argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(int argc, char **argv) {
  sqlite3 *db;
  int rc;
  std::string create;
  std::string insert;
  std::string select;
  std::string del;
  //std::string update;

  std::string name;
  std::string age;
  std::string phone_number;
  std::string address;

  char *error_msg;
  std::fstream fs;

  std::cout << "\n\n********** Welcome to the Student Records Database **********\n\n\n";
  
  rc = sqlite3_open("student.db", &db);

  std::ifstream is ("student.db", std::ifstream::binary);
  is.seekg (0, is.end);
  int length = is.tellg();
  is.seekg (0, is.beg);

  if (length == 0) {
    if (rc) {
      std::cout << "Cannot open database!\n";
      return -1;
    }

    // Create a table
    create = "CREATE TABLE BANKSYS( "
          "ID INTEGER PRIMARY KEY, "
          "NAME TEXT NOT NULL, "
          "AGE TEXT NOT NULL, "
          "PHONE_NUMBER TEXT NOT NULL, "
          "ADDRESS TEXT NOT NULL); ";
    rc = sqlite3_exec(db, create.c_str(), NULL, 0, &error_msg);
    if (rc != SQLITE_OK) {
      std::cout << "Error: Cannot execute SQL Query\n";
      return -1;
    }
  }
  int choice;
  while (true) {
    std::cout << "1. Add student entry\n";
    std::cout << "2. Update student information\n";
    std::cout << "3. Delete student entry\n";
    std::cout << "4. Show student entry\n";
    std::cout << "5. Exit\n\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cout << "\n";

    if (typeid(choice) == typeid(int)) {
      switch (choice) {
        // ADD ENTRY
        case 1:
          std::cout << "***** Adding student entry *****\n\n";

          select = "SELECT * FROM BANKSYS;";
          rc = sqlite3_exec(db, select.c_str(), NULL, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
          }
          std::cin.ignore();
          std::cout << "Enter a name: ";
          getline(std::cin, name);
          std::cout << "Enter an age: ";
          std::cin >> age;
          std::cout << "Enter a phone number: ";
          std::cin >> phone_number;
          std::cin.ignore();
          std::cout << "Enter an address: ";
          getline(std::cin, address);
          std::cout << "\n";

          insert = "INSERT INTO BANKSYS (NAME, AGE, PHONE_NUMBER, ADDRESS) VALUES ('" + name + "', '" + age + "', '" + phone_number + "', '" + address + "');";
          rc = sqlite3_exec(db, insert.c_str(), NULL, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
          }
          break;
        // UPDATE ENTRY
        case 2:
          std::cout << "Provide the following information to update a student entry\n";

          std::cin.ignore();
          std::cout << "Enter a name: ";
          getline(std::cin, name);
          std::cout << "Enter an age: ";
          std::cin >> age;
          std::cout << "Enter a phone number: ";
          std::cin >> phone_number;
          std::cin.ignore();
          std::cout << "Enter an address: ";
          getline(std::cin, address);
          std::cout << "\n";

          std::cout << "What would you like to update";
          break;
        // DELETE ENTRY
        case 3:
          std::cout << "\n***** Delete student entry *****\n\n";

          select = "SELECT * FROM BANKSYS;";
          rc = sqlite3_exec(db, select.c_str(), NULL, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
          }
          int delete_choice;
          std::cout << "Delete based on: \n";
          std::cout << "1. Name\n";
          std::cout << "2. Age\n";
          std::cout << "3. Phone number\n";
          std::cout << "4. Address\n";
          std::cin >> delete_choice;
          
          if (delete_choice == 1) {
            std::cout << "Enter a name: ";
            std::cin >> name;
            del = "DELETE FROM BANKSYS WHERE NAME='" + name + "';";
          } else if (delete_choice == 2) {
            std::cout << "Enter an age: ";
            std::cin >> age;
            del = "DELETE FROM BANKSYS WHERE AGE='" + age + "';";
          } else if (delete_choice == 3) {
            std::cout << "Enter a phone number: ";
            std::cin >> phone_number;
            del = "DELETE FROM BANKSYS WHERE PHONE_NUMBER='" + phone_number + "';";
          } else if (delete_choice == 4) {
            std::cin.ignore();
            std::cout << "Enter an address: ";
            getline(std::cin, address);
            del = "DELETE FROM BANKSYS WHERE ADDRESS='" + address + "';";
          } else {
            std::cout << "Error: Choice unavailable\n\n";
            continue;
          }
          rc = sqlite3_exec(db, del.c_str(), NULL, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
          }
          std::cout << "\n";
          break;
        // SHOW TABLE ENTRIES
        case 4:
          select = "SELECT * FROM BANKSYS";
          rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
          }
          break;
        // EXIT DB
        case 5:
          sqlite3_close(db);
          std::cout << "\n********** Goodbye! **********\n\n";
          return 0;
        default:
          std::cout << "Error: Choice unavailable\n\n";
          break;
      }
    } else {
      std::cout << "Error: Choice must be an integer\n\n";
      return -1;
    }
  }
}
