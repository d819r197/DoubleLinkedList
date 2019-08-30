#include <iostream>

#include "Node.h"

//Constructor
Node::Node(int value) {
  nodeValue = value;
}

//Helper Functions
int Node::getValue() {
  return(nodeValue);
}

void Node::setValue(int value) {
  nodeValue = value;
}

Node* Node::getNextNode() {
  return(nextNode);
}

void Node::setNextNode(Node* node) {
  nextNode = node;
}

Node* Node::getPrevNode() {
  return(prevNode);
}

void Node::setPrevNode(Node* node) {
  prevNode = node;
}
