/*PROBLEM STATEMENT
We are given an array of integers. The array contains the duplicate values, we want to return the vector of integers without duplicate values and the order should be preserved.

input = [1, 2, 2, 3, 2, 1]
output = [1, 2, 3]

input = [1, 4, 3, 2, 4, 2, 1]
output = [1, 4, 3, 2]

APPROACH

1. We will use hashing technique

2. Loop through the given input array, If the number is not present in the map as a key then add it and add the value as true. Also add this to vector

3. If the number already present in the map as key then skip it
*/

// SOLUTION

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicates(int* a, int size) {
  vector<int> result;
  unordered_map<int, bool> seen;

  for (int i = 0; i < size; i++) {
    if (seen.count(a[i]) > 0) {
      continue;
    }
    seen[a[i]] = true;
    result.push_back(a[i]);
  }
  return result;
}

int main() {
  int a[] = { 1, 2, 5, 2, 4, 7, 2, 9, 3, 1 };
  vector<int> output = removeDuplicates(a, 10);
  for (int i = 0; i < output.size(); i++) {
    cout << output[i] << endl;
  }
}