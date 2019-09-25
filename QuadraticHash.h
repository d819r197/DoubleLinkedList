#ifndef QUADRATICHASH_H
#define QUADRATICHASH_H

#include <iostream>
#include <string>
#include "RestaurantNode.h"

class QuadraticHash {
  public:
    //Constructor
    QuadraticHash();
    ~QuadraticHash();

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
