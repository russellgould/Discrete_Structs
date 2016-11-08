/*
NAME......: Russ Gould
CRN.......: 41726
ASSIGNMENT: Lab4
SOURCES...: none
*/

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num);
void getFactors(int num, vector<int> &factors);

int main() {
  for (int i(0); i < 4; i++) {
    cout << "Please enter a positive integer greater than 1 that you would "
            "like the prime factors of:";
    int num(0);
    cin >> num;
    vector<int> factors;
    if (isPrime(num)) {
      cout << "That number is prime." << endl;
      cout << endl;
    } else if (num <= 1) {
      cout << "That number was not positive and greater than 1." << endl;
      cout << endl;
    } else {
      getFactors(num, factors);
      cout << "The prime factors of " << num << " are: ";
      for (size_t t(0); t < factors.size(); t++) {
        if (t == factors.size() - 1) {
          cout << factors[t] << "." << endl;
        } else {
          cout << factors[t] << ", ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  } else if (num == 2) {
    return true;
  } else if (num % 2 == 0) {
    return false;
  } else {
    for (int t(3); t * t <= num; t++) {
      if (num % t == 0) {
        return false;
      }
    }
  }
  return true;
}

void getFactors(int num, vector<int> &factors) {
  if (isPrime(num)) { // only final factor will satisfy this
    factors.push_back(num);
    return;
  } else {
    for (int t(2); t * t <= num; t++) {
      if (isPrime(t) && num % t == 0) {
        factors.push_back(t);
        getFactors(num / t, factors);
        break;
      }
    }
  }
}
