#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include "LinkedList.hpp"
#include <iostream>

//Yazmış class'ın imzası
class FileReader {
public:
    static void readFile(const std::string& dosyaAdi, LinkedList**& allTopLists, LinkedList**& allBottomLists, int& counter);
};

#endif
