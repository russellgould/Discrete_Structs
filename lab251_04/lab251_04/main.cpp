/*
NAME......: Russ Gould
CRN.......: 11674
ASSIGNMENT: Lab04
SOURCES...: getDigitLen(), getMaxEntryLen(), and printMatrix() taken from
              previous project for MTH261
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct edge {
  int src;
  int dst;
  int wght;
};

int getDigitLen(int d);
int getMaxEntryLen(int m[][10]);
size_t getMatrixSize(int m[][10]);
void printMatrix(int m[][10]);
void getEdges(int m[][10], vector<edge> &edges);
int circuitFind(int p[], int k);
void circuitUnion(int p[], int x, int y);
bool makesCircuit(vector<edge> &edges);
int getMinEdge(vector<edge> &edges);

int main() {
  int input_matrix[10][10];
  int krusk_matrix[10][10];
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      input_matrix[i][j] = 0;
    }
  }
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      krusk_matrix[i][j] = 0;
    }
  }

  cout << "Please enter the weight values, separated by spaces, one row per "
          "line:"
       << endl;
  string input;
  int buf;
  for (size_t i = 0; i < 10; i++) {
    getline(cin, input);
    stringstream ssin(input);
    int j(0);
    while (ssin >> buf) {
      input_matrix[i][j] = buf;
      j++;
    }
  }

  cout << endl << "The matrix you entered is:" << endl;
  printMatrix(input_matrix);

  vector<edge> E, T;
  edge e;
  e.src = 0;
  e.dst = 0;
  e.wght = 0;

  getEdges(input_matrix, E);

  // Kruskal's Algorithm Body
  //////////////////////////////////////////////////////////////////////////////

  for (size_t i = 0; i < 10; i++) {
    int min(getMinEdge(E));
    // get smallest weight edge in edges
    e = E[min];
    // remove that edge from edges
    E.erase(E.begin() + min);
    // if edge does not make circuit, add e
    T.push_back(e);
    if (makesCircuit(T)) {
      T.erase(T.end() - 1);
    }
  }

  //////////////////////////////////////////////////////////////////////////////

  for (size_t i = 0; i < T.size(); i++) {
    krusk_matrix[T[i].src][T[i].dst] = T[i].wght;
    krusk_matrix[T[i].dst][T[i].src] = T[i].wght;
  }

  cout << endl << "Result of Kruskal's algorithm:" << endl;
  printMatrix(krusk_matrix);

  return 0;
}

int getDigitLen(int d) {
  string result;
  ostringstream conv;
  conv << d;
  result = conv.str();
  return result.length();
}

int getMaxEntryLen(int m[][10]) {
  int max(1);
  for (unsigned i = 0; i < 10; i++) {
    for (unsigned j = 0; j < 10; j++) {
      int check = getDigitLen(m[i][j]);
      if (check > max) {
        max = check;
      }
    }
  }
  return max;
}

size_t getMatrixSize(int m[][10]) {
  size_t size(0);
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      if (m[i][j] > 0) {
        size = i;
      }
    }
  }
  return size + 1;
}

void printMatrix(int m[][10]) {
  int boxSize = getMaxEntryLen(m);
  size_t mSize = getMatrixSize(m);
  cout << endl;
  for (unsigned i = 0; i < mSize; i++) {
    cout << "[";
    for (unsigned j = 0; j < mSize; j++) {
      int d(m[i][j]);
      if (j == 0) {
        cout << setw(boxSize) << setfill(' ') << d;
      } else {
        cout << setw(boxSize + 1) << setfill(' ') << d;
      }
    }
    cout << "]" << endl;
  }
}

void getEdges(int m[][10], vector<edge> &edges) {
  edge buf;
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = i; j < 10; j++) {
      if (m[i][j] > 0) {
        buf.src = i;
        buf.dst = j;
        buf.wght = m[i][j];
        edges.push_back(buf);
      }
    }
  }
}

int circuitFind(int p[], int k) {
  if (p[k] == -1) {
    return k;
  } else {
    return circuitFind(p, p[k]);
  }
}

void circuitUnion(int p[], int x, int y) {
  int xset, yset;
  xset = circuitFind(p, x);
  yset = circuitFind(p, y);
  p[xset] = yset;
}

bool makesCircuit(vector<edge> &edges) {
  bool flag(false);
  int p[45], x, y;
  for (size_t i = 0; i < 45; i++) {
    p[i] = -1;
  }
  for (size_t i = 0; i < edges.size(); i++) {
    x = circuitFind(p, edges[i].src);
    y = circuitFind(p, edges[i].dst);
    if (x == y) {
      flag = true;
    } else {
      circuitUnion(p, x, y);
    }
  }
  return flag;
}

int getMinEdge(vector<edge> &edges) {
  int min(edges[0].wght), index(0);
  for (unsigned j = 0; j < edges.size(); j++) {
    int check = edges[j].wght;
    if (check < min) {
      min = check;
      index = j;
    }
  }
  return index;
}