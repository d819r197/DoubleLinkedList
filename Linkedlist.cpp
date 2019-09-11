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
  Node* tempNode = head;
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
        delete tempNode;
        listSize--;
        return (true);
      }
    }
    tempNode = tempNode->getNextNode();
  }
  if(value == tempNode->getValue()) {
    Node* next = tempNode->getNextNode();
    if(tempNode->getValue() == head->getValue()) {
      head=next;
      delete tempNode;
      listSize--;
      return (true);
    }
    else {
      delete tempNode;
      listSize--;
      return (true);
    }
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

void Linkedlist::parseNewString(std::string input) {
  std::string strInt = "";
  for(int lcv = 0; lcv < input.size(); lcv++) {
    if(input[lcv] != ' ' && input[lcv] != '\n') {
      strInt += input[lcv];
    }
    else {
      insertNode(std::stoi(strInt));
      strInt = "";
    }
  }
  insertNode(std::stoi(strInt));
}

<<<<<<< HEAD
bool Linkedlist::sortList(bool isSorted, int pos) {
  if(!isEmpty()) {
    // if(!isSorted || firstCall) {
      Node* node = head;
      Nod    reverse->insertNode(node->getValue());
e* nextNode = head->getNextNode();
      int tempValue = node->getValue();
      for(int n = 0; n < listSize; n++) {
        // if(node->getNextNode() != nullptr && nextNode->getNextNode() != nullptr) {
        if(node->getNextNode() != nullptr) {
          if(tempValue > nextNode->getValue()) {
            // std::cout << "Swapping " << node->getValue() <<" and " <<nextNode->getValue() <<std::endl;
            tempValue = node->getValue();
            node->setValue(nextNode->getValue());
            if(nextNode != nullptr) {
              nextNode->setValue(tempValue);
=======
bool Linkedlist::sortList() {
  bool isSorted = false;
  while(!isSorted) {
    if(!isEmpty()) {
        isSorted = true;
        Node* node = head;
        Node* nextNode = head->getNextNode();
        int tempValue = node->getValue();
        for(int n = 0; n < listSize; n++) {
          if(node->getNextNode() != nullptr) {
            if(tempValue > nextNode->getValue()) {
              node->setValue(nextNode->getValue());
              if(nextNode != nullptr) {
                nextNode->setValue(tempValue);
              }
              isSorted = false;
>>>>>>> aeec20e9e4a78d7b756cdb593fa79187325b7e49
            }
            tempValue = nextNode->getValue();
            node = node->getNextNode();
            nextNode = nextNode->getNextNode();
          }
        }
<<<<<<< HEAD
      }

      // Node* node = head;
      // int currentVal = head->getValue();
      // while(node->getNextNode() != nullptr) {
      //   std::cout << "Comparing " << node->getValue() <<" and " <<(node->getNextNode())->getValue() <<std::endl;
      //   if(currentVal > (node->getNextNode())->getValue()) {
      //     std::cout << "Swapping " << node->getValue() <<" and " <<(node->getNextNode())->getValue() <<std::endl;
      //     node->setValue((node->getNextNode())->getValue());
      //     (node->getNextNode())->setValue(currentVal);
      //     currentVal = node->getValue();
      //     isSorted = false;
      //   }
      //   node = node->getNextNode();
      // }
    // }
  }
  else if    reverse->insertNode(node->getValue());
(isSorted) {
    return(true);
=======
        if(isSorted) {
          return(true);
        }
    }
    else {
      return(false);
    }
>>>>>>> aeec20e9e4a78d7b756cdb593fa79187325b7e49
  }
}

bool Linkedlist::merge2Lists(std::string listRaw) {
  parseNewString(listRaw);
  return(sortList());
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
  Node* node = head;
  Linkedlist* reverse = new Linkedlist;
  while(node->getNextNode() != nullptr) {
    reverse->insertNode(node->getValue());
    node = node->getNextNode();
  }
  reverse->insertNode(node->getValue());

  // for(int lcv = 0; lcv < listSize; lcv++) {
  //   node = node->getPrevNode();
  // }
  return (reverse);
}
