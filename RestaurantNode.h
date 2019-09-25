#ifndef RESTAURANTNODE_H
#define RESTAURANTNODE_H

#include <iostream>
#include <string>

class RestaurantNode {
  public:
    //Constructor
    RestaurantNode();
    RestaurantNode(std::string name, std::string priceRange, int rating);

    //Helper Functions
    void setName(std::string value);
    void setPriceRange(std::string value);
    void setRating(int value);

    std::string getName();
    std::string getPriceRange();
    int getRating();

  private:
    std::string name;
    std::string priceRange;
    int rating;
};

#endif
