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

  private:
    int nodeValue;
    Node* nextNode;
};

#endif
