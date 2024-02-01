/*THEORY

A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

There will be 2^n possible subsequence for a string of size n

We will be solving this using recursion, In C++ for returning an array we have to return the pointer to pointing the start of the array. But there will be one issue that we don't get any information about the length of the array. So we will be taking the input string and the output array (with some defined size) as the arguments to the getSubseq function.

APPROACH

1. Base Case: When the string is empty then there is only one possible substring [""] and the return 1 as the length of the subseqence array

2. Take the substring of the input string leaving the first character
"abc" -> after leaving the first character "bc"

3. This substring will be passed to the getSubseq function to call the function recursively. We will assume that this recusrion would get subseq for this small substring and return the length of the subseq array

We assume for string "bc" recursive function would give ["", "c", "b", "bc"] length = 4

4. Now the subsequence that the recursive function returned has all the subsequence without the first character. Now we will take all those subsequence and add the first character in the begining and then add it to the subsequence array

"" -> 'a' + "" = "a" -> at index : 4(length provided by recursive function) + 0
"c" -> 'a' + "c" = "ac" -> at index: 4 + 1 = 5
"b" -> 'a' + "b" = "ab" -> at index: 4 + 2 = 6
"bc" -> 'a'  + "bc" = "abc" -> at index: 4 + 3 = 7

["", "c", "b", "bc", "a", "ac", "ab", "abc"], length = 4 * 2 = 8

5. Since the subsequence array length got doubled after adding the subsequence with first character, we have to return the current length of the subsequence array
*/

#include <iostream>
#include <string>
using namespace std;

int getSubseq(string input, string output[]) {
  if (input.empty()) {
    output[0] = "";
    return 1;
  }

  string smallInput = input.substr(1);
  int smallOutputSize = getSubseq(smallInput, output);
  for (int i = 0; i < smallOutputSize; i++) {
    output[smallOutputSize + i] = input[0] + output[i];
  }
  return 2 * smallOutputSize;
}

int main() {
  string input;
  cin >> input;
  string* output = new string[1000];
  int len = getSubseq(input, output);
  for (int i = 0; i < len; i++) {
    cout << output[i] << endl;
  }
}