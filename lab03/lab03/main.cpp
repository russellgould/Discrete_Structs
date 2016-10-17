/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab3
SOURCES...: checkInput function from:
http://www.cplusplus.com/forum/general/103479/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string checkInput();
void matchSizes(vector<char> &num1, vector<char> &num2);

int main() {
  cout << "Enter First Binary Number: ";
  string str1 = checkInput();

  cout << "Enter Second Binary Number: ";
  string str2 = checkInput();

  vector<char> vec1(str1.begin(), str1.end());
  vector<char> vec2(str2.begin(), str2.end());

  matchSizes(vec1, vec2);

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
void matchSizes(vector<char> &num1, vector<char> &num2) {
  if (num1.size() != num2.size()) {
    string big, small;
    if (num1.size() > num2.size()) {
      size_t dif = num1.size() - num2.size();
      num2.insert(num2.begin(), dif, '0');
    }
    else {
      size_t dif = num2.size() - num1.size();
      num1.insert(num1.begin(), dif, '0');
    }
  }
}