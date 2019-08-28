#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

class Linkedlist {
  public:
    Linkedlist();

    bool isEmpty();
    void insertNode(Node* node);
    bool deleteNode(Node* node);
    int smallest();
    int largest();
    int average();
    Linkedlist* mergeLists(Linkedlist newList);
    void printList();
    Linkedlist* reverseList();

  private:
    Node* tail;
};

#endif
