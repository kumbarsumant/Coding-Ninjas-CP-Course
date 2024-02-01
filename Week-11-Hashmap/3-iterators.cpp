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

  unordered_map<string, int>::iterator it1 = ourmap.find("abc1");
  cout << "The value for key abc1 is " << it1->second << endl;

  // throws error (segmentation fault) if the key is not present.
  // unordered_map<string, int>::iterator it3 = ourmap.find("abc");
  // cout << "The value for key abc1 is " << it3->second;

  // Deleting the key using the iterator
  ourmap.erase(it1);

  unordered_map<string, int>::iterator it3 = ourmap.begin();
  // order is not guaranteed
  while (it3 != ourmap.end()) {
    cout << "Key: " << it3->first << " " << "Value: " << it3->second << endl;
    it3++;
  }

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  vector<int>::iterator it2 = v.begin();
  while (it2 != v.end()) {
    cout << *it2 << endl;
    it2++;
  }

}