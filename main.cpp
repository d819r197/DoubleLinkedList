#include <iostream>
#include <typeinfo>

#include "MyString.h"
#include "Executive.h"

int main(int argc, char* argv[]) {
  //./DoubleLinkedList filePath
  if(argc == 2) {
    std::cout <<"argc: " <<argc <<" and argv[1]: " <<argv[1] <<std::endl;
    MyString input(argv[1]);
    char* test = argv[1];
    std::cout <<"test: " <<test <<" and newTest: " <<input.value() <<std::endl;
    std::cout <<"Type: " <<typeid(*test).name() << std::endl;
    std::cout <<"Creating Exec Obj...\n";
    Executive exec(input);
    std::cout <<"Exec obj created\n";
    std::cout <<"Parsing Imput File...";
    if(exec.parseInputFile()) {
      std::cout <<"Parse Completed\n";
      exec.run();
    }
  }
  //Bad Input
  else {
    std::cout<<"Invalid input. Try again.\n";
  }

  return 0;
}
