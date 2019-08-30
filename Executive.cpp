#include <iostream>
#include <string>
#include <fstream>

#include "Executive.h"
#include "Linkedlist.h"

Executive::Executive(std::string path) {
  filePath = path;
  currentList = new Linkedlist;
}

int Executive::menuInput() {
  int choice;

  std::cout << "1. Insert \n";
  std::cout << "2. Delete \n";
  std::cout << "3. Find Smallest Number \n";
  std::cout << "4. Find Largest Number \n";
  std::cout << "5. Average of Numbers \n";
  std::cout << "6. Merge2Lists \n";
  std::cout << "7. Print \n";
  std::cout << "8. ReverseList \n";
  std::cout << "9. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      case 1: {
          int input;
          std::cout << "Enter element to be inserted in list: ";
          std::cin >> input;
          currentList->insertNode(input);
          break;
      }
      case 2: {
          int input;
          std::cout << "Enter the number to be deleted: ";
          std::cin >> input;
          currentList->deleteNode(input);
          break;
      }
      case 3: {
          break;
      }
      case 4: {
          break;
      }
      case 5: {
          break;
      }
      case 6: {
          break;
      }
      case 7: {
          currentList->printList();
          break;
      }
      case 8: {
          break;
      }
      case 9: {
          quit = true;
          break;
      }
      default: {
          std::cout << "Please input a number between 1 and 9.\n\n";
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
        std::cout<<"Creating Node with Value: " <<strInt <<"\n";
        // Node* newNode= new Node(std::stoi(strInt));
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
