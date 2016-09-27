/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab1
SOURCES...: None
*/

#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

int main() {

  array<string, 100> index = {0};
  string inFilePath = "";

  cout << "Enter input file path: ";
  cin >> inFilePath;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return 0;
}