#include <iostream>
#include <string>
#include <fstream>

#include "Executive.h"
// #include "DoubleHash.h"
// #include "QuadraticHash.h"

Executive::Executive(std::string path) {
  filePath = path;
  qHash = new QuadraticHash;
  dHash = new DoubleHash;
}

int Executive::menuInput() {
  int choice;

  std::cout << "1. Insert \n";
  std::cout << "2. Delete \n";
  std::cout << "3. FindByRating \n";
  std::cout << "4. SearchByPrice \n";
  std::cout << "5. Print \n";
  std::cout << "6. Exit \n";

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
          // qHash->insert(input);
          // dHash->insert(input)
          break;
      }
      //Delete
      case 2: {
          std::string input;
          std::cout << "Enter the name to be deleted: ";
          std::cin >> input;
          // if(currentList->deleteNode(input)) {
          //   std::cout << "Delete was successful. \n";
          // }
          // else {
          //   std::cout << "Delete failed. Number was not found in the list.\n";
          // }
          break;
      }
      //FindByRating
      case 3: {
          break;
      }
      //SearchByPrice
      case 4: {
          break;
      }
      //Print
      case 5: {
          qHash->Print();
          dHash->Print();
          break;
      }
      //Quit
      case 6: {
        delete qHash;
        delete dHash;
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
  int cellNum = 0;

  std::string name, rating;
  int priceRange;

  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ') {
        strInt += c;
      }
      else if(c == ',') {
        if(cellNum == 0) {
          name = strInt;
        }
        else if(cellNum == 1) {
          rating = strInt;
        }
        else if(cellNum == 2 ) {
          priceRange = std::stoi(strInt);
        }
        else {
          std::cout << "ERROR: Trying to place data in unknown spot of Restaurant struct\n";
          return(false);
        }
        strInt = "";
        cellNum++;
      }
      else if(c == '\n') {
        qHash->Insert(name, rating, priceRange);
        dHash->Insert(name, rating, priceRange);

        name = "";
        rating = "";
        priceRange = 0;
      }
      else {
        // std::cout<<"Creating Node with Value: " <<strInt <<"\n";
        // currentList->insertNode(std::stoi(strInt));
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
