#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include "Linkedlist.h"

class Hash {
  public:
    //Constructor & Deconstructor
    Hash();
    ~Hash();

    bool Insert(std::string x);
    bool Delete(std::string x);
    void Print();
    int HashFunction(std::string x);
    void Rehash();
    bool Find(std::string x);
    void ComputeLamda();
    int NextPrime(int num);

  private:
    int bucketSize;
    Linkedlist* table;
    double lamda;
};

#endif
