#include <iostream>

#include "Hash.h"
#include "Linkedlist.h"

//Constructor
Hash::Hash() {
  bucketSize = 5;
  lamda = .80;
  table = new Linkedlist[bucketSize];
}

//Deconstructor
Hash::~Hash() {
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    // Linkedlist tempList = *table[lcv];
    // delete tempList;
    table[lcv].~Linkedlist();
  }
}

bool Hash::Insert(std::string x) {
  //If(hash.find(x) ! = true && all chars lowercase)
    //Then Insert X at head of list
      //Output: x was added successfully
      //Return true
    //Else
      //Output: x was not added successfully
      //Return false

    if(!Find(x)) {
      // table[HashFunction(x)].insertNodeFront(x);
      table[HashFunction(x)].insertNodeFront(x);  
      std::cout <<x << " was added successfully\n";
      return(true);
    }
    else {
      std::cout <<x << " was not added successfully\n";
      return(false);
    }
}

bool Hash::Delete(std::string x) {
  //If(!hash.find(x))
    //Output: x was not found
    //Return false
  //Else
    //Delete node with value x
    //Output: x was deleted
    //return true

  if(!Find(x)) {
    std::cout <<x << " was not found\n";
    return(false);
  }
  else {
    for(int lcv = 0; lcv < bucketSize; lcv++) {
      if(table[lcv].find(x)) {
        if(table[lcv].deleteNode(x)) {
          return(true);
        }
      }
    }
  }
  return(false);
}

void Hash::Print() {
  //For list in lists
    //print list with . between nodes
    for(int lcv = 0; lcv < bucketSize; lcv++) {
      std::cout << "Bucket " <<lcv <<": ";
      table[lcv].printList();
      std::cout<<std::endl;
    }

}

void Hash::ComputeLamda() {
  int numOfElements = 0;
  for(int lcv = 0; lcv<bucketSize; lcv++) {
    numOfElements += table[lcv].size();
  }
  lamda = numOfElements / bucketSize;
}

int Hash::HashFunction(std::string input) {
  ComputeLamda();
  if(lamda >= 1) {
    Rehash();
  }
  else {
    int asciiValue = 0;
    for(int lcv = 0; lcv < input.size(); lcv++) {
      asciiValue += int(input[lcv]);
    }
    return(asciiValue % bucketSize);
  }
return(HashFunction(input));
}

int Hash::NextPrime(int num) {
  for(int lcv = 2; lcv <= num/2; ++lcv)
  {
      if(num%lcv == 0)
      {
          return(num);
      }
  }
  return(NextPrime(num+1));
}

void Hash::Rehash() {
  int newBucketSize = NextPrime(bucketSize*2);
  Linkedlist* tempHashTable = new Linkedlist[newBucketSize];
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    tempHashTable[lcv] = table[lcv];
  }
  table = tempHashTable;
  bucketSize = newBucketSize;
  std::cout << "The table has been rehashed!\n";

}

bool Hash::Find(std::string x) {
  for(int lcv = 0; lcv < bucketSize; lcv++) {
    if(table[lcv].find(x)) {
      std::cout <<x <<" was found at location " << lcv <<std::endl;
      return(true);
    }
  }
  std::cout <<x <<" is not found.\n";
  return(false);
}
