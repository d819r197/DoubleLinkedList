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

  private:
    std::string filePath;
    Linkedlist* currentList;

};

#endif
