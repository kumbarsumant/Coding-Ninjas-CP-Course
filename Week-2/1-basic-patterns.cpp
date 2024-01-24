#include <iostream>
using namespace std;

void pattern1() {
  // PATTERN - 1

  // *****
  // *****
  // *****
  // *****
  // *****

  int n;
  cin >> n;

  int i = 1;
  while (i <= n) {
    int j = 1;
    while (j <= n) {
      cout << "*";
      j++;
    }
    cout << endl;
    i++;
  }
}

int main() {
  cout << "Pattern-1 input: ";
  pattern1();
}


