/** 
* @file calculateFunctions.cpp
* @description Programda gerekli olan fonksiyonlarım main.cpp'de kullanıcının rahat kullanıp anlayabilmesi için fazlalıktan kaçınması adına yazılmış olan hesaplamaların olduğu fonksiyon dosyasıdır.
* @course Yaz dönemi 1.öğretim A grubu - Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 23.07.2023
* @author Aybüke Berfin Süer  aybuke.suer@ogr.sakarya.edu.tr
*/

#include <cmath>
#include "calculateFunctions.hpp"

#include <iostream>
using namespace std;

int findMaxElementCount(LinkedList** allLists, int size) { //bağlı listelerdeki max eleman sayısının bulunması
    int maxElementCount = 0;
    for (int i = 0; i < size; i++) {
        int currentElementCount = allLists[i]->getLength();
        if (currentElementCount > maxElementCount) {
            maxElementCount = currentElementCount;
        }
    }
    return maxElementCount;
}


void printElements(LinkedList** allTopLists,LinkedList** allBottomLists, int counter){//Program çalışırken kontroler için elemanların ekrana yazılması için kullanılan fonksiyon, projenin son halinde kullanılmamıştır.Kontrol amaçlı veri göremk adına yazılmıştır.
    for (int i = 0; i < counter; i++) {
        cout << "Top List " << i + 1 << ": ";
        allTopLists[i]->show();

        cout << "Bottom List " << i + 1 << ": ";
        allBottomLists[i]->show();

        cout <<"-------"<< endl;
    }
 }
 //İstenen ortalamaların toplamını gerçekleştirmek için yazılmış fonksiyon. Aynı yöndeki bağlı listelerin boş olmayan aynı indisli elemanların ortalamasını bulup farklı indislerle olanların toplamıyla elde edilir.
 float calculateAverageOfSameIndexesForLists(LinkedList** allLists, int size) {
    int maxElementCount = findMaxElementCount(allLists, size);
    float totalSum = 0;
    int validListCount = 0;

    for (int i = 0; i < maxElementCount; i++) {
        float currentSum = 0;

        for (int j = 0; j < size; j++) {
            LinkedList* currentList = allLists[j];
            Node* currentNode = currentList->getHead();

            int k = 0;
            while (k < i && currentNode != nullptr) {
                currentNode = currentNode->next;
                k++;
            }

            if (currentNode != nullptr ) {
                currentSum += currentNode->data;
                validListCount++;
            }
        }

        if (validListCount > 0) {
            totalSum += (float)(currentSum) / validListCount;
        }
        validListCount = 0; 
    }
    return totalSum;
}