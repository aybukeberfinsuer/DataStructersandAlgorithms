#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Stack.hpp"

struct LinkedListNode {
    Stack* stack;
    LinkedListNode* next;

    LinkedListNode(Stack* stack) : stack(stack), next(nullptr) {}
};

class LinkedList {
private:
    LinkedListNode* head;

public:
    LinkedList();
    ~LinkedList();
    void insert(Stack* stack);
    void displayAll();
};

#endif
