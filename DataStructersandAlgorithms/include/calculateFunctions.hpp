#ifndef CALCULATE_FUNCTIONS_HPP
#define CALCULATE_FUNCTIONS_HPP
#include "LinkedList.hpp"

//Yazmış olduğum methodun imzaları
int findMaxElementCount(LinkedList** allTopLists, int counter);
void printElements(LinkedList** allTopLists,LinkedList** allBottomLists, int counter);
int findMaxElementCount(LinkedList** allLists, int size);
float calculateAverageOfSameIndexesForLists(LinkedList** allLists, int size);

#endif 
