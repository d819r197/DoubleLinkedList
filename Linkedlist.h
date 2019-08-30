#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

class Linkedlist {
  public:
    Linkedlist();

    bool isEmpty();
    void insertNode(int value);
    bool deleteNode(int value);
    int smallest();
    int largest();
    int average();
    Linkedlist* mergeLists(Linkedlist newList);
    void printList();
    Linkedlist* reverseList();

  private:
    Node* head;
    int listSize;
};

#endif
