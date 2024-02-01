#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  unordered_map<string, int> ourmap;

  //inserting the key value using pair
  pair<string, int> p("abc", 1);
  ourmap.insert(p);
  ourmap["def"] = 2;

  // size of the map
  cout << "size: " << ourmap.size() << endl; // gives 2

  // get the value from the key
  cout << ourmap.at("abc") << endl;
  cout << ourmap["abc"] << endl;

  // accessing the value from key which is not present
  // cout << ourmap.at("ghi") << endl; // error
  cout << ourmap["ghi"] << endl; // creates new key pair with default value

  cout << "size: " << ourmap.size() << endl; // gives 3

  // check if the key is present using the count method
  if (ourmap.count("ghi") > 0) {
    cout << "ghi key is present" << endl;
    cout << ourmap["ghi"] << endl;
    cout << ourmap.at("ghi") << endl;
  }

  // deleting the key value pair
  ourmap.erase("ghi");
  cout << "size: " << ourmap.size() << endl; // gives 2

  // deleting the key not present
  ourmap.erase("aaa"); // doesn't throws the error
  cout << "size: " << ourmap.size() << endl; // gives 2
}