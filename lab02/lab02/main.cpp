/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab2
SOURCES...: None
*/

#include <iostream>
using namespace std;

bool ifThen(bool P, bool Q);
bool iff(bool P, bool Q);
bool premise(bool P, bool Q, bool R);
bool conclusion(bool P, bool Q, bool R);
bool isValid(bool table[]);

int main() {
  bool table[40]; // for 8 rows & 5 cols, simpler than 2D array
  int i(0);

  for (int p(1); p >= 0; p--) {
    for (int q(1); q >= 0; q--) {
      for (int r(1); r >= 0; r--) {
        table[i++] = p;
        table[i++] = q;
        table[i++] = r;
        table[i++] = premise(p, q, r);
        table[i++] = conclusion(p, q, r);
      }
    }
  }

  cout << "Columns are:" << endl
       << "Column 1: Value of P" << endl
       << "Column 2: Value of Q" << endl
       << "Column 3: Value of R" << endl
       << "Column 4: Truth values of premise" << endl
       << "Column 5: Truth values of conclusion" << endl
       << endl;

  cout << "  1 2 3 4 5" << endl;
  for (size_t j(0); j < 8; j++) {
    cout << j + 1 << " ";
    for (size_t k(0); k < 5; k++) {
      cout << ((table[5 * j + k]) ? "T" : "F") << " ";
    }
    cout << endl;
  }
  cout << endl;

  if (isValid(table)) {
    cout << "Argument is valid." << endl;
  } else {
    cout << "Rows ";
    for (size_t i(0); i < 8; i++) {
      if ((table[5 * i + 3]) && !(table[5 * i + 4])) {
        cout << i + 1 << " ";
      }
    }
    cout << "show where the premise is true but the conclusion is not." << endl;
    cout << "Therefore the argument is not valid." << endl;
  }

  return 0;
}

bool ifThen(bool P, bool Q) { return (!P || Q); }

bool iff(bool P, bool Q) { return (P == Q); }

bool premise(bool P, bool Q, bool R) {
  return iff(((P || Q) && ifThen(Q, R) ^ (P && R)), (R && Q));
}

bool conclusion(bool P, bool Q, bool R) { return (P || R); }

bool isValid(bool table[]) {
  bool valid(1);
  for (size_t i(0); i < 8 && valid; i++) {
    // check if cols 4 & 5 are the same, if not, argument cannot be valid
    if ((table[5 * i + 3]) && !(table[5 * i + 4])) {
      valid = false;
    }
  }
  return valid;
}