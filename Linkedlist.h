#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

#include "Node.h"

class Linkedlist {
  public:
    Linkedlist();
    ~Linkedlist();

    bool isEmpty();
    void insertNode(int value);
    bool deleteNode(int value);
    int smallest();
    int largest();
    int average();
    void parseNewString(std::string input);
    Linkedlist* merge2Lists(std::string listRaw);
    void printList();
    Linkedlist* reverseList();

  private:
    Node* head;
    int listSize;
};

#endif
