#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "node.h"
#include <string>

class Calculator {
private:
    Node *first;
    void push(double d);
    double pop();

public:
    Calculator();
    ~Calculator();

    double calculate(std::string input);
};

#endif
