#include "Labafive.h"
void inputArray(sortArrayByMerger workingArray[]) {
 for (int rows = 0; rows < SIZE; rows++) {
  for (int columns = 0; columns < SIZE; columns++) {
   cout << "Input [" << (rows + 1) << "]" << "[" << (columns + 1) << "]: ";
   cin >> workingArray[rows].arrayItself[columns];
  }
 }
}

void showArray(sortArrayByMerger workingArray[]) {
 for (int rows = 0; rows < SIZE; rows++) {
  for (int columns = 0; columns < SIZE; columns++) {
   cout << "\t" << workingArray[rows].arrayItself[columns] << endl;
  }
 }
}

void mergeArray(int& vector_pointer, int leng) {
 int* workingArray = &vector_pointer;
 if (leng < 2) {
  return;
 }

 int* leftNumber = new int[leng / 2];
 int* rightNumber = new int[leng - leng / 2];

 for (int offsetLeft = 0; offsetLeft < leng / 2; offsetLeft++) {
  leftNumber[offsetLeft] = workingArray[offsetLeft];
 }
 for (int offsetRight = 0; offsetRight < leng - leng / 2; offsetRight++) {
  rightNumber[offsetRight] = workingArray[leng / 2 + offsetRight];
 }

 mergeArray(*leftNumber, leng / 2);
 mergeArray(*rightNumber, leng - leng / 2);


 int leftNumberСontinuation = 0, rightNumberСontinuation = 0;
 for (int rows = 0; rows < leng; rows++) {
  if (leftNumberСontinuation >= leng / 2) {
   workingArray[rows] = rightNumber[rightNumberСontinuation];
   rightNumberСontinuation++;
   continue;
  }
  if (rightNumberСontinuation >= leng - leng / 2) {
   workingArray[rows] = leftNumber[leftNumberСontinuation];
   leftNumberСontinuation++;
   continue;
  }
  if (leftNumber[leftNumberСontinuation] < rightNumber[rightNumberСontinuation]) {
   workingArray[rows] = leftNumber[leftNumberСontinuation];
   leftNumberСontinuation++;
  }
  else {
   workingArray[rows] = rightNumber[rightNumberСontinuation];
   rightNumberСontinuation++;
  }
 }

 delete[] leftNumber;
 delete[] rightNumber;
}
void sortArray(sortArrayByMerger workingArray[]) {
 for (int rows = 0; rows < SIZE; rows++) {
  int column[SIZE] = { 0 };
  for (int offsetRight = 0; offsetRight < SIZE; offsetRight++) {
   column[offsetRight] = workingArray[offsetRight].arrayItself[rows];
  }
  mergeArray(*column, SIZE);
  for (int offsetRight = 0; offsetRight < SIZE; offsetRight++) {
   workingArray[offsetRight].arrayItself[rows] = column[offsetRight];
  }
 }
}


void arithmeticOfSort(sortArrayByMerger workingArray[]) {
 float GeometricMeanOfTheRow = 0, sum = 0;
 int f[] = { 1,1,1,1,1 };
 for (int rows = 0; rows < SIZE; rows++) {
  for (int columns = rows; columns < SIZE; columns++) {
   f[rows] *= workingArray[rows].arrayItself[columns];

  }
  cout << endl << "f[" << rows << "]=" << sqrt(sqrt(abs(f[rows])));


  GeometricMeanOfTheRow += sqrt(sqrt(abs(f[rows])));
 }

 cout << "\n" << "F = " << GeometricMeanOfTheRow << endl;

}
