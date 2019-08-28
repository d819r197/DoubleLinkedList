//Constructor
Node::Node(int value) {
  nodeValue = value;
}

//Helper Functions
void setValue(int value) {
  nodeValue = value;
}

int getValue() {
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
