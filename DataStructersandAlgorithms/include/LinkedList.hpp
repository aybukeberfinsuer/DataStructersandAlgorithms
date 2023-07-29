#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class Node {
public:
    int data;
    Node* next;  
    Node(int value);
};


class LinkedList {
private:
    Node* head;
    void displayBottomRecursive(Node* node);

public:
    LinkedList();
    ~LinkedList();    
    void insert(int value);
    void show();  
    Node* getHead();
    bool isEmptyList();
    bool isEmptyIndex(Node* node);
    int getLength();
    void displayFirstElement();
};

#endif
