#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>

class Executive {
  public:
    Executive(std::string path);
    void printMenu();
    void run();
    void parseInputFile();

  private:
    std::string filePath;
};

#endif
