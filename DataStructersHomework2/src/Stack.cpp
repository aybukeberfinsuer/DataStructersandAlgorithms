/** 
* @file main.cpp
* @description Programda oluşacak yığınların özel fonksiyonlarını içeren dosya.
* @course Yaz dönemi 1.öğretim A grubu - Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 09.08.2023
* @author Aybüke Berfin Süer  aybuke.suer@ogr.sakarya.edu.tr
*/
#include "Stack.hpp"
#include <iostream>

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::push(int data) {
    NodeStack* newNode = new NodeStack(data);
    if (top == nullptr) {
        top = newNode;
    } else {
        NodeStack* current = top;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int Stack::pop() {
    if (!isEmpty()) {
        if (top->next == nullptr) {
            int data = top->data;
            delete top;
            top = nullptr;
            return data;
        }
        NodeStack* current = top;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        int data = current->next->data;
        delete current->next;
        current->next = nullptr;
        return data;
    } else {
        return -1; 
    }
}


int Stack::peek() const {
    NodeStack* current=top;
    if (!isEmpty()) {
        while(current->next!=0){
            current=current->next;
        }
        return current->data;
    } 
    else {
        return -1; // You might want to handle this case appropriately.
    }
}
void Stack::display() const {
    NodeStack* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
int Stack::size() const {
    int count = 0;
    NodeStack* current = top;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
