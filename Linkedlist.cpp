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
  }
  listSize++;
}

bool Linkedlist::deleteNode(int value) {

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
