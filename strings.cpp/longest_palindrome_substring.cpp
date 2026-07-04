/*
------------------------------------------------------------
Problem: Longest Palindromic Substring
Link: https://leetcode.com/problems/longest-palindromic-substring/

Pattern Used:
Expand Around Center

Idea:
Every palindrome expands symmetrically from
its center.

A palindrome can have:

1. Odd Length
   Center = Single character

   Example:
      aba
       ^

2. Even Length
   Center = Between two characters

   Example:
      abba
       ^^

Expand from every possible center and keep
track of the longest palindrome found.

------------------------------------------------------------
Algorithm

Initialize:

start = 0
maxLength = 1

For every index i:

1. Expand around (i, i)
   -> Odd-length palindrome

2. Expand around (i, i + 1)
   -> Even-length palindrome

Update:

start
maxLength

Return:

s.substr(start, maxLength)

------------------------------------------------------------
Helper Function

expand(s, left, right)

Expand while:

left >= 0
right < n
s[left] == s[right]

After expansion stops,

Palindrome Length =

right - left - 1

If this palindrome is longer than the
current answer,

Update:

start = left + 1
maxLength = length

------------------------------------------------------------
Dry Run

s = "babad"

i = 0

Center = "b"

Palindrome = "b"

---------------------

i = 1

Center = "a"

Expand

b a b

Palindrome = "bab"

Length = 3

Update answer

---------------------

i = 2

Center = "b"

Expand

a b a

Palindrome = "aba"

Length = 3

Same length

---------------------

Answer = "bab"

( "aba" is also correct )

------------------------------------------------------------
Key Observation

Every palindrome has a center.

Instead of checking every possible substring,
expand only from each possible center.

Total Centers:

n odd centers

+
n - 1 even centers

Total = 2n - 1 centers

------------------------------------------------------------
Time Complexity

O(n²)

Reason:

There are O(n) centers.

Each expansion may take O(n).

------------------------------------------------------------
Space Complexity

O(1)

Only a few variables are used.

------------------------------------------------------------
Similar Problems

1. Palindromic Substrings
2. Shortest Palindrome
3. Valid Palindrome
4. Longest Palindrome
5. Manacher's Algorithm (Optimal O(n))
------------------------------------------------------------
*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    void expand(string &s,
                int left,
                int right,
                int &start,
                int &maxLength,
                int n) {

        while (left >= 0 &&
               right < n &&
               s[left] == s[right]) {

            left--;
            right++;
        }

        int len = right - left - 1;

        if (len > maxLength) {
            maxLength = len;
            start = left + 1;
        }
    }

    string longestPalindrome(string s) {

        int n = s.size();

        if (n == 0) {
            return "";
        }

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; i++) {

            // Odd-length palindrome
            expand(s, i, i, start, maxLength, n);

            // Even-length palindrome
            expand(s, i, i + 1, start, maxLength, n);
        }

        return s.substr(start, maxLength);
    }
};

int main() {

    Solution obj;

    string s = "babad";

    cout << "Original String      : " << s << endl;
    cout << "Longest Palindrome   : "
         << obj.longestPalindrome(s)
         << endl;

    return 0;
}