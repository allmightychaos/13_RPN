#ifndef NODE_H
#define NODE_H

class Node {
private:
    double data;
    Node* next;

public:
    Node(double d);
    ~Node();
    friend class Calculator;
};

#endif
