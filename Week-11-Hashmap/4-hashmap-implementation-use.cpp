#include <iostream>
#include "ourmap.h"
using namespace std;

int main() {
  OurMap<int> map;
  cout << "Size: " << map.size() << endl;
  for (int i = 0; i < 10; i++) {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    int val = i + 1;
    map.insert(key, val);
    cout << map.getLoadFactor() << endl;
  }
  cout << "Size: " << map.size() << endl;
  map.remove("abc2");
  map.remove("abc7");
  cout << "Size: " << map.size() << endl;

  for (int i = 0; i < 10; i++) {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    cout << "Key: " << key << " Val: " << map.getValue(key) << endl;
  }
}