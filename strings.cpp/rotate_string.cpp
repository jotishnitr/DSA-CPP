/*
------------------------------------------------------------
Problem: Rotate String
Link: https://leetcode.com/problems/rotate-string/

Pattern Used:
String Concatenation

Idea:
If goal is a rotation of s,
then it must appear as a substring
of (s + s).

Example:

s = "abcde"

s + s = "abcdeabcde"

All possible rotations of s are present
as substrings in this concatenated string.

So simply check whether goal exists in
(s + s).

------------------------------------------------------------
Algorithm

1. If lengths are different,
   return false.

2. Concatenate:

doubleS = s + s

3. Check if goal is a substring of doubleS.

If found,
return true.

Otherwise,
return false.

------------------------------------------------------------
Dry Run

s = "abcde"
goal = "cdeab"

doubleS =

"abcdeabcde"

Find:

"cdeab"

Substring exists.

Answer = true

------------------------------------------------------------
Example

s = "abcde"
goal = "abced"

doubleS =

"abcdeabcde"

"abced" does not exist.

Answer = false

------------------------------------------------------------
Key Observation

Every possible rotation of a string appears
exactly once as a contiguous substring of
(s + s).

Therefore,

goal is a valid rotation
iff

goal is a substring of (s + s).

------------------------------------------------------------
Time Complexity

Concatenation:
O(n)

Substring Search (find):
O(n)

Overall:
O(n)

------------------------------------------------------------
Space Complexity

O(n)

Reason:
An additional string of length 2n
is created.

------------------------------------------------------------
Similar Problems

1. Implement strStr()
2. Repeated Substring Pattern
3. Is Subsequence
4. Find the Index of the First Occurrence in a String
5. KMP Pattern Matching
------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) {
            return false;
        }

        string doubleS = s + s;

        return doubleS.find(goal) != string::npos;
    }
};

int main() {

    Solution obj;

    string s = "abcde";
    string goal = "cdeab";

    if (obj.rotateString(s, goal)) {
        cout << "Valid Rotation" << endl;
    }
    else {
        cout << "Not a Rotation" << endl;
    }

    return 0;
}