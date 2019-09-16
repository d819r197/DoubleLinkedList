#ifndef HASH_H
#define HASH_H

#include <iostream>

class Hash {
  public:
    //Constructor
    Hash();

    bool Insert(char* x[]);
    bool Delete(char* x[]);
    void Print();
    int HashFunction(char* x[], int bucketSize);
    Hash* Rehash();
    bool Find(char* x[]);

  private:
};

#endif
