/*
====================================================
README - Generate Binary Strings Without Consecutive 1's
====================================================

Problem:
Generate all binary strings of length n such that no two consecutive
characters are '1'.

Example:
Input:
n = 3

Output:
000
001
010
100
101

----------------------------------------------------
Approach (Backtracking)
----------------------------------------------------

Idea:
Build the binary string one character at a time.

At every position:

1. Always place '0'.
2. Place '1' only if the previous character is not '1'.

This guarantees that invalid strings are never generated,
so no extra validation is required.

Algorithm:
1. If current string length becomes n:
      Store the string.
2. Append '0' and recurse.
3. If previous character is not '1':
      Append '1' and recurse.

----------------------------------------------------
Complexity
----------------------------------------------------

Time Complexity:
O(2^n)

Although some branches are pruned, the number of valid binary
strings still grows exponentially.

Space Complexity:
O(n)

Recursion depth is at most n.
(Result storage is not included.)

----------------------------------------------------
Key Concept
----------------------------------------------------

Instead of generating every binary string and checking validity,
we prune invalid branches immediately.

Condition:
Previous character != '1'
        ↓
Allowed to place '1'

Otherwise,
only '0' can be placed.

This is a classic Backtracking with Pruning problem.

----------------------------------------------------
Similar Problems
----------------------------------------------------

• LeetCode 3211 - Generate Binary Strings Without Adjacent Zeros
  (Similar backtracking idea with a different constraint)

• GeeksforGeeks - Generate all binary strings without consecutive 1's

Topics:
• Recursion
• Backtracking
• Pruning
• String Generation
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //====================================================
    // Optimal (Backtracking with Pruning)
    // Time: O(2^n)
    // Space: O(n)
    //====================================================

    void generate(int n, string s, vector<string>& result) {

        if (s.length() == n) {
            result.push_back(s);
            return;
        }

        generate(n, s + "0", result);

        if (s.empty() || s.back() != '1') {
            generate(n, s + "1", result);
        }
    }

    vector<string> binstr(int n) {

        vector<string> result;
        generate(n, "", result);
        return result;
    }
};

int main() {

    Solution obj;

    int n = 3;

    vector<string> ans = obj.binstr(n);

    cout << "Binary strings without consecutive 1s:\n";

    for (string s : ans) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}