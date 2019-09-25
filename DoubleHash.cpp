#include <iostream>
#include <string>

#include "DoubleHash.h"
#include "RestaurantNode.h"

//Constructor & Deconstructor
DoubleHash::DoubleHash() {
  bucketSize = 5;
  lamda = .80;
  table = new RestaurantNode[bucketSize];
    for(int lcv = 0; lcv < bucketSize; lcv++) {
      table[lcv].setName("");
    }
}

DoubleHash::~DoubleHash() {

}


bool DoubleHash::Insert(std::string name, std::string rating, int priceRange) {
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
        std::cout <<"Double Hashing: " <<name << " was added successfully at location: " <<tableLocation <<"\n";
        return(true);
      }
      else {
        int asciiValue = 0;
        for(int lcv = 0; lcv < name.size(); lcv++) {
          asciiValue += int(name[lcv]);
        }
        asciiValue = asciiValue % bucketSize;
        tableLocation = (tableLocation + (3 - (asciiValue % 3))) % bucketSize;

      }
    }
  }
  else {
    std::cout <<"Double Hashing: " <<name << " was not added successfully at location: " <<tableLocation <<"\n";
  }
  return(false);
}

bool DoubleHash::Delete(std::string name) {
  int tableLocation = 0;
  for(int lcv = 0; lcv<bucketSize; lcv++) {
    tableLocation = lcv;
    if(table[lcv].getName() == name) {
      RestaurantNode blankNode;
      table[lcv] = blankNode;
      std::cout <<"Double Hashing: " <<name << " was successfully deleted at location: " <<tableLocation <<"\n";
      return(true);
    }
  }
  std::cout <<"Double Hashing: " <<name << " was not successfully deleted at location: " <<tableLocation <<"\n";
  return(false);
}

void DoubleHash::Print() {
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    if(table[lcv].getName() == "") {
      std::cout << ".\n";
    }
    else {
      std::cout << lcv << ": " << table[lcv].getName() << " " << table[lcv].getRating() << " " << table[lcv].getPriceRange() <<std::endl;
    }
  }
}

void DoubleHash::ComputeLamda() {
  double numOfElements = 0;
  for(int lcv = 0; lcv<bucketSize; lcv++) {
    if(table[lcv].getName() != "") {
      numOfElements++;
    }
  }
  lamda = numOfElements / bucketSize;
}

int DoubleHash::HashFunction(std::string name) {
  int asciiValue = 0;
  for(int lcv = 0; lcv < name.size(); lcv++) {
    asciiValue += int(name[lcv]);
  }
  return(asciiValue % bucketSize);
}

int DoubleHash::NextPrime(int num) {
  for(int lcv = 2; lcv <= num/2; ++lcv)
  {
      if(num%lcv == 0)
      {
          return(num);
      }
  }
  return(NextPrime(num+1));
}

void DoubleHash::Rehash() {
  int newBucketSize = NextPrime(bucketSize*2);
  RestaurantNode* tempdTable = new RestaurantNode[newBucketSize];
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    tempdTable[HashFunction(table[lcv].getName())] = table[lcv];
  }
  table = tempdTable;
  bucketSize = newBucketSize;
  std::cout << "The Double Hash table has been rehashed!\n";

}

bool DoubleHash::Find(std::string restaurantName) {
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    if(table[lcv].getName() == restaurantName) {
      return(true);
    }
  }
  return(false);
}

//Helper Functions
void DoubleHash::setName(std::string value, int pos) {
    table[pos].setName(value);
}

void DoubleHash::setPriceRange(std::string value, int pos) {
  table[pos].setPriceRange(value);
}

void DoubleHash::setRating(int value, int pos) {
  table[pos].setRating(value);
}

std::string DoubleHash::getName(int pos) {
  return(table[pos].getName());
}

std::string DoubleHash::getPriceRange(int pos) {
  return(table[pos].getPriceRange());
}

int DoubleHash::getRating(int pos) {
  return(table[pos].getRating());
}

int DoubleHash::getBucketSize() {
  return(bucketSize);
}
