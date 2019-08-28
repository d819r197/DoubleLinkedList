#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Linkedlist {
  public:
    Linkedlist();
  
    bool isEmpty();
    bool insertNode(int value);
    bool deleteNode(int value);
    int smallest();
    int largest();
    int average();
    Linkedlist* mergeLists(Linkedlist newList);
    void printList();
    LinkedList* reverseList();

  private:
    Linkedlist* list;
};

#endif
