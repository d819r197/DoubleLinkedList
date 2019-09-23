#ifndef DOUBLEHASH_H
#define DOUBLEHASH_H

#include <iostream>
#include "RestaurantNode.h"

class DoubleHash {
  public:
    //Constructor
    DoubleHash();
    ~DoubleHash();


    bool Insert(std::string name, std::string rating, int priceRange);
    bool Delete(RestaurantNode x);
    void Print();
    int HashFunction(RestaurantNode x);
    bool Rehash();
    bool Find(RestaurantNode x);

  private:
    int bucketSize;
};

#endif
