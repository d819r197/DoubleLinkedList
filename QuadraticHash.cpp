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
  for(int lcv = 0; lcv<bucketSize; lcv++) {
    if(table[lcv].getName() == name) {
      RestaurantNode blankNode;
      table[lcv] = blankNode;
      return(true);
    }
  }
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
  int numOfElements = 0;
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

bool QuadraticHash::Rehash() {
  int newBucketSize = NextPrime(bucketSize*2);
  RestaurantNode* tempqTable = new RestaurantNode[newBucketSize];
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    tempqTable[HashFunction(table[lcv].getName())] = table[lcv];
  }
  table = tempqTable;
  bucketSize = newBucketSize;
  std::cout << "The Quadratic Probing table has been rehashed!\n";
  return(true);
}

bool QuadraticHash::Find(std::string restaurantName) {
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    if(table[lcv].getName() == restaurantName) {
      return(true);
    }
  }
  return(false);
}
