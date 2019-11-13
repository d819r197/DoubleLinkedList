#include <iostream>

#include "Node.h"

//Constructor
Node::Node(std::string value) {
  nodeValue = value;
}

//Helper Functions
std::string Node::getValue() {
  return(nodeValue);
}

void Node::setValue(std::string value) {
  nodeValue = value;
}

Node* Node::getNextNode() {
  return(nextNode);
}

void Node::setNextNode(Node* node) {
  nextNode = node;
}
