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
  std::cout << "No node was found, try again.\n";
  return (false);
}

int Linkedlist::smallest() {
  Node* tempNode = head;
  while(tempNode->getNextNode() != nullptr)
  {
    tempNode = tempNode->getNextNode();
  }
}

int Linkedlist::largest() {
  Node* tempNode = head;
  while(tempNode->getNextNode() != nullptr)
  {
    tempNode = tempNode->getNextNode();
  }
}

int Linkedlist::average() {
  Node* tempNode = head;
  while(tempNode->getNextNode() != nullptr)
  {
    tempNode = tempNode->getNextNode();
  }
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
