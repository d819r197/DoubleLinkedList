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
      //Smallest Number
      case 3: {
          std::cout <<"Smallest number: " <<currentList->smallest() <<std::endl;
          break;
      }
      //Largest Number
      case 4: {
          std::cout <<"Largest number: " <<currentList->largest() <<std::endl;
          break;
      }
      //List Average
      case 5: {
          std::cout <<"Average: " <<currentList->average() <<std::endl;
          break;
      }
      //Merge2Lists
      case 6: {
          std::string input;
          std::cout << "Enter a new list to be merged\n";
          std::cin.ignore();
          std::getline(std::cin, input);
          parseNewString(input);
          std::cout <<"Merged List: ";
          currentList->printList();
          break;
      }
      //Print List
      case 7: {
          currentList->printList();
          break;
      }
      //Reverse List
      case 8: {
          // (currentList->reverseList())->printList();
          currentList = currentList->reverseList();
          currentList->printList();
          break;
      }
      //Quit
      case 9: {
          quit = true;
          break;
      }
      //Invalid Input
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

void Executive::parseNewString(std::string input) {
  std::string strInt = "";
  std::cout <<"User input: " <<input <<std::endl;
  for(int lcv = 0; lcv < input.size(); lcv++) {
    if(input[lcv] != ' ' && input[lcv] != '\n') {
      strInt += input[lcv];
    }
    else {
      currentList->insertNode(std::stoi(strInt));
      strInt = "";
    }
  }
  currentList->insertNode(std::stoi(strInt));
}
