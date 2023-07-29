/** 
* @file main.cpp
* @description Programın ana klasörüdür alacağımız çıktıların ve fonksiyonların çalıştırılamsı burada olacaktır.
* @course Yaz dönemi 1.öğretim A grubu - Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 1.Ödev
* @date 23.07.2023
* @author Aybüke Berfin Süer  aybuke.suer@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "LinkedList.hpp"
#include "FileReader.hpp"
#include "calculateFunctions.hpp"
#include <cmath>

using namespace std;

int main() {
    int konumA = 0;
    int konumB = 0;
    int counter = 0; //bagli liste sayisi
    LinkedList** allTopLists; //ust listelerin adreslerini tutacak pointer dizisi
    LinkedList** allBottomLists; //alt listelerin adreslerini tutacak pointer dizisi

    FileReader::readFile("okunacak_dosya.txt", allTopLists, allBottomLists, counter);
    //Okunacak dosyayı parametre olarak girip listelerin oluşturulması

    cout << "Konum A: ";
    cin >> konumA;

    cout << "Konum B: ";
    cin >> konumB;

    // Kullanıcının girdiği değerlerin int olup olmadığını kontrol ediyoruz.
    if (cin.fail()) {
        cout << "Gecersiz index girdiniz. Lutfen sayi giriniz." << endl;
    } else if (konumA < 0 || konumA >= counter || konumB < 0 || konumB >= counter) {
        cout << "Gecersiz index.." << endl;
    } else {
        LinkedList* tempTopList = allTopLists[konumA];
        allTopLists[konumA] = allBottomLists[konumB];
        allBottomLists[konumB] = tempTopList;
        //Burada istenen ust ve alt indislerin yerlerini değiştiriyoruz.

        cout << "Konum A ve Konum B degerleri ile belirtilen bagli listeler yer degistirdi." << endl;
        cout<<endl;
        float totalAveragetop = calculateAverageOfSameIndexesForLists(allTopLists, counter); //istenen hesaplamanın yapılması
        totalAveragetop = totalAveragetop;
        cout << "Ust indislerin ortalamasi toplami: " << totalAveragetop << endl;

        float totalAveragebottom = calculateAverageOfSameIndexesForLists(allBottomLists, counter); //istenen hesaplamanın yapılması
        totalAveragebottom = totalAveragebottom;

        cout << "Alt indislerin ortalamasi toplami: " << totalAveragebottom << endl;
        cout<<endl;
    }

    //Bellekte ayrılan heap alanını serbest bırakma
    cout << "Bellek temizlendi." << endl;
    for (int i = 0; i < counter; i++) {
        delete allTopLists[i];
        delete allBottomLists[i];
    }
    delete[] allTopLists;
    delete[] allBottomLists;

    return 0;
}
