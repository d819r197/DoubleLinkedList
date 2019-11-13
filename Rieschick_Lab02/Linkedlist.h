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
    void insertNode(std::string value);
    void insertNodeFront(std::string value);
    bool deleteNode(std::string value);
    bool find(std::string value);
    Node* at(int pos);
    void parseNewString(std::string input);
    bool merge2Lists(std::string listRaw);
    void printList();
    Linkedlist* reverseList();
    bool sortList();
    int size();

  private:
    Node* head;
    int listSize;
};

#endif
