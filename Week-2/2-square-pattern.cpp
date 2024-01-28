#include <iostream>
using namespace std;

// PATTERN - 1

// 1111
// 2222
// 3333
// 4444

// number of rows = n (n is the input)
// number of columns = n
// what to print? = row number (i)

void pattern1() {
  int n;
  cin >> n;

  int i = 1;
  while (i <= n) {
    int j = 1;
    while (j <= n) {
      cout << i;
      j++;
    }
    cout << endl;
    i++;
  }
}

// PATTERN - 2

// 1234
// 1234
// 1234
// 1234

// number of rows = n (n is the input)
// number of columns = n
// what to print? = column number (j)

void pattern2() {
  int n;
  cin >> n;

  int i = 1;
  while (i <= n) {
    int j = 1;
    while (j <= n) {
      cout << j;
      j++;
    }
    cout << endl;
    i++;
  }
}

int main() {
  // cout << "Pattern-1 - Input: ";
  // pattern1();
  cout << "Pattern-2 - Input: ";
  pattern2();
}