/** 
* @file main.cpp
* @description Programın ana klasörüdür alacağımız çıktıların ve fonksiyonların çalıştırılamsı burada olacaktır.
* @course Yaz dönemi 1.öğretim A grubu - Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 09.08.2023
* @author Aybüke Berfin Süer  aybuke.suer@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include<windows.h>          
#include<unistd.h>         
#include "Stack.hpp"
#include "ListNode.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

int main() {
    ifstream inputFile("Sayilar3.txt");
    if (!inputFile) {
        cerr << "Dosya açılırken hata." << endl;
        return 1;
    }

    string line;
    ListNode* head = nullptr; // Bağlı listeyi başlatacak işaretçi
    ListNode* tail = nullptr; // Bağlı listenin son düğümünü tutacak işaretçi
    int numLines = 0; // Dosyadaki satır sayısını tutacak değişken
    while (getline(inputFile, line)) {
        numLines++;
        Stack* currentStack = new Stack(); // Yeni bir yığıt oluşturun
        ListNode* newNode = new ListNode(); // Yeni bir bağlı liste düğümü oluşturun
        BinarySearchTree* currentBst = new BinarySearchTree();
        newNode->stack = currentStack;
        newNode->next = nullptr;
        newNode->bst=currentBst;

        // Bağlı listeye düğümü ekleyin
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        // Satırı bir tamsayıya dönüştürün ve yığına ekleyin
        int value;
        bool control = false;
        istringstream iss(line);
        while (iss >> value) {
            if (control && (value % 2 == 0 && value > currentStack->peek())) {
                currentStack = new Stack(); // Yeni bir yığıt oluşturun
                currentBst = new BinarySearchTree();
                newNode = new ListNode(); // Yeni bir bağlı liste düğümü oluşturun
                newNode->stack = currentStack;
                newNode->next = nullptr;
                newNode->bst=currentBst;
                tail->next = newNode; // Yeni düğümü bağlı liste sonuna ekleyin
                tail = newNode; // Yeni düğümü son düğüm olarak ayarlayın
                control = false; // Kontrolü sıfırlayın
            }
            currentStack->push(value);
            control = true; // Kontrolü true olarak ayarlayın
        }


    ListNode* current = head;
    while (current != nullptr) {
        while(!current->stack->isEmpty()){
            int data= current->stack->pop();
            current->bst->insert(data);
        }        
        current = current->next;
    }
    delete current;
   
ListNode* maxTreeNode = nullptr;
BinarySearchTree* maxTree = nullptr;

ListNode* current2 = head;
while (current2 != nullptr) {
    if (maxTreeNode == nullptr || 
        (current2->bst != nullptr && maxTree != nullptr &&
         (current2->bst->getSize() > maxTree->getSize() || 
          (current2->bst->getSize() == maxTree->getSize() && 
           current2->bst->getPostOrderSum(current2->bst->getRoot()) >
               maxTree->getPostOrderSum(maxTree->getRoot()))))) {
        maxTreeNode = current2;
        maxTree = current2->bst;
    }
    current2 = current2->next;
}


if (maxTreeNode != nullptr) {
    maxTreeNode->bst->PostOrder(maxTreeNode->bst->getRoot());
    cout << endl;
} else {
    cout << "Herhangi bir ağaç bulunamadı." << endl;
}

    while (head != nullptr) {
        ListNode* nextNode = head->next;
        delete head->stack;
        delete head;
        head = nextNode;
    }
    head=nullptr;
   Sleep(10);
}

    // Rest of the code...
    
    inputFile.close();

    return 0;
}
