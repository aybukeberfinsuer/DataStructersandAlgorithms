#ifndef STACK_HPP
#define STACK_HPP

struct NodeStack {
    int data;
    NodeStack* next;

    NodeStack(int data) : data(data), next(nullptr) {}
};

class Stack {
public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    void push(int data);
    int pop();
    int peek() const;
    int size() const;
    void display() const;
    NodeStack* top;
};

#endif
