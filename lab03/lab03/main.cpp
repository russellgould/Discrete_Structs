/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab3
SOURCES...: checkInput function from:
http://www.cplusplus.com/forum/general/103479/
*/

#include <iostream>
#include <string>
using namespace std;

string checkInput();

int main() {
  cout << "Enter First Binary Number: ";
  string binaryString1 = checkInput();

  cout << "Enter Second Binary Number: ";
  string binaryString2 = checkInput();

  return 0;
}

string checkInput() {
  bool valid = true;
  string tempStr;

  do {
    valid = true;
    getline(cin, tempStr);
    for (int i = 0; i < tempStr.length(); i++) {
      if ((tempStr.compare(i, 1, "0") != 0) &&
          (tempStr.compare(i, 1, "1") != 0)) {
        valid = false;
        std::cout << "Enter Valid Binary Number: ";
        break;
      }
    }
  } while (valid == false);

  return tempStr;
}
