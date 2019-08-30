#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>

#include "Linkedlist.h"

class Executive {
  public:
    Executive(std::string path);
    int menuInput();
    void run();
    bool parseInputFile();
    void parseNewString(std::string input);

  private:
    std::string filePath;
    Linkedlist* currentList;

};

#endif
