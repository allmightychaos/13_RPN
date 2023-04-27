#include <stdexcept>

#include "calculator.h"
#include "node.h"

void Calculator::push(double d) {
    Node* new_node = new Node(d);
    new_node->next = first;
    first = new_node;
}

double Calculator::pop() {
    if (first == nullptr) {
        throw std::logic_error("Empty stack!");
    }
    double d = first->data;
    Node* tmp = first;
    first = first->next;
    delete tmp;
    return d;
}

Calculator::Calculator() {
    first = nullptr;
}

Calculator::~Calculator() {
    while (first != nullptr) {
        Node* tmp = first;
        first = first->next;
        delete tmp;
    }
}

double Calculator::calculate(std::string input) {
    std::string part;
    size_t pos;
    while (input.size() > 0) {
        if (input[0] == ' ') {
            input.erase(0, 1);
            continue;
        }
        pos = input.find_first_of(' ');
        if (pos == std::string::npos) {
            part = input;
            input.clear();
        } else {
            part = input.substr(0, pos);
            input.erase(0, pos+1);
        }
        if (part.length() == 1 && (part[0] == '*' || part[0] == '+' || part[0] == '-')) {
            double op2 = pop();
            double op1 = pop();
            switch (part[0]) {
                case '*':
                    push(op1 * op2);
                    break;
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
            }
        } else {
            push(stod(part));
        }
    }
    return pop();
}
