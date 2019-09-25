#include <iostream>
#include <string>

#include "QuadraticHash.h"
#include "RestaurantNode.h"

//Constructor & Deconstructor
QuadraticHash::QuadraticHash() {
  bucketSize = 5;
  lamda = .80;
  table = new RestaurantNode[bucketSize];
    for(int lcv = 0; lcv < bucketSize; lcv++) {
      table[lcv].setName("");
    }
}

QuadraticHash::~QuadraticHash() {
}


bool QuadraticHash::Insert(std::string name, std::string rating, int priceRange) {
  ComputeLamda();
  if(lamda >= .5) {
    Rehash();
  }
  RestaurantNode tempNode(name, rating, priceRange);
  // std::cout << "Creating Node with Name: " <<tempNode.getName() << ", rating: " <<tempNode.getRating() <<", price range: " <<tempNode.getPriceRange() <<std::endl;
  int tableLocation = HashFunction(name);
  if(!Find(name)) {
    for(int lcv = 0; lcv < bucketSize/2; lcv++) {
      if(table[tableLocation].getName() == "") {
        table[tableLocation] = tempNode;
        std::cout <<"Quadratic Probing: " <<name << " was added successfully at location: " <<tableLocation <<"\n";
        return(true);
      }
      else {
        tableLocation = (tableLocation + (lcv * lcv)) % bucketSize;
      }
    }
  }
  else {
    std::cout <<"Quadratic Probing: " <<name << " was not added successfully at location: " <<tableLocation <<"\n";
  }
  return(false);
}

bool QuadraticHash::Delete(std::string name) {
  int tableLocation = 0;
  for(int lcv = 0; lcv<bucketSize; lcv++) {
    tableLocation = lcv;
    if(table[lcv].getName() == name) {
      RestaurantNode blankNode;
      table[lcv] = blankNode;
      std::cout <<"Quadratic Probing: " <<name << " was successfully deleted\n";
      return(true);
    }
  }
  std::cout <<"Quadratic Probing: " <<name << " was not successfully deleted\n";
  return(false);
}

void QuadraticHash::Print() {
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    if(table[lcv].getName() == "") {
      std::cout << ".\n";
    }
    else {
      std::cout << lcv << ": " << table[lcv].getName() << " " << table[lcv].getRating() << " " << table[lcv].getPriceRange() <<std::endl;
    }
  }
}

void QuadraticHash::ComputeLamda() {
  double numOfElements = 0;
  for(int lcv = 0; lcv<bucketSize; lcv++) {
    if(table[lcv].getName() != "") {
      numOfElements++;
    }
  }
  lamda = numOfElements / bucketSize;
}

int QuadraticHash::HashFunction(std::string name) {
  int asciiValue = 0;
  for(int lcv = 0; lcv < name.size(); lcv++) {
    asciiValue += int(name[lcv]);
  }
  return(asciiValue % bucketSize);
}

int QuadraticHash::NextPrime(int num) {
  for(int lcv = 2; lcv <= num/2; ++lcv)
  {
      if(num%lcv == 0)
      {
          return(num);
      }
  }
  return(NextPrime(num+1));
}

void QuadraticHash::Rehash() {
  int newBucketSize = NextPrime(bucketSize*2);
  RestaurantNode* tempqTable = new RestaurantNode[newBucketSize];
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    tempqTable[HashFunction(table[lcv].getName())] = table[lcv];
  }
  table = tempqTable;
  bucketSize = newBucketSize;
  std::cout << "The Quadratic Probing table has been rehashed!\n";
}

bool QuadraticHash::Find(std::string restaurantName) {
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    if(table[lcv].getName() == restaurantName) {
      return(true);
    }
  }
  return(false);
}

//Helper Functions
void QuadraticHash::setName(std::string value, int pos) {
    table[pos].setName(value);
}

void QuadraticHash::setPriceRange(std::string value, int pos) {
  table[pos].setPriceRange(value);
}

void QuadraticHash::setRating(int value, int pos) {
  table[pos].setRating(value);
}

std::string QuadraticHash::getName(int pos) {
  return(table[pos].getName());
}

std::string QuadraticHash::getPriceRange(int pos) {
  return(table[pos].getPriceRange());
}

int QuadraticHash::getRating(int pos) {
  return(table[pos].getRating());
}

int QuadraticHash::getBucketSize() {
  return(bucketSize);
}
