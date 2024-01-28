/*
Problem statement

You have been given two integer arrays / lists(ARR1 and ARR2) of size N and M, respectively.You need to print their intersection; An intersection for this problem can be defined when both the arrays / lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays / lists.

Note :
Input arrays / lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the second array / list(ARR2).

Constraints :
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec

Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7
Sample Output 1 :
2
3
4

Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1
2
2


Approach

1. Sorting the array and then solving the problem won't work as the order of the arr2 has to be preserved. So we will be using hashmaps to solve this

2. Haspmap store the numbers as the key and the frequency as the value
  key: int, value: int

3. Loop through the first array, add all the numbers and their frequencies in the map

4. Loop through the second array, while looping check if the number (from the array2) is present as a key in the map, then check if the frequency is greater than 0 (note 1). If the element is present then we will decrease its frequeny by 1. Also print the number

note 1: Why to check if the frequency of the number is greater than 0?
consider the below two arrays
arr1 = [1, 2, 3]
arr2 = [1, 1, 2]

after looping through the first array
map: {1: 1, 2: 1, 3: 1}

looping through second array
first element: 1
decrease the frequency of 1, map = {1: 0, 2: 1, 3: 1}, print 1
second element 1
- in this case, key 1 is present but its frequency is 0. That is all 1's present commonly in arr1 and arr2 are completed. Now if again 1 is showing up in arr2 then it is the extra one that is only present in arr2 and not in arr1. So in this case it becomes necessary that we also need to check if the frequency is greater than 0.
*/

// SOLUTION

#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
  unordered_map<int, int> numberFrequencyMap;

  // loop thorugh first array
  for (int i = 0; i < n; i++) {
    if (numberFrequencyMap.count(arr1[i]) == 0) {
      numberFrequencyMap[arr1[i]] = 1;
    } else {
      numberFrequencyMap[arr2[i]] += 1;
    }
  }

  // loop through second array
  for (int i = 0; i < m; i++) {
    // check if number present as key and also check if its frequency is greater than 0
    if (numberFrequencyMap.count(arr2[i]) > 0 && numberFrequencyMap[arr2[i]] > 0) {
      cout << arr2[i] << endl;
      numberFrequencyMap[arr2[i]] -= 1;
    }
  }
}

/*
int main() {
  int n;
  cin >> n;

  int* arr1 = new int[n];

  for (int i = 0; i < n; ++i) {
    cin >> arr1[i];
  }

  int m;
  cin >> m;

  int* arr2 = new int[m];

  for (int i = 0; i < m; ++i) {
    cin >> arr2[i];
  }

  printIntersection(arr1, arr2, n, m);

  delete[] arr1;
  delete[] arr2;
}
*/