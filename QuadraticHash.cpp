#include <iostream>

#include "QuadraticHash.h"
#include "RestaurantNode.h"

//Constructor & Deconstructor
QuadraticHash::QuadraticHash() {

}

QuadraticHash::~QuadraticHash() {

}


bool QuadraticHash::Insert(std::string name, std::string rating, int priceRange) {
  RestaurantNode tempNode(name, rating, priceRange);
}

bool QuadraticHash::Delete(RestaurantNode x) {

}

void QuadraticHash::Print() {

}

int QuadraticHash::HashFunction(RestaurantNode x) {

}

bool QuadraticHash::Rehash() {

}

bool QuadraticHash::Find(RestaurantNode x) {

}
