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
void matchSizes(string &bin1, string &bin2);

int main() {
  cout << "Enter First Binary Number: ";
  string bin1 = checkInput();

  cout << "Enter Second Binary Number: ";
  string bin2 = checkInput();

  matchSizes(bin1, bin2);

  cout << bin1 << " - " << bin1.size() << endl;
  cout << bin2 << " - " << bin2.size() << endl;

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
        cout << "Enter Valid Binary Number: ";
        break;
      }
    }
  } while (valid == false);

  return tempStr;
}

// left-fills the shorter binary number with 0's if str1 & str2 have different
// sizes
void matchSizes(string &bin1, string &bin2) {
  if (bin1.size() != bin2.size()) {
    string big, small;
    if (bin1.size() > bin2.size()) {
      size_t dif = bin1.size() - bin2.size();
      bin2.insert(0, dif, '0');
    } else {
      size_t dif = bin2.size() - bin1.size();
      bin1.insert(0, dif, '0');
    }
  }
}