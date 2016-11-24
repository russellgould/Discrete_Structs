/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab6
SOURCES...: none
*/

#include <iostream>
#include <vector>
using namespace std;

void divide(long long num1, long long num2, long long &q, long long &r);
void convert_bin(long long num, vector<long long> &bin_result);

int main() {
  for (size_t n(0); n < 5; n++) {
    cout << "Please enter a nonnegative decimal integer:";
    long long num(0);
    cin >> num;
    vector<long long> bin_result;
    convert_bin(num, bin_result);
    int r(bin_result.size() % 4);
    if (r > 0) {
      bin_result.insert(bin_result.end(), 4 - r, 0);
    }
    cout << "In binary that is: ";
    for (int i(bin_result.size() - 1); i >= 0; i--) {
      if ((i + 1) % 4 == 0) {
        cout << ' ';
      }
      cout << bin_result[i];
    }
    cout << endl;
    cout << endl;
  }
  return 0;
}

void divide(long long num1, long long num2, long long &q, long long &r) {
  long long a(num1), d(num2);
  r = a;
  q = 0;
  while (r >= d) {
    r -= d;
    q++;
  }
}

void convert_bin(long long num, vector<long long> &bin_result) {
  long long q(num), i(0), r(0);
  while (i == 0 || q != 0) {
    divide(q, 2, q, r);
    bin_result.push_back(r);
    i++;
  }
}
