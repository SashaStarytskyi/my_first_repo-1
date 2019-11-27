#include <iostream>
#include "Labafive.h"

#define SIZE 5

using namespace std;



int main() {


 sortArrayByMerger inputted_vector[SIZE];

 inputArray(inputted_vector);
 cout << "Old :" << endl;
 showArray(inputted_vector);

 sortArray(inputted_vector);

 cout << "New :" << endl;
 showArray(inputted_vector);

 cout << endl << endl;

 arithmeticOfSort(inputted_vector);


 return 0;
}
