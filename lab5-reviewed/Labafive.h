#pragma once
#include <iostream>
#define SIZE 5
using namespace std;

class sortArrayByMerger {
private:
 int arrayItself[SIZE];
public:

 friend void showArray(sortArrayByMerger workingArray[]);
 friend void sortArray(sortArrayByMerger workingArray[]);
 friend void inputArray(sortArrayByMerger workingArray[]);
 friend void arithmeticOfSort(sortArrayByMerger workingArray[]);
 friend void mergeArray(int& vector_pointer, int leng);
 

};
