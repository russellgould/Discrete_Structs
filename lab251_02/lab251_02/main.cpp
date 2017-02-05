/*
NAME......: Russ Gould
CRN.......: 11674
ASSIGNMENT: Lab01
SOURCES...: none
*/

#include <iostream>
#include <vector>
using namespace std;

void divide(int num1, int num2, int &q, int &r);
void dec_to_bin(int num, vector<int> &bin_result);
void get_residues(vector<int> &result, int size, int base, int modulus);
int big_mod(int base, int exponent, int modulus);

int main() {
  for (size_t n(0); n < 5; n++) {
    cout << "Please enter the value of the base:";
    int base(0);
    cin >> base;
    cout << "Please enter the value of the exponent:";
    int exponent(0);
    cin >> exponent;
    cout << "Please enter the value of the modulus:";
    int modulus(0);
    cin >> modulus;
    long result(big_mod(base, exponent, modulus));
    cout << base << "^" << exponent << " mod " << modulus << " = " << result
         << endl;
    cout << endl;
  }
  return 0;
}

void divide(int num1, int num2, int &q, int &r) {
  int a(num1), d(num2);
  r = a;
  q = 0;
  while (r >= d) {
    r -= d;
    q++;
  }
}

void dec_to_bin(int num, vector<int> &bin_result) {
  int q(num), i(0), r(0);
  while (i == 0 || q != 0) {
    divide(q, 2, q, r);
    bin_result.push_back(r);
    i++;
  }
}

void get_residues(vector<int> &result, int size, int base, int modulus) {
  for (size_t i = 0; i < size; i++) {
    if (i == 0) {
      result.push_back(base % modulus);
    } else {
      if (result[i - 1] == 0) {
        result.push_back(0);
      } else {
        int res(result[i - 1]);
        result.push_back((res * res) % modulus);
      }
    }
  }
}

int big_mod(int base, int exponent, int modulus) {
  vector<int> binary_exponent;
  dec_to_bin(exponent, binary_exponent);
  vector<int> residues;
  int size(binary_exponent.size());
  get_residues(residues, size, base, modulus);
  long long prod(1);
  for (size_t i = 0; i < size; i++) {
    if (binary_exponent[i] == 1) {
      prod *= residues[i];
    }
  }
  return (prod % modulus);
}
