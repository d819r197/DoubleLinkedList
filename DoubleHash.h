#ifndef DOUBLEHASH_H
#define DOUBLEHASH_H

#include <iostream>
#include "RestaurantNode.h"

class DoubleHash {
  public:
    //Constructor
    DoubleHash();
    ~DoubleHash();

    bool Insert(std::string name, std::string priceRange, int rating);
    bool Delete(std::string name);
    void Print();
    void ComputeLamda();
    int HashFunction(std::string x);
    int NextPrime(int num);
    bool Rehash();
    bool Find(std::string x);

  private:
    int bucketSize;
    double lamda;
    RestaurantNode* table;
};

#endif
