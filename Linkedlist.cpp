#include <iostream>

#include "Linkedlist.h"
#include "Node.h"

Linkedlist::Linkedlist() {
  head = nullptr;
  listSize = 0;
}

bool Linkedlist::isEmpty() {
  std::cout << "list size: " <<listSize <<std::endl;
  if(listSize == 0) {
    std::cout << "true\n";
    return(true);
  }
  else {
    std::cout << "false\n";
    return(false);
  }
}

void Linkedlist::insertNode(int value) {
  std::cout <<"inserting node...";
  Node* tempNode = new Node(value);

  if(isEmpty()) {
    std::cout << "Empty List\n";
    tempNode->setNextNode(nullptr);
    head = tempNode;
  }
  else {
    tempNode->setNextNode(head);
    head = tempNode;
  }

  listSize++;
  std::cout <<"node added.\n";
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
  std::cout << "Printing List.\n";
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
