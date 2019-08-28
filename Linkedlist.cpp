#include <iostream>

#include "Linkedlist.h"
#include "Node.h"

Linkedlist::Linkedlist() {
  tail = nullptr;
}

bool Linkedlist::isEmpty() {
  if(tail == nullptr) {
    std::cout<<"True\n";
    return(true);
  }
  else {
    std::cout<<"False\n";
    return(false);
  }
}

void Linkedlist::insertNode(Node* node) {
  //First Item
  std::cout<<"Checking if list is empty: ";
  if(isEmpty()) {
    std::cout << "Empty List\n";
    tail = node;
  }
  //More then 1 Item
  //Go through each node till nextPtr = nullptr
  else {
    std::cout << "Not Empty List\n";
    Node* newNode = node;
    while(node->getNextNode() != nullptr) {
      node = node->getNextNode();
    }
    node->setNextNode(newNode);
  }
}

bool Linkedlist::deleteNode(Node* node) {

}

int Linkedlist::smallest() {

}

int Linkedlist::largest() {

}

int Linkedlist::average() {

}

Linkedlist* Linkedlist::mergeLists(Linkedlist newList) {

}

void Linkedlist::printList() {
  Node* node = tail;
  if(!isEmpty()) {
    std::cout << "List: ";
    while(node->getNextNode() != nullptr) {
      std::cout << node->getValue() <<", ";
      node = node->getNextNode();
    }
    std::cout <<node->getValue() <<".\n";
  }
  else {
    std::cout << "Nothing to print. Empty List.\n";
  }

}

Linkedlist* Linkedlist::reverseList() {

}
