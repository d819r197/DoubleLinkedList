#include <iostream>

#include "Linkedlist.h"
#include "Node.h"

Linkedlist::Linkedlist() {
  head = nullptr;
  listSize = 0;
}

Linkedlist::~Linkedlist() {
  while(!isEmpty()) {
    deleteNode(head->getValue());
  }
}

bool Linkedlist::isEmpty() {
  if(listSize == 0 || head == nullptr) {
    return(true);
  }
  else {
    return(false);
  }
}

void Linkedlist::insertNode(std::string value) {
  if(!find(value)) {
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
}


void Linkedlist::insertNodeFront(std::string value) {
  if(!find(value)) {
    if(isEmpty()) {
      insertNode(value);
    }
    else {
      Node* oldFirst = head;
      Node* newFirst = new Node(value);
      Node* second = oldFirst->getNextNode();

      head = newFirst;
      newFirst->setNextNode(oldFirst);
      oldFirst->setNextNode(second);
    }
    listSize++;
  }
}

bool Linkedlist::deleteNode(std::string value) {
  Node* tempNode = head;
  Node* prevNode = nullptr;
  int nodePos = 1;

  if(isEmpty()) {
    return(false);
  }
  while(tempNode->getNextNode() != nullptr)
  {
    if(value == tempNode->getValue()) {
      Node* next = tempNode->getNextNode();
      if(tempNode == head) {
        head=next;
        delete tempNode;
        listSize--;
        return (true);
      }
      else {
        prevNode = at(nodePos-1);
        prevNode->setNextNode(tempNode->getNextNode());
        delete tempNode;
        listSize--;
        return (true);
      }
    }
    tempNode = tempNode->getNextNode();
    nodePos++;
  }
  if(value == tempNode->getValue()) {
    Node* next = tempNode->getNextNode();
    nodePos++;
    if(tempNode->getValue() == head->getValue()) {
      head=next;
      delete tempNode;
      listSize--;
      return (true);
    }
    else {
      prevNode = at(nodePos-1);
      prevNode->setNextNode(tempNode->getNextNode());
      delete tempNode;
      listSize--;
      return (true);
    }
  }
  return (false);
}

bool Linkedlist::find(std::string value) {
  Node* tempNode = head;
  if(!isEmpty()) {
    if(listSize == 1) {
      if(tempNode->getValue() == value) {
        return(true);
      }
      else {
        return(false);
      }
    }
    else {
      while(tempNode->getNextNode() != nullptr) {
        if(value == tempNode->getValue()) {
          return(true);
        }
        tempNode = tempNode->getNextNode();
      }
      if(value == tempNode->getValue()) {
        return(true);
      }
    }
  }
  return(false);
}

Node* Linkedlist::at(int pos) {
  Node* tempNode = head;
  if(pos < listSize) {
    for(int lcv = 1; lcv < pos; lcv++) {
      if(tempNode->getNextNode() != nullptr) {
        tempNode = tempNode->getNextNode();
      }
    }
  }
  return(tempNode);
}


void Linkedlist::parseNewString(std::string input) {
  std::string strInt = "";
  for(int lcv = 0; lcv < input.size(); lcv++) {
    if(input[lcv] != ' ' && input[lcv] != '\n') {
      strInt += input[lcv];
    }
    else {
      insertNode(strInt);
      strInt = "";
    }
  }
  insertNode(strInt);
}

bool Linkedlist::sortList() {
  bool isSorted = false;
  while(!isSorted) {
    if(!isEmpty()) {
        isSorted = true;
        Node* node = head;
        Node* nextNode = head->getNextNode();
        std::string tempValue = node->getValue();
        for(int n = 0; n < listSize; n++) {
          if(node->getNextNode() != nullptr) {
            if(tempValue > nextNode->getValue()) {
              node->setValue(nextNode->getValue());
              if(nextNode != nullptr) {
                nextNode->setValue(tempValue);
              }
              isSorted = false;
            }
            tempValue = nextNode->getValue();
            node = node->getNextNode();
            nextNode = nextNode->getNextNode();
          }
        }
        if(isSorted) {
          return(true);
        }
    }
    else {
      return(false);
    }
  }
  return(false);
}

bool Linkedlist::merge2Lists(std::string listRaw) {
  parseNewString(listRaw);
  return(sortList());
}

void Linkedlist::printList() {
  if(isEmpty() == false) {
    std::cout << "-> ";
    Node* node = head;
    while(node->getNextNode() != nullptr) {
      std::cout << node->getValue() <<" -> ";
      node = node->getNextNode();
    }
    std::cout <<node->getValue();
  }
}

Linkedlist* Linkedlist::reverseList() {
  Node* node = head;
  Linkedlist* reverse = new Linkedlist;
  while(node->getNextNode() != nullptr) {
    reverse->insertNodeFront(node->getValue());
    node = node->getNextNode();
  }
  reverse->insertNodeFront(node->getValue());
  return (reverse);
}

int Linkedlist::size() {
  return(listSize);
}
