/** 
* @file FileReader.cpp
* @description Dosya okuma ve düğümlere değer ataması için yazılmış olan dosyadır.
* @course Yaz dönemi 1.öğretim A grubu - Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 23.07.2023
* @author Aybüke Berdin Süer  aybuke.suer@ogr.sakarya.edu.tr
*/
#include "FileReader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void FileReader::readFile(const string& dosyaAdi, LinkedList**& allTopLists, LinkedList**& allBottomLists, int& counter) {
    ifstream file(dosyaAdi); //Dosyanın okunmasında oluşacak herhangi bir sorun için kontrol
    if (!file) {
        cout << "Dosya acilamadi!" << endl;
        exit(1);
    }
    // Başlangıçta kapasiteyi belirtiyoruz fakat duruma göre bu kapasiteyi artırıyoruz ve en sonunda mutlaka bellekten tuttuğumuz yerleri yok ediyoruz.
    int currentCapacity = 10; 
    allTopLists = new LinkedList*[currentCapacity];
    allBottomLists = new LinkedList*[currentCapacity];
    counter = 0;

    string line;
    while (getline(file, line)) {
        LinkedList* topList = new LinkedList(); // Her bir satır için yeni bir  üst bağlı liste oluştur.
        LinkedList* bottomList = new LinkedList();// Her bir satır için yeni bir alt bağlı liste oluştur.
        bool control=false;
        istringstream iss(line);
        int num;
        
        while (iss >> num) {
            if (num >= 10 && num <= 99) {
                int ones = num % 10;     // Birler basamağındaki rakam
                int tens = num / 10;     // Onlar basamağındaki rakam

           // Onlar basamağındaki rakamlar üst bağlı listeye birler ise alt bağlı listeye eklenir.
                topList->insert(tens);
                bottomList->insert(ones);
                control=true;
            }
        }

       if (control)
       {
         if (counter >= currentCapacity) {
            int newCapacity = currentCapacity * 2; //yukarıda bahsetmiş olduğumuz kapasite taşması durumunda hafızadan daha fazla yer açılması gerekmektedir
            LinkedList** newTopLists = new LinkedList*[newCapacity];
            LinkedList** newBottomLists = new LinkedList*[newCapacity];

            for (int i = 0; i < counter; i++) {
                newTopLists[i] = allTopLists[i];
                newBottomLists[i] = allBottomLists[i];
            }

            delete[] allTopLists;
            delete[] allBottomLists;

            allTopLists = newTopLists;
            allBottomLists = newBottomLists;
            currentCapacity = newCapacity;
        }

        allTopLists[counter] = topList; // Yeni bağlı listeyi allTopLists dizisine atamak
        allBottomLists[counter] = bottomList; // Yeni bağlı listeyi allBottomLists dizisine atamak
        counter++;
       }
    }

    file.close();
}


