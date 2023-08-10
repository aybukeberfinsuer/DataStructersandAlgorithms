#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include "Stack.hpp"

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
   Node* root;
    BinarySearchTree();
    ~BinarySearchTree();
    bool findElements(int findData,Node* active);
    void insert(int newData);
    void remove(int deleteData, Node* active);
    int maxElements(Node* node);
    void clearTree(Node* node);
    void PostOrder(Node* node);
    int getPostOrderSum(Node* node);
    Node* getRoot();
    void createFromStack(Stack* stack);
    int getSize() const;
    int getSizeHelper(Node* node) const;

};

#endif 