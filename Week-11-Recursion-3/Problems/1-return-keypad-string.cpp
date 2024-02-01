/*
PROBLEM STATEMENT

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

Return empty string for numbers 0 and 1.

Note :
1. The order of strings are not important.
2. Input and output has already been managed for you.You just have to populate the output array and return the count of elements populated in the output array.

Constraints :
1 <= n <= 10^6

Sample Input:
  23

Sample Output:
  ad
  ae
  af
  bd
  be
  bf
  cd
  ce
  cf

APPROACH:

We will be solving this using the recursion.

1. We will be making an array, that contains the keypad strings corresponding to the number (index)
keystr = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

2. we will hold the last digit of the number and pass the rest to the recursive function.

last digit = number % 10
rest number = number / 10 (integer division)

3. So if we do the above operation then in the base case we will be getting 0 at last, As there are no letters corresponding to 0 and 1, and in the question it is said to return "" in case of 0 and 1.
Base case: if the number <= 1 | output = [""] and return 1 (length of the output array)

4. When we call a function recursively we will assume that it has returned the length of the combination till the previos number and also updated the output array.

5. for integer 23, the number 2 has returned the output array as ["a", "b", "c"]. Now we have to take care of the number 3 (last digit). We will get all the letters correspoding to number 3 i.e., "def".

6. We have to make copy of all the combinations 3 times as "def" has 3 letters. One copy is already provided by the recursive function and another two we will make. While making we will also add the next letter.

["a", "b", "c", // (already given by recursive function), take this as reference for copying
"ae", "be", "ce",  // second copy, we also add 2nd character in "def"
"af", "bf", "cf"]  // third copy, we also add 1st character in "def"

7. In the above step we haven't modified the first copy, becuase we need the referece to copy. Once other copies are completed we have to concatenate the first copy with first character

["ad", "bd", "cd",
"ae", "be", "ce",
"af", "bf", "cf"]
*/

// SOLUTION

#include <iostream>
#include <string>
using namespace std;

const string KEYSTR[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

int keypad(int num, string output[]) {
  // base case
  if (num <= 1) {
    output[0] = "";
    return 1;
  }

  int lastDigit = num % 10;
  int restNumber = num / 10;
  int smallOutputSize = keypad(restNumber, output);
  string letters = KEYSTR[lastDigit];

  for (int i = 1; i < letters.size(); i++) {
    for (int j = 0; j < smallOutputSize; j++) {
      // offset index by (smallOutputSize * i)
      output[smallOutputSize * i + j] = output[j] + letters[i];
    }
  }

  for (int i = 0; i < smallOutputSize; i++) {
    output[i] += letters[i];
  }

  return smallOutputSize * letters.size();
}

// int main() {
//   int num;
//   cin >> num;

//   string output[10000];
//   int count = keypad(num, output);
//   for (int i = 0; i < count && i < 10000; i++) {
//     cout << output[i] << endl;
//   }
//   return 0;
// }
