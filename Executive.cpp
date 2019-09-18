#include <iostream>
#include <string>
#include <fstream>

#include "Executive.h"
#include "Linkedlist.h"
#include "Hash.h"

Executive::Executive(std::string path) {
  filePath = path;
  hashTable = new Hash;
}

int Executive::menuInput() {
  int choice;

  std::cout << "1. Insert \n";
  std::cout << "2. Delete \n";
  std::cout << "3. Find \n";
  std::cout << "4. Print \n";
  std::cout << "5. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      //Insert
      case 1: {
          std::string input;
          std::cout << "Enter element to be inserted in list: ";
          std::cin >> input;
          hashTable->Insert(input);
          break;
      }
      //Delete
      case 2: {
          std::string input;
          std::cout << "Enter the number to be deleted: ";
          std::cin >> input;
          if(hashTable->Delete(input)) {
            std::cout <<input << " was removed from the hash table. \n";
          }
          else {
            std::cout << "Delete failed. Number was not found in the list.\n";
          }
          break;
      }
      //Find
      case 3: {
          std::string input;
          std::cout << "Enter the number to find: ";
          std::cin >> input;
          hashTable->Find(input); 

          break;
      }
      //Print
      case 4: {
          hashTable->Print();
          break;
      }
      //Quit
      case 5: {
        delete hashTable;
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and 5.\n\n";
      }
    }
  }
}

bool Executive::parseInputFile() {
  std::ifstream inputFile(filePath);
  std::string strInt = "";
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != ',' && c != '\n') {
        strInt += c;
      }
      else {
        if(strInt != "") {
          hashTable->Insert(strInt);
        }
        strInt = "";
      }
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
