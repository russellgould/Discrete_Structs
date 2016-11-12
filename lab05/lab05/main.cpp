/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab5
SOURCES...: none
*/

#include <iostream>
using namespace std;

long long gcd(long long num1, long long num2);
void divide(long long num1, long long num2, long long &q, long long &r);

int main() {
  for (size_t i(0); i < 4; i++) {

    cout << "Please enter the greater integer:";
    long long num1(0);
    cin >> num1;
    cout << "Please enter the lesser integer:";
    long long num2(0);
    cin >> num2;
    cout << endl;

    long long quotient(0), remainder(0);
    divide(num1, num2, quotient, remainder);

    cout << "The GCD of the two numbers is: " << gcd(num1, num2) << endl;
    cout << endl;
    cout << "Dividing " << num1 << " by " << num2 << " gives:" << endl;
    cout << "Quotient : " << quotient << endl;
    cout << "Remainder: " << remainder << endl;
    cout << num1 << " = " << num2 << "(" << quotient << ") + " << remainder
         << endl;
    cout << endl;
  }

  return 0;
}

long long gcd(long long num1, long long num2) {
  long long a(num2), b(num1), r(num1);
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
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