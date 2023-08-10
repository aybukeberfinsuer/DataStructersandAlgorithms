/** 
* @file main.cpp
* @description Programda oluşan bağlı listelerin özel fonksiyonlarını içeren dosya.
* @course Yaz dönemi 1.öğretim A grubu - Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 09.08.2023
* @author Aybüke Berfin Süer  aybuke.suer@ogr.sakarya.edu.tr
*/
#include "LinkedList.hpp"
#include <iostream>
using namespace std;
struct LinkedListNode {
    Stack* stack;
    LinkedListNode* next;
    LinkedListNode(Stack* stack) : stack(stack), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insert(Stack* stack);
    void displayAll();
    LinkedListNode* head;
};

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(Stack* stack) {
    LinkedListNode* newNode = new LinkedListNode(stack);
    newNode->next = head;
    head = newNode;
}

void LinkedList::displayAll() {
    LinkedListNode* current = head;
    while (current != nullptr) {
        cout << "Yigit adresi: " << current->stack << endl;
        current = current->next;
    }
}