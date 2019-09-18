#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

class Node {
  public:
    //Constructor
    Node(std::string value);

    //Helper Functions
    void setValue(std::string value);
    std::string getValue();

    Node* getNextNode();
    void setNextNode(Node* node);

  private:
    std::string nodeValue;
    Node* nextNode;
};

#endif
