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
    bool merge2Lists(std::string listRaw);
    void printList();
    Linkedlist* reverseList();
    bool sortList();

  private:
    Node* head;
    int listSize;
};

#endif
