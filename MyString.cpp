#include <iostream>

#include "MyString.h"

//Constructors
MyString::MyString() {
  stringSize = 0;
  stringValue[0] = {};
}

MyString::MyString(char arr[]) {
  stringSize = *(&arr + 1) - arr;
  stringValue = arr;
}
//
// MyString::MyString(char* arrPtr) {
//   stringValue = arrPtr;
//   stringSize = *(&arr + 1) - arr;
// }

int MyString::stoi()
{
    int intInt;
    intInt = 0;
    while(*stringValue >= '0' && *stringValue <= '9')
    {
        intInt = intInt * 10 + (*stringValue - '0');
        stringValue++;
    }
    return intInt;
}

int MyString::size() {
  return(stringSize);
}

char MyString::at(int pos) {
  return(stringValue[pos]);
}

void MyString::append(MyString newString) {
  char* arr = newString.value();
  int newStringSize = *(&arr + 1) - arr;
  int mergedArrSize = newStringSize + stringSize;
  char mergedArr[mergedArrSize];

  if(stringSize == 0) {
    setValue(newString.value());
  }
  else {
    for(int lcv = 0; lcv < mergedArrSize; lcv++) {
      if(lcv < stringSize) {
        mergedArr[lcv] = stringValue[lcv];
      }
      else if (lcv >= stringSize && lcv < mergedArrSize) {
        mergedArr[lcv] = newString.value()[lcv];
      }
    }
    char* newArrPtr = mergedArr;
    std::cout <<stringValue <<" + " <<newString.value() <<" = " <<mergedArr <<std::endl;

    setValue(newArrPtr);
  }
}

char* MyString::value() {
  return(stringValue);
}

void MyString::setValue(char* arr) {
  stringSize = *(&arr + 1) - arr;
  stringValue = arr;
}
