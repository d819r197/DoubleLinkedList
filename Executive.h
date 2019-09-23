#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>

#include "QuadraticHash.h"
#include "DoubleHash.h"

class Executive {
  public:
    Executive(std::string path);

    int menuInput();
    void run();
    bool parseInputFile();

  private:
    std::string filePath;
    QuadraticHash* qHash;
    DoubleHash* dHash;

};

#endif
