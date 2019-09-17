#include <iostream>
#include <string>
#include <fstream>

#include "Executive.h"
#include "Linkedlist.h"
#include "Hash.h"
#include "MyString.h"

Executive::Executive(MyString path) {
  std::cout<<"Path: " <<path.value() <<std::endl;
  filePath.setValue(path.value());
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
  std::cout <<"Opening File...";
  std::ifstream inputFile(filePath.value());
  std::cout <<"File Opened\n";
  MyString strInt;
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        char simpleArr[1] = {c};
        std::cout <<"Appending newString...";
        strInt.append(simpleArr);
        std::cout <<"newString appended\n";
      }
      else {
        // std::cout<<"Creating Node with Value: " <<strInt <<"\n";
        std::cout <<"Inserting Node...";
        currentList->insertNode(strInt.stoi());
        std::cout <<"Node inserted\n";
        std::cout <<"Setting strInt value to nullptr...";
        strInt.setValue(nullptr);
        std::cout <<"Value set\n";
      }
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath.value() <<" is an invalid path.\n";
    return(false);
  }
}
