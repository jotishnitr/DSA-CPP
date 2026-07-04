/*
------------------------------------------------------------
Problem: Maximum Nesting Depth of the Parentheses
Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

Pattern Used:
Parentheses Depth Tracking

Idea:
Traverse the string while maintaining the
current nesting depth.

- Every '(' increases the depth.
- Every ')' decreases the depth.

The maximum value reached by the depth
during traversal is the maximum nesting depth.

------------------------------------------------------------
Algorithm

Initialize:

depth = 0
ans = 0

Traverse every character:

If '('
→ depth++

If ')'
→ depth--

After every update:

ans = max(ans, depth)

Return ans.

------------------------------------------------------------
Dry Run

s = "(1+(2*3)+((8)/4))+1"

Start:

depth = 0
ans = 0

( → depth = 1 → ans = 1

( → depth = 2 → ans = 2

) → depth = 1

( → depth = 2

( → depth = 3 → ans = 3

) → depth = 2

) → depth = 1

) → depth = 0

Maximum Depth = 3

------------------------------------------------------------
Key Observation

The current nesting depth equals the number
of unmatched opening parentheses encountered
so far.

The highest value of this depth during traversal
is the required answer.

------------------------------------------------------------
Time Complexity

O(n)

where n is the length of the string.

------------------------------------------------------------
Space Complexity

O(1)

------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {

        int depth = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                depth++;
            }

            if (s[i] == ')') {
                depth--;
            }

            ans = max(ans, depth);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "(1+(2*3)+((8)/4))+1";

    cout << "Maximum Nesting Depth: "
         << obj.maxDepth(s)
         << endl;

    return 0;
}