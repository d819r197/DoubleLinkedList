#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>


class MyString {
  public:
    //Constructor
    MyString();
    MyString(char arr[]);
    // MyString(char* arr);

    int size();
    char at(int pos);
    void append(MyString newString);
    int stoi();

    //Helper Functions
    char* value();
    void setValue(char* arr);

  private:
    int stringSize;
    char* stringValue;
};

#endif
