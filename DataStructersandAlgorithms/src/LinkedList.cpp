/** 
* @file LinkedList.cpp
* @description Bu dosyada Tek yönlü bağlı listelerin yapıcı ve yıkıcı methodlarının yer aldığı ve ekstra kullanılacak fonksiyonların yer aldığı dosyadır
* @course Yaz dönemi 1.öğretim A grubu - Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 23.07.2023
* @author Aybüke Berfin Süer  aybuke.suer@ogr.sakarya.edu.tr
*/
#include "LinkedList.hpp"
#include <iostream>
using namespace std;

//Bağlı listedeki elemanların düğüm yapısı
Node::Node(int value) { 
    data = value;
    next = nullptr;
}

//Bağlı listelerin oluşumunda değer atanmadan önce default değer atama
LinkedList::LinkedList() { 
    head = nullptr;
}

// Bağlı listeler için yok edici method
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

//Dosyadan okunacak verileri (bkz FileReader.cpp) tek yönlü bağlı liste yapmak için yazılan fonkisyon
void LinkedList::insert(int value) { 
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//İlk elemanı almak için yazmış olduğum bir method
Node* LinkedList::getHead() {
    return head;
}

//Bu fonksiyon aranan düğümün adres kontrolünde kullanılır.
bool LinkedList::isEmptyIndex(Node* node) {
    if(node == nullptr){
        return true;
    }
    else return false;
}

//Bağlı listelerin uzunluğunu bulmak için yazılmış bir method
int LinkedList::getLength() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

//Programda aktif olarak kullanılmıyor. Kontrol amaçlı yazılmış olup listelerin doğruluğuna bakmak içindir. Dileyen kullanıcının incelemesi için bu methodu kullanabilir.
void LinkedList::show() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


//Bağlı listenein ilk elemanını görmek için yazılmış bir method
void LinkedList::displayFirstElement() {
    if (head == nullptr) {
        cout << "Liste bos!" << endl;
        return;
    }  
    cout << "Ilk eleman: " << head->data << endl;
}

