#ifndef LISTNODE_HPP
#define LISTNODE_HPP
#include "Stack.hpp"
#include "BinarySearchTree.hpp"

struct ListNode {
    Stack* stack; // Yığıtın adresini tutacak işaretçi
    ListNode* next; // Sonraki düğümün adresini tutacak işaretçi
    BinarySearchTree* bst;
};

#endif // LISTNODE_HPP
