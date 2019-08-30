#include <iostream>

#include "Linkedlist.h"
#include "Node.h"

Linkedlist::Linkedlist() {
  head = nullptr;
  listSize = 0;
}

bool Linkedlist::isEmpty() {
  if(listSize == 0) {
    return(true);
  }
  else {
    return(false);
  }
}

void Linkedlist::insertNode(int value) {
  if(isEmpty()) {
    Node* tempNode = new Node(value);
    tempNode->setNextNode(nullptr);
    head = tempNode;
  }
  else {
    Node* tempNode = head;
    Node* tempNode2 = new Node(value);
    while(tempNode->getNextNode() != nullptr)
    {
      tempNode = tempNode->getNextNode();
    }
    tempNode->setNextNode(tempNode2);
    tempNode2->setNextNode(nullptr);
    tempNode2->setPrevNode(tempNode);
  }
  listSize++;
}

bool Linkedlist::deleteNode(int value) {
  Node* tempNode = head;
  while(tempNode->getNextNode() != nullptr)
  {
    if(value == tempNode->getValue()) {
      std::cout << "Node with value: " <<value <<" found!\n";
      Node* prev = tempNode->getPrevNode();
      Node* next = tempNode->getNextNode();
      std::cout << "Connecting node: " <<prev->getValue() <<" and " <<next->getValue() <<".\n";
        prev->setNextNode(next);
        delete tempNode;
        listSize--;
        return (true);
    }
    tempNode = tempNode->getNextNode();
  }
  return (false);
}

int Linkedlist::smallest() {
  Node* tempNode = head;
  int smallest = tempNode->getValue();
  while(tempNode->getNextNode() != nullptr) {
    if(tempNode->getValue() < smallest) {
      smallest = tempNode->getValue();
    }
    tempNode = tempNode->getNextNode();
  }
  if(tempNode->getValue() < smallest) {
    smallest = tempNode->getValue();
  }
  return(smallest);
}

int Linkedlist::largest() {
  Node* tempNode = head;
  int largest = tempNode->getValue();
  while(tempNode->getNextNode() != nullptr) {
    if(tempNode->getValue() > largest) {
      largest = tempNode->getValue();
    }
    tempNode = tempNode->getNextNode();
  }
  if(tempNode->getValue() > largest) {
    largest = tempNode->getValue();
  }
  return(largest);
}

int Linkedlist::average() {
  Node* tempNode = head;
  int sum = 0;
  while(tempNode->getNextNode() != nullptr) {
    sum += tempNode->getValue();
    tempNode = tempNode->getNextNode();
  }
  sum += tempNode->getValue();
  return(sum/listSize);
}

Linkedlist* Linkedlist::mergeLists(Linkedlist newList) {

}

void Linkedlist::printList() {
  if(isEmpty() == false) {
    std::cout << "List: ";
    Node* node = head;
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
