#include <iostream>
#include <string>

#include "DoubleHash.h"
#include "RestaurantNode.h"

//Constructor & Deconstructor
DoubleHash::DoubleHash() {

}

DoubleHash::~DoubleHash() {

}

bool DoubleHash::Insert(std::string name, std::string rating, int priceRange) {
  RestaurantNode tempNode(name, rating, priceRange);
}

bool DoubleHash::Delete(RestaurantNode x) {

}

void DoubleHash::Print() {

}

int DoubleHash::HashFunction(RestaurantNode x) {

}

bool DoubleHash::Rehash() {

}

bool DoubleHash::Find(RestaurantNode x) {

}
