#include <iostream>

#include "RestaurantNode.h"

//Constructor
RestaurantNode::RestaurantNode() {
  name = "";
  priceRange = "";
  rating = 0;
}

RestaurantNode::RestaurantNode(std::string n, std::string pr, int r) {
  name = n;
  priceRange = pr;
  rating = r;
}

//Helper Functions
void RestaurantNode::setName(std::string value) {
    name = value;
}

void RestaurantNode::setPriceRange(std::string value) {
  priceRange = value;
}

void RestaurantNode::setRating(int value) {
  rating = value;
}

std::string RestaurantNode::getName() {
  return(name);
}

std::string RestaurantNode::getPriceRange() {
  return(priceRange);
}

int RestaurantNode::getRating() {
  return(rating);
}
