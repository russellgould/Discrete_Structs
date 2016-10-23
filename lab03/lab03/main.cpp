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
void fixSizes(vector<char> &num1, vector<char> &num2);
vector<int> makeInts(vector<char> num);
void halfAdder(bool P, bool Q, bool &sum, bool &carry);
void fullAdder(bool P, bool Q, bool R, bool &sum, bool &carryOut);
void addBins(vector<int> num1, vector<int> num2, vector<int> &result);
void printVec(vector<int> vec);
void printCarry(int pos);
void printNums(vector<int> num1, vector<int> num2);
void printStep(vector<int> num1, vector<int> num2, vector<int> result,
               bool carry, int carryPos);

int main() {
  cout << "To enter binary numbers, just enter up to eight 1's and 0's" << endl;
  for (size_t i = 0; i < 4; i++) {
    cout << "Enter First Binary Number: ";
    string str1 = checkInput();

    cout << "Enter Second Binary Number: ";
    string str2 = checkInput();

    vector<char> temp1(str1.begin(), str1.end());
    vector<char> temp2(str2.begin(), str2.end());

    fixSizes(temp1, temp2);
    vector<int> vec1 = makeInts(temp1);
    vector<int> vec2 = makeInts(temp2);
    vector<int> result(8, 0);
    cout << endl;

    addBins(vec1, vec2, result);

    cout << endl << "Final result is:" << endl << endl;
    printNums(vec1, vec2);
    printVec(result);
    cout << endl;
  }

  return 0;
}

string checkInput() {
  bool valid = true;
  string tempStr;

  do {
    valid = true;
    getline(cin, tempStr);
    for (size_t i = 0; i < tempStr.length(); i++) {
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
void fixSizes(vector<char> &num1, vector<char> &num2) {
  if (num1.size() < 8) {
    num1.insert(num1.begin(), 8 - num1.size(), '0');
  }
  if (num2.size() < 8) {
    num2.insert(num2.begin(), 8 - num2.size(), '0');
  }
}

// converts vector<char> to vector<int> to simplify comparisons/addition
vector<int> makeInts(vector<char> num) {
  vector<int> result(num.size());
  for (size_t i = 0; i < num.size(); i++) {
    if (num[i] == '0') {
      result[i] = 0;
    } else {
      result[i] = 1;
    }
  }
  return result;
}

void halfAdder(bool P, bool Q, bool &sum, bool &carry) {
  sum = P ^ Q;
  carry = P && Q;
}

void fullAdder(bool P, bool Q, bool R, bool &sum, bool &carryOut) {
  bool C1(0), S1(0), C2(0);
  halfAdder(P, Q, S1, C1);
  halfAdder(S1, R, sum, C2);
  carryOut = C1 || C2;
}

void addBins(vector<int> num1, vector<int> num2, vector<int> &result) {
  printNums(num1, num2);
  bool S1 = 0, C1 = 0;
  halfAdder(num1[7], num2[7], S1, C1);
  result[7] = S1;

  printStep(num1, num2, result, C1, 7);

  bool S2 = 0, C2 = 0;
  fullAdder(num1[6], num2[6], C1, S2, C2);
  result[6] = S2;

  printStep(num1, num2, result, C2, 6);

  bool S3 = 0, C3 = 0;
  fullAdder(num1[5], num2[5], C2, S3, C3);
  result[5] = S3;

  printStep(num1, num2, result, C3, 5);

  bool S4 = 0, C4 = 0;
  fullAdder(num1[4], num2[4], C3, S4, C4);
  result[4] = S4;

  printStep(num1, num2, result, C4, 4);

  bool S5 = 0, C5 = 0;
  fullAdder(num1[3], num2[3], C4, S5, C5);
  result[3] = S5;

  printStep(num1, num2, result, C5, 3);

  bool S6 = 0, C6 = 0;
  fullAdder(num1[2], num2[2], C5, S6, C6);
  result[2] = S6;

  printStep(num1, num2, result, C6, 2);

  bool S7 = 0, C7 = 0;
  fullAdder(num1[1], num2[1], C6, S7, C7);
  result[1] = S7;

  printStep(num1, num2, result, C7, 1);

  bool S8 = 0, C8 = 0;
  fullAdder(num1[0], num2[0], C7, S8, C8);
  result[0] = S8;

  printStep(num1, num2, result, 0, 0);
  printVec(result);
}

void printVec(vector<int> vec) {
  for (size_t i = 0; i < 8; i++) {
    if (i == 4) {
      cout << " ";
    }
    cout << vec[i];
  }
  cout << endl;
}

void printCarry(int pos) {
  if (pos > 4) {
    for (size_t i = 0; i < pos + 1; i++) {
      cout << " ";
    }
  } else {
    for (size_t i = 0; i < pos; i++) {
      cout << " ";
    }
  }
  cout << "1" << endl;
}

void printNums(vector<int> num1, vector<int> num2) {
  cout << " ";
  printVec(num1);
  cout << "+";
  printVec(num2);
  cout << "----------" << endl << " ";
}

void printStep(vector<int> num1, vector<int> num2, vector<int> result,
               bool carry, int carryPos) {
  printVec(result);
  cout << endl;
  if (carry) {
    printCarry(carryPos);
  }
  printNums(num1, num2);
}