/** 
* @file main.cpp
* @description Programın ikili arama ağaçları için hazırladığım özel fonksiyonlarını içerend dosya.
* @course Yaz dönemi 1.öğretim A grubu - Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 09.08.2023
* @author Aybüke Berfin Süer  aybuke.suer@ogr.sakarya.edu.tr
*/
#include "BinarySearchTree.hpp"
#include <algorithm>
#include <iostream>
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clearTree(root);
}

bool BinarySearchTree::findElements(int findData,Node* active) {
    if(active->data<findData){
        if(active->right){
            return findElements(findData,active->right);
        }
        return false;
    }
    else if(active->data>findData){
        if(active->left){
            return findElements(findData,active->left);
        }
        return false;
    }
    else return true;
};

void BinarySearchTree::insert(int newData) {
    if (root == nullptr) {
        root = new Node(newData);
    } else {
        Node* currentNode = root;
        while (true) {
            if (newData < currentNode->data) {
                if (currentNode->left) {
                    currentNode = currentNode->left;
                } else {
                    currentNode->left = new Node(newData);
                    break;
                }
            } else if (newData > currentNode->data) {
                if (currentNode->right) {
                    currentNode = currentNode->right;
                } else {
                    currentNode->right = new Node(newData);
                    break;
                }
            } else {
                // Değer zaten ağaçta var, ekleme işlemi yapılmayacak.
                break;
            }
        }
    }
}

void BinarySearchTree::remove(int deleteData, Node* active) {
    Node* parentNode = nullptr;
    Node* currentNode = root;

    // Silinecek düğümü ve üst düğümünü bulana kadar dolaşın
    while (currentNode != nullptr && currentNode->data != deleteData) {
        parentNode = currentNode;
        if (deleteData < currentNode->data) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    // Silinecek düğümü bulamadıysak fonksiyonu sonlandırın
    if (currentNode == nullptr) {
        return;
    }

    // Silinecek düğümün çocuk düğümleri olup olmadığını kontrol edin
    bool hasLeftChild = (currentNode->left != nullptr);
    bool hasRightChild = (currentNode->right != nullptr);

    // Duruma göre silme işlemini gerçekleştirin
    if (!hasLeftChild && !hasRightChild) {
        // Silinecek düğümün her iki çocuğu yoksa (yaprak düğüm), düğümü doğrudan silin.
        if (parentNode == nullptr) {
            root = nullptr;
        } else if (parentNode->left == currentNode) {
            parentNode->left = nullptr;
        } else {
            parentNode->right = nullptr;
        }
        delete currentNode;
    } else if (hasLeftChild && !hasRightChild) {
        // Silinecek düğümün sadece sol çocuğu varsa, sol çocuğunu mevcut düğümle değiştirin.
        if (parentNode == nullptr) {
            root = currentNode->left;
        } else if (parentNode->left == currentNode) {
            parentNode->left = currentNode->left;
        } else {
            parentNode->right = currentNode->left;
        }
        delete currentNode;
    } else if (!hasLeftChild && hasRightChild) {
        // Silinecek düğümün sadece sağ çocuğu varsa, sağ çocuğunu mevcut düğümle değiştirin.
        if (parentNode == nullptr) {
            root = currentNode->right;
        } else if (parentNode->left == currentNode) {
            parentNode->left = currentNode->right;
        } else {
            parentNode->right = currentNode->right;
        }
        delete currentNode;
    } else {
        // Silinecek düğümün hem sol hem de sağ çocuğu varsa,
        // silinecek düğümün inorder successor'ını (en küçük sağ alt ağaç düğümü) bulun.
        Node* successor = currentNode->right;
        Node* parentOfSuccessor = currentNode;

        while (successor->left != nullptr) {
            parentOfSuccessor = successor;
            successor = successor->left;
        }

        // Inorder successor'u bulduk. Bu düğümü silinecek düğümle değiştirin.
        currentNode->data = successor->data;

        // Inorder successor'ın ebeveyninin sol veya sağ çocuğunu güncelleyin.
        if (parentOfSuccessor->left == successor) {
            parentOfSuccessor->left = successor->right;
        } else {
            parentOfSuccessor->right = successor->right;
        }
        delete successor;
    }
};

int BinarySearchTree::maxElements(Node* node){
    if(node->right){
        return maxElements(node->right);
    }
    return node->data;
};

void BinarySearchTree::clearTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}
void BinarySearchTree::PostOrder(Node* node) {
    if (node) {
        PostOrder(node->left);
        PostOrder(node->right);
    std::cout << static_cast<char>(node->data) << " ";
    }
}


int BinarySearchTree::getPostOrderSum(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftSum = getPostOrderSum(node->left);
    int rightSum = getPostOrderSum(node->right);

    return node->data + leftSum + rightSum;
}
Node* BinarySearchTree::getRoot() {
    return root;
};

void BinarySearchTree::createFromStack(Stack* stack) {
    while (!stack->isEmpty()) {
        insert(stack->pop());
    }
}

int BinarySearchTree::getSize() const {
    return getSizeHelper(root);
}
int BinarySearchTree::getSizeHelper(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + getSizeHelper(node->left) + getSizeHelper(node->right);
}