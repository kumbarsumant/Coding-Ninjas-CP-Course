/*
Problem statement
You are given an array of integers that contain numbers in random order.Write a program to find and return the number which occurs the maximum times in the given input.

If two or more elements are having the maximum frequency, return the element which occurs in the array first.

Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6

Sample Output 1 :
2

Sample Input 2 :
6
7 2 2 4 8 4

Sample Output 2 :
2

Explanation:
Here, both element '2' and element '4' have same frequency but '2' ocurr first in orignal array that's why we are returning '2' as output.
*/

/*
Approach
1. make an unordered array, we will be storing the number as key and their frequency as the value so key:int, value:int

2. make max, index variable
  max: stores the maximum repeatation count (initialise to 0)
  index: stores the index of the maximum repeated number (initialise to 0)

3. loop through the array in reverse order (check note 1), we will store the number as the key and its frequency as the value

4. before adding the key, check if the key already present in the map, if not add the key and initialise it to 1, otherwise increase the frequency by 1.

5. if the key already present then we will be increasing the frequency by 1, at the same time we will check if the max id less than or equal to current number's frequency (check note 2). If yes then update the max=current element's frequency and index=current element index.

6. finally arr[index] element is the one which has the highest frequency

note 1: Reason behind looping the array in reverse order
- There is one condition, if there are two numbers that have the same frequency then the first element with highest frequency is the answer. If we loop from start to end, then we will be getting the last number with highest frequency.

arr = [1, 1, 2, 2]
map {1: 2, 2: 2}, max = 2, index = 3 if we loop from start to end with the above approach
answer = arr[index] = arr[3] = 2
map {1: 2, 2: 2}, max= 2, index = 0 if we loop in reverse order with above approach
answer = arr[index] = arr[0] = 1


note 2: We are checking if the max is equal and lesser than (why not only lesser than?)
- Since we are looping in reverse order, even if the current number's frequency is same as the max, then also we should be updating the index. Because we want the number with highest frequency from begining. If we use only lesser than, then we will be ignoring the number's with equal frequency on the left of the current number.

arr = [1, 1, 2, 2]
map {1: 2, 2: 2}, max = 2, index = 3 if we use condition: max < current number's frequency
answer = arr[index] = arr[3] = 2
map {1: 2, 2: 2}, max= 2, index = 0 if we use condition: max <= current number's frequency
answer = arr[index] = arr[0] = 1
*/

// SOLUTION

#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int arr[], int n) {
  unordered_map<int, int> numberFrequencyMap;

  int max = 0;
  // if all numbers occurs once then first element is the answer
  int index = 0;

  // loop in reverse order
  for (int i = n - 1; i >= 0; i--) {
    if (numberFrequencyMap.count(arr[i] == 0)) {
      numberFrequencyMap[arr[i]] = 1;
    } else {
      numberFrequencyMap[arr[i]] += 1;
      if (max <= numberFrequencyMap[arr[i]]) {
        max = numberFrequencyMap[arr[i]];
        index = i;
      }
    }
  }

  return arr[index];
}

/*
int main() {
  int n;
  cin >> n;

  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  cout << highestFrequency(arr, n);

  delete[] arr;
}
*/

