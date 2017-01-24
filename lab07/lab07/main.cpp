/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab7
SOURCES...: none
*/

#include <iostream>
using namespace std;

void getRoots(float A, float B, float &t1, float &t2, float disc);
void getSolution1(float &C, float &D, float a0, float a1, float t1);
void getSolution2(float &C, float &D, float a0, float a1, float t1, float t2);

int main() {
  for (int i(0); i < 4; i++) {
    float A(0), B(0), C(0), D(0), a0(0), a1(0), t1(1), t2(1), disc(0);
    cout << "Please enter the following values:" << endl;
    cout << "A=";
    cin >> A;
    cout << "B=";
    cin >> B;
    cout << "a0=";
    cin >> a0;
    cout << "a1=";
    cin >> a1;

    disc = (A * A) + (4 * B);

    if (disc < 0) {
      cout << "Complex roots, run away!" << endl;
    } else {
      if (disc == 0) {
        t1 = A / 2;
        getSolution1(C, D, a0, a1, t1);
        cout << endl;
        cout << "The formula would be:" << endl;
        cout << "a_n = (" << C << ")(" << t1 << ")^n + (" << D << ")n(" << t1
             << ")^n" << endl;
      } else {
        getRoots(A, B, t1, t2, disc);
        getSolution2(C, D, a0, a1, t1, t2);
        cout << endl;
        cout << "The formula would be:" << endl;
        cout << "a_n = (" << C << ")(" << t1 << ")^n + (" << D << ")(" << t2
             << ")^n" << endl;
      }

      float a2(a0), a3(a1), a4(0);
      cout << endl;
      cout << "a0= " << a2 << endl;
      cout << "a1= " << a3 << endl;
      for (int i(2); i < 6; i++) {
        a4 = (A * a3) + (B * a2);
        cout << "a" << i << "= " << a4 << endl;
        a2 = a3;
        a3 = a4;
      }
    }
  }
  return 0;
}

void getRoots(float A, float B, float &t1, float &t2, float disc) {
  t1 = (A + sqrt(disc)) / 2;
  t2 = (A - sqrt(disc)) / 2;
}

void getSolution1(float &C, float &D, float a0, float a1, float t1) {
  D = (a1 / t1) - a0;
  C = a0;
}

void getSolution2(float &C, float &D, float a0, float a1, float t1, float t2) {
  D = (a1 - (a0 * t1)) / (t2 - t1);
  C = a0 - D;
}