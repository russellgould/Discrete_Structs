/*
NAME......: Russ Gould
CRN.......: 11674
ASSIGNMENT: Lab05
SOURCES...: None
*/

// #pragma warning(disable : 4996)

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace chrono;

void printResults(double x, vector<int> coeffs, size_t caseNo,
                  duration<float> &elapsed_time, double result);

int main() {
  time_point<system_clock> start;
  time_point<system_clock> end;

  random_device rd;
  mt19937 engine(rd());
  normal_distribution<> dist1(50, 16);
  normal_distribution<> dist2(0, 7);

  for (size_t n = 2; n < 27; n++) {
    vector<int> coeffs;
    double x;
    // generate random coefficients
    for (size_t i = 0; i < n; i++) {
      coeffs.push_back(static_cast<int>(round(dist1(engine))));
    }
    // generate random x
    x = dist2(engine);
    // evaluate polynomial
    start = system_clock::now();
    double result(0);
    for (int i = (coeffs.size() - 1); i >= 0; i--) {
      result = result * x + coeffs[i];
    }
    end = system_clock::now();
    // display info
    duration<float> elapsed_time = end - start;
    time_t end_time = system_clock::to_time_t(end);

    printResults(x, coeffs, (n - 1), elapsed_time, result);
  }

  return 0;
}

void printResults(double x, vector<int> coeffs, size_t caseNo,
                  duration<float> &elapsed_time, double result) {
  cout << showpoint << fixed << setprecision(2);
  cout << "Case " << caseNo << ": x = " << x << ", ";
  for (size_t i = 0; i < coeffs.size(); i++) {
    if (i == (coeffs.size() - 1)) {
      cout << "a" << i << " = " << coeffs[i];
    } else {
      cout << "a" << i << " = " << coeffs[i] << ", ";
    }
  }
  cout << endl;
  cout << "  Polynomial = ";
  for (int i = coeffs.size() - 1; i >= 0; i--) {
    if (i == 0) {
      cout << coeffs[i];
    } else if (i == 1) {
      cout << coeffs[i] << "(" << x << ") + ";
    } else {
      cout << coeffs[i] << "(" << x << ")^" << (i) << " + ";
    }
  }
  cout << endl;
  cout << "  Result     = " << result << endl;
  cout << showpoint << fixed << setprecision(12);
  cout << "  CPU Time:    " << elapsed_time.count() << endl;
  cout << setprecision(2);
  cout << endl;
}