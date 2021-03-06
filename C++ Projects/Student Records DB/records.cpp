#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sqlite3.h>
#include <string>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  for(int i = 0; i<argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(int argc, char **argv) {
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
  std::string name;
  std::string phone_number;
  std::string email;
  std::string dept;
  std::string title;
  std::string aff;

  // UPDATE variables
  int column;
  std::string column_name;
  std::string current;
  std::string replace;

  // MISC variables
  char *error_msg;
  std::fstream fs;

  std::cout << "\n\n********** Welcome to the Student Records Database **********\n\n\n";
  
  rc = sqlite3_open("student.db", &db);

  // Find out size of database if it exists
  std::ifstream is ("student.db", std::ifstream::binary);
  is.seekg (0, is.end);
  int length = is.tellg();
  is.seekg (0, is.beg);

  // If DB is empty, create table
  if (length == 0) {
    if (rc) {
      std::cout << "Cannot open database!\n";
      return -1;
    }

    // Create a table
    create = "CREATE TABLE RECORDSYS( "
          "ID INTEGER PRIMARY KEY, "
          "NAME TEXT NOT NULL, "
          "PHONE_NUMBER TEXT NOT NULL, "
          "EMAIL TEXT NOT NULL, "
          "DEPT TEXT, "
          "TITLE TEXT, "
          "AFF TEXT NOT NULL); ";
    rc = sqlite3_exec(db, create.c_str(), NULL, 0, &error_msg);
    if (rc != SQLITE_OK) {
      std::cout << "Error: Cannot create table\n";
      return -1;
    }
  }
  // After DB and table are created, present Main Menu
  int choice;
  while (true) {
    // Main Menu
    std::cout << "1. Add student entry\n";
    std::cout << "2. Update student information\n";
    std::cout << "3. Delete student entry\n";
    std::cout << "4. Show student entry\n";
    std::cout << "5. Search\n";
    std::cout << "6. Exit\n\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cout << "\n";

    if (typeid(choice) == typeid(int)) {
      switch (choice) {
      // ADD ENTRY
        case 1:
          std::cout << "***** Adding student entry *****\n\n";

          select = "SELECT * FROM RECORDSYS;";
          rc = sqlite3_exec(db, select.c_str(), NULL, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SELECT Query in ADD ENTRY\n";
            return -1;
          }
          std::cout << "Enter a name: ";
          std::cin.ignore();
          getline(std::cin, name);
          std::cout << "Enter a phone number: ";
          getline(std::cin, phone_number);
          std::cout << "Enter an email: ";
          getline(std::cin, email);
          std::cout << "Enter a department: ";
          getline(std::cin, dept);
          std::cout << "Enter a title if applicable (otherwise input 'None'): ";
          getline(std::cin, title);
          std::cout << "Enter an affiliation (e.g.: undergraduate): ";
          getline(std::cin, aff);
          std::cout << "\n";

          insert = "INSERT INTO RECORDSYS (NAME, PHONE_NUMBER, EMAIL, DEPT, TITLE, AFF) VALUES ('" + name + "', '" + phone_number + "', '" + email + "', '" + dept + "', '" + title + "', '" + aff + "');";
          rc = sqlite3_exec(db, insert.c_str(), NULL, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
          }
          break;
      // UPDATE ENTRY
        case 2:
          while (true) {
            std::cout << "What would you like to update: \n";
            std::cout << "1. Name\n";
            std::cout << "2. Phone number\n";
            std::cout << "3. Email\n";
            std::cout << "4. Department\n";
            std::cout << "5. Title\n";
            std::cout << "6. Affiliation\n";
            std::cout << "7. Exit\n";
            std::cin >> column;

            if (column == 1) {
              column_name = "NAME";
            } else if (column == 2) {
              column_name = "PHONE_NUMBER";
            } else if (column == 3) {
              column_name = "EMAIL";
            } else if (column == 4) {
              column_name = "DEPT";
            } else if (column == 5) {
              column_name = "TITLE";
            } else if (column == 6) {
              column_name = "AFF";
            } else {
              std::cout << "\n";
              break;
            }

            std::cout << "Enter current " + column_name + ": ";
            std::cin.ignore();
            getline(std::cin, current);
            std::cout << "Enter new " + column_name + ": ";
            getline(std::cin, replace);

            update = "UPDATE RECORDSYS SET " + column_name + "='" + replace + "' WHERE " + column_name + "='" + current + "';";
            rc = sqlite3_exec(db, update.c_str(), NULL, 0, &error_msg);
            if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
            }
            std::cout << "\n";
          }
          break;
      // DELETE ENTRY
        case 3:
          std::cout << "\n***** Delete student entry *****\n\n";
          select = "SELECT * FROM RECORDSYS;";
          rc = sqlite3_exec(db, select.c_str(), NULL, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
          }
          int delete_choice;
          std::cout << "Delete based on: \n";
          std::cout << "1. Name\n";
          std::cout << "2. Phone number\n";
          std::cout << "3. Email\n";
          std::cout << "4. Department\n";
          std::cout << "5. Title\n";
          std::cout << "6. Affiliation\n";
          std::cin >> delete_choice;
          std::cin.ignore();

          if (delete_choice == 1) {
            std::cout << "Enter a name: ";
            getline(std::cin, name);
            del = "DELETE FROM RECORDSYS WHERE NAME='" + name + "';";
          } else if (delete_choice == 2) {
            std::cout << "Enter a phone number: ";
            getline(std::cin, phone_number);
            del = "DELETE FROM RECORDSYS WHERE PHONE_NUMBER='" + phone_number + "';";
          } else if (delete_choice == 3) {
            std::cout << "Enter an email: ";
            getline(std::cin, email);
            del = "DELETE FROM RECORDSYS WHERE EMAIL='" + email + "';";
          } else if (delete_choice == 4) {
            std::cout << "Enter a department: ";
            getline(std::cin, dept);
            del = "DELETE FROM RECORDSYS WHERE DEPT='" + dept + "';";
          } else if (delete_choice == 5) {
            std::cout << "Enter a title: ";
            getline(std::cin, title);
            del = "DELETE FROM RECORDSYS WHERE TITLE='" + title + "';";
          } else if (delete_choice == 6) {
            std::cout << "Enter an affiliation: ";
            getline(std::cin, aff);
            del = "DELETE FROM RECORDSYS WHERE AFF='" + aff + "';";
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
          select = "SELECT * FROM RECORDSYS";
          rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
          if (rc != SQLITE_OK) {
            std::cout << "Error: Cannot execute SQL Query\n";
            return -1;
          }
          break;
      // SEARCH
        case 5:
          while (true) {
            int search_choice;
            std::cout << "Search based on: \n";
            std::cout << "1. Name\n";
            std::cout << "2. Phone number\n";
            std::cout << "3. Email\n";
            std::cout << "4. Department\n";
            std::cout << "5. Title\n";
            std::cout << "6. Affiliation\n";
            std::cout << "7. Exit\n";
            std::cin >> search_choice;

            if (search_choice == 1) {
              std::cout << "Enter a name: ";
              std::cin.ignore();
              getline(std::cin, name);
              select = "SELECT * FROM RECORDSYS WHERE NAME='" + name +"';";
              rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
              if (rc != SQLITE_OK) {
                std::cout << "Error: Cannot execute SQL Query\n";
                return -1;
              } 
            } else if (search_choice == 2) {
              std::cout << "Enter a phone number: ";
              std::cin.ignore();
              getline(std::cin, phone_number);
              select = "SELECT * FROM RECORDSYS WHERE PHONE_NUMBER='" + phone_number +"';";
              rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
              if (rc != SQLITE_OK) {
                std::cout << "Error: Cannot execute SQL Query\n";
                return -1;
              } 
            } else if (search_choice == 3) {
              std::cout << "Enter a email: ";
              std::cin.ignore();
              getline(std::cin, email);
              select = "SELECT * FROM RECORDSYS WHERE EMAIL='" + email +"';";
              rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
              if (rc != SQLITE_OK) {
                std::cout << "Error: Cannot execute SQL Query\n";
                return -1;
              } 
            } else if (search_choice == 4) {
              std::cout << "Enter a department: ";
              std::cin.ignore();
              getline(std::cin, dept);
              select = "SELECT * FROM RECORDSYS WHERE DEPT='" + dept +"';";
              rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
              if (rc != SQLITE_OK) {
                std::cout << "Error: Cannot execute SQL Query\n";
                return -1;
              } 
            } else if (search_choice == 5) {
              std::cout << "Enter a title: ";
              std::cin.ignore();
              getline(std::cin, title);
              select = "SELECT * FROM RECORDSYS WHERE TITLE='" + title +"';";
              rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
              if (rc != SQLITE_OK) {
                std::cout << "Error: Cannot execute SQL Query\n";
                return -1;
              } 
            } else if (search_choice == 6) {
              std::cout << "Enter an affiliation: ";
              std::cin.ignore();
              getline(std::cin, aff);
              select = "SELECT * FROM RECORDSYS WHERE AFF='" + aff +"';";
              rc = sqlite3_exec(db, select.c_str(), callback, 0, &error_msg);
              if (rc != SQLITE_OK) {
                std::cout << "Error: Cannot execute SQL Query\n";
                return -1;
              } 
            } else if (search_choice == 7) {
              break;
            } else {
              std::cout << "Error: Choice unavailable\n";
              continue;
            }
          }
          break;
      // EXIT DB
        case 6:
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
