#include <iostream>
#include <string>
#include <fstream>

#include "Executive.h"

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
          std::string input;
          std::cout << "Enter element to be inserted in list: ";
          std::cin.ignore();
          std::getline(std::cin, input);
          parseNewInput(input);
          break;
      }
      //Delete
      case 2: {
          std::string input;
          std::cout << "Enter the name to be deleted: ";
          std::cin.ignore();
          std::getline(std::cin, input);
          if(qHash->Delete(input)) {
            if(dHash->Delete(input)) {
              std::cout << "Deletion Status: Success/Success\n";
            }
            else {
              std::cout << "Deletion Status: Success/Failure\n";
            }
          }
          else {
            if(dHash->Delete(input)) {
              std::cout << "Deletion Status: Failure/Success\n";
            }
            else {
              std::cout << "Deletion Status: Failure/Failure\n";
            }
          }

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
          std::cout << "Quadratic Probing: \n\n";
          qHash->Print();
          std::cout << std::endl;
          std::cout << "Double Hashing: \n\n";
          dHash->Print();
          std::cout << "-----------------------------------------" << std::endl;
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

void Executive::parseNewInput(std::string input) {
  std::string strInt = "";
  int cellNum = 0;

  std::string name, priceRange;
  int rating;

  for(int lcv = 0; lcv < input.length(); lcv++) {
    char c = input[lcv];
    if(c == ' ') {
      //do nothing
    }
    else if (c != ',' && c != '\n') {
      strInt += c;
    }
    else if(c == ',') {
      if(cellNum == 0) {
        name = strInt;
      }
      else if(cellNum == 1) {
        rating = std::stoi(strInt);
      }
      else {
        std::cout << "ERROR: Trying to place data in unknown spot of Restaurant struct\n";
      }
      strInt = "";
      cellNum++;
    }
    else if(c == '\n') {
      //Do nothing till below
    }
    else {
      strInt = "";
    }
  }
    priceRange = strInt;
    std::cout <<"inserting node with values name: " <<name <<", rating: " <<rating <<", and price range: " <<priceRange <<std::endl;

    if(qHash->Insert(name, priceRange, rating)){
      if(dHash->Insert(name, priceRange, rating)){
        std::cout << "Insertion Status: Success/Success\n";
      }
      else {
        std::cout << "Insertion Status: Success/Failure\n";
      }
    }
    else {
      if(dHash->Insert(name, priceRange, rating)){
        std::cout << "Insertion Status: Failure/Success\n";
      }
      else {
        std::cout << "Insertion Status: Failure/Failure\n";
      }
    }

    strInt = "";
    name = "";
    priceRange = "";
    rating = 0;
    cellNum = 0;
}

bool Executive::parseInputFile() {
  std::ifstream inputFile(filePath);
  std::string strInt = "";
  int cellNum = 0;

  std::string name, priceRange;
  int rating;

  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if(c == ' ') {
        //do nothing
      }
      else if (c != ',' && c != '\n') {
        strInt += c;
      }
      else if(c == ',') {
        if(cellNum == 0) {
          name = strInt;
        }
        else if(cellNum == 1) {
          rating = std::stoi(strInt);
        }
        else {
          std::cout << "ERROR: Trying to place data in unknown spot of Restaurant struct\n";
          return(false);
        }
        strInt = "";
        cellNum++;
      }
      else if(c == '\n') {
        priceRange = strInt;
        std::cout <<"inserting node with values name: " <<name <<", rating: " <<rating <<", and price range: " <<priceRange <<std::endl;
        if(!qHash->Insert(name, priceRange, rating)){
          qHash->Rehash();
          if(qHash->Insert(name, priceRange, rating)){
            std::cout <<"Quadratic Probing: Insertion Status: Failure/Success\n";
          }
          else {
            std::cout <<"Quadratic Probing: Insertion Status: Failure/Failure\n";
          }
        }
        else {
          std::cout <<"Quadratic Probing: Insertion Status: Success\n";
        }


        if(!dHash->Insert(name, priceRange, rating)){
          dHash->Rehash();
          if(dHash->Insert(name, priceRange, rating)){
            std::cout <<"Double Hashing: Insertion Status: Failure/Success\n";
          }
          else {
            std::cout <<"Double Hashing: Insertion Status: Failure/Failure\n";
          }
        }
        else {
          std::cout <<"Double Hashing: Insertion Status: Success\n";
        }

        strInt = "";
        name = "";
        priceRange = "";
        rating = 0;
        cellNum = 0;
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
