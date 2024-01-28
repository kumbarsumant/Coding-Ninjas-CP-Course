#include <iostream>
using namespace std;

// 4444
// 4444
// 4444
// 4444

// number of rows = n (n is the given input)
// number of columns in ith row = n
// we have to print the given input n

int main() {
  int n;
  cin >> n;

  int i = 1;
  while (i <= n) {
    int j = 1;
    while (j <= n) {
      cout << n;
      j++;
    }
    cout << endl;
    i++;
  }
}