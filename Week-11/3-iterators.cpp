#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
  unordered_map<string, int> ourmap;
  ourmap["abc1"] = 1;
  ourmap["abc2"] = 2;
  ourmap["abc3"] = 3;
  ourmap["abc4"] = 4;
  ourmap["abc5"] = 5;

  unordered_map<string, int>::iterator it = ourmap.begin();
  // order is not guaranteed
  while (it != ourmap.end()) {
    cout << "Key: " << it->first << " " << "Value: " << it->second << endl;
    it++;
  }

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  vector<int>::iterator it1 = v.begin();
  while (it1 != v.end()) {
    cout << *it1 << endl;
    it1++;
  }

}