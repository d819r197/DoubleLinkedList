#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
  public:
    //Constructor
    Node(int value);

    //Helper Functions
    void setValue(int value);
    int getValue();

    Node* getNextNode();
    void setNextNode(Node* node);

    Node* getPrevNode();
    void setPrevNode(Node* node);

  private:
    int nodeValue;
    Node* nextNode;
    Node* prevNode;
};

#endif
