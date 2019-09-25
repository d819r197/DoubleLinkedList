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
    void Rehash();
    bool Find(std::string x);

    void setName(std::string value, int pos);
    void setPriceRange(std::string value, int pos);
    void setRating(int value, int pos);

    std::string getName(int pos);
    std::string getPriceRange(int pos);
    int getRating(int pos);
    int getBucketSize();

  private:
    int bucketSize;
    double lamda;
    RestaurantNode* table;
};

#endif
