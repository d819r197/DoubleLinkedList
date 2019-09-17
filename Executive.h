#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
// #include <string>

#include "Linkedlist.h"
#include "Hash.h"
#include "MyString.h"

class Executive {
  public:
    Executive(MyString path);

    int menuInput();
    void run();
    bool parseInputFile();

  private:
    MyString filePath;
    Linkedlist* currentList;

};

#endif
