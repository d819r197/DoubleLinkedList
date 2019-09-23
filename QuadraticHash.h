#ifndef QUADRATICHASH_H
#define QUADRATICHASH_H

#include <iostream>
#include "RestaurantNode.h"

class QuadraticHash {
  public:
    //Constructor
    QuadraticHash();
    ~QuadraticHash();

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
