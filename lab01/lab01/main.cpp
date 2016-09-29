/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab1
SOURCES...: None
*/

#include <array>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int I_SIZE = 500; // size of word index

void inputWordToIndex(array<string, I_SIZE> &index, string word, int &iSize);
void bubbleSort(array<string, I_SIZE> &index, int iSize);
void printIndex(array<string, I_SIZE> &index, int iSize);

int main() {
  array<string, I_SIZE> index;
  string inFilePath = "", wordBuf = "";
  ifstream inFile;
  int iSize(0);
  for (size_t i(0); i < I_SIZE; i++) {
    index[i] = "";
  }
  cout << "Enter input file path: ";
  getline(cin, inFilePath);
  inFile.open(inFilePath.c_str());
  while (!inFile.good()) {
    cout << "Couldn't open that file. Try another: ";
    getline(cin, inFilePath);
    inFile.open(inFilePath.c_str());
  }
  while (!inFile.eof()) {
    inFile >> wordBuf;
    inputWordToIndex(index, wordBuf, iSize);
  }
  bubbleSort(index, iSize);
  printIndex(index, iSize);
  return 0;
}

// utilizes a sequential search to input a single word to index,
// returns true if input is successful
void inputWordToIndex(array<string, I_SIZE> &index, string word, int &iSize) {
  bool found(0);
  if (iSize == 0) {
    index[0] = word;
    iSize++;
  } else {
    for (size_t i = 0; i < iSize && !found; i++) {
      if (index[i] == word) {
        found = true;
      }
    }
    if (!found) {
      index[iSize] = word;
      iSize++;
    }
  }
}

void bubbleSort(array<string, I_SIZE> &index, int iSize) {
  bool sorted(0);
  int pass(1);
  while (!sorted && pass < iSize) {
    sorted = true;
    for (int i(0); i < iSize - pass; i++) {
      int nextI(i + 1);
      if (index[i] > index[nextI]) {
        swap(index[i], index[nextI]);
        sorted = false;
      }
    }
    pass++;
  }
}

void printIndex(array<string, I_SIZE> &index, int iSize) {
  cout << endl << "Words in the file:" << endl;
  for (size_t i(0); i < iSize; i++) {
    cout << index[i] << endl;
  }
}