#include <iostream>
#include <string>
#include <fstream>

#include "Executive.h"
#include "Linkedlist.h"
#include "Hash.h"

Executive::Executive(std::string path) {
  filePath = path;
  currentList = new Linkedlist;
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
          int input;
          std::cout << "Enter element to be inserted in list: ";
          std::cin >> input;
          currentList->insertNode(input);
          break;
      }
      //Delete
      case 2: {
          int input;
          std::cout << "Enter the number to be deleted: ";
          std::cin >> input;
          if(currentList->deleteNode(input)) {
            std::cout << "Delete was successful. \n";
          }
          else {
            std::cout << "Delete failed. Number was not found in the list.\n";
          }
          break;
      }
      //Find
      case 3: {
          break;
      }
      //Print
      case 4: {
          currentList->printList();
          break;
      }
      //Quit
      case 5: {
        delete currentList;
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
      if (c != ' ' && c != '\n') {
        strInt += c;
      }
      else {
        // std::cout<<"Creating Node with Value: " <<strInt <<"\n";
        currentList->insertNode(std::stoi(strInt));
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
