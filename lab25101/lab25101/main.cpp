/*
NAME......: Russ Gould
CRN.......: 11674
ASSIGNMENT: Lab01
SOURCES...: none
*/

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void outputPair(vector<pair<string, string>> vect);
void output(vector<string> vect);
void setCard(vector<string> vect);
void setRoster(vector<string> vect);
vector<string> setUnion(vector<string> setA, vector<string> setB);
vector<string> setIntersect(vector<string> setA, vector<string> setB);
vector<string> setComplement(vector<string> setA, vector<string> setB);
vector<pair<string, string>> setCross(vector<string> setA, vector<string> setB);

int main() {
  cout << "Enter set A:" << endl;
  string input;
  string buf;
  getline(cin, input);
  stringstream ssin(input);
  vector<string> setA;

  while (ssin >> buf) {
    setA.push_back(buf);
  }

  cout << "Enter set B:" << endl;
  string input2;
  string buf2;
  getline(cin, input2);
  stringstream ssin2(input2);
  vector<string> setB;

  while (ssin2 >> buf2) {
    setB.push_back(buf2);
  }

  vector<string> setU = setUnion(setA, setB);
  cout << endl;
  cout << "Union:" << endl;
  output(setU);

  vector<string> setI = setIntersect(setA, setB);
  cout << endl;
  cout << "Intersection:" << endl;
  output(setI);

  vector<string> setC1 = setComplement(setA, setB);
  cout << endl;
  cout << "A - B:" << endl;
  output(setC1);

  vector<string> setC2 = setComplement(setB, setA);
  cout << endl;
  cout << "B - A:" << endl;
  output(setC2);

  vector<pair<string, string>> setProd = setCross(setA, setB);
  cout << endl;
  cout << "Cross Product:" << endl;
  outputPair(setProd);

  cout << endl;
  cout << "Cardinality of Power Set of Cross Product: 2^" << setProd.size()
       << endl;

  return 0;
}

void outputPair(vector<pair<string, string>> vect) {
  cout << "Cardinality: ";
  cout << vect.size() << endl;
  cout << "Roster: ";
  for (size_t i = 0; i < vect.size(); i++) {
    if (vect.size() == 0) {
      cout << "{}";
    } else if (vect.size() == 1) {
      cout << "{"
           << "(" << vect[i].first << "," << vect[i].second << ")"
           << "}";
    } else if (i == 0) {
      cout << "{"
           << "(" << vect[i].first << "," << vect[i].second << ")";
    } else if (i == vect.size() - 1) {
      cout << ", "
           << "(" << vect[i].first << "," << vect[i].second << ")"
           << "}";
    } else {
      cout << ", "
           << "(" << vect[i].first << "," << vect[i].second << ")";
    }
  }
  cout << endl;
}

void output(vector<string> vect) {
  cout << "Cardinality: ";
  setCard(vect);
  cout << "Roster: ";
  setRoster(vect);
}

void setCard(vector<string> vect) { cout << vect.size() << endl; }

void setRoster(vector<string> vect) {
  for (size_t i = 0; i < vect.size(); i++) {
    if (vect.size() == 0) {
      cout << "{}";
    } else if (vect.size() == 1) {
      cout << "{" << vect[i] << "}";
    } else if (i == 0) {
      cout << "{" << vect[i];
    } else if (i == vect.size() - 1) {
      cout << ", " << vect[i] << "}";
    } else {
      cout << ", " << vect[i];
    }
  }
  cout << endl;
}

vector<string> setUnion(vector<string> setA, vector<string> setB) {
  vector<string> result = {};
  for (size_t i = 0; i < setA.size(); i++) {
    result.push_back(setA[i]);
  }
  for (size_t i = 0; i < setB.size(); i++) {
    bool flag = false;
    for (size_t t = 0; t < result.size(); t++) {
      if (setB[i] == result[t]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      result.push_back(setB[i]);
    }
  }
  return result;
}

vector<string> setIntersect(vector<string> setA, vector<string> setB) {
  vector<string> result = {};
  for (size_t i = 0; i < setA.size(); i++) {
    for (size_t t = 0; t < setB.size(); t++) {
      if (setA[i] == setB[t]) {
        result.push_back(setA[i]);
        break;
      }
    }
  }
  return result;
}

vector<string> setComplement(vector<string> setA, vector<string> setB) {
  vector<string> result = {};

  for (size_t i = 0; i < setA.size(); i++) {
    bool flag = false;
    for (size_t t = 0; t < setB.size(); t++) {
      if (setA[i] == setB[t]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      result.push_back(setA[i]);
    }
  }

  return result;
}

vector<pair<string, string>> setCross(vector<string> setA,
                                      vector<string> setB) {
  vector<pair<string, string>> result = {};
  for (size_t i = 0; i < setA.size(); i++) {
    for (size_t t = 0; t < setB.size(); t++) {
      result.push_back(make_pair(setA[i], setB[t]));
    }
  }
  return result;
}
