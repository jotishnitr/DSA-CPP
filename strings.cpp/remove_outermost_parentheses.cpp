/*
------------------------------------------------------------
Problem: Remove Outermost Parentheses
Link: https://leetcode.com/problems/remove-outermost-parentheses/

Pattern Used:
Parentheses Depth Tracking

Idea:
A primitive valid parentheses string always has
one outermost opening '(' and one outermost
closing ')' that should be removed.

Track the current nesting level while traversing
the string.

For '(':
- If current level > 0,
  it is not an outer parenthesis,
  so include it.
- Then increase the level.

For ')':
- First decrease the level.
- If new level > 0,
  it is not an outer parenthesis,
  so include it.

------------------------------------------------------------
Algorithm

Initialize:

level = 0
result = ""

Traverse every character:

If '('

    if(level > 0)
        add '('

    level++

Else ')'

    level--

    if(level > 0)
        add ')'

------------------------------------------------------------
Dry Run

s = "(()())(())"

level = 0

(  -> level = 1 (skip)
(  -> add '('
)  -> add ')'
(  -> add '('
)  -> add ')'
)  -> level becomes 0 (skip)

Result = "()()"

(  -> level = 1 (skip)
(  -> add '('
)  -> add ')'
)  -> level becomes 0 (skip)

Final Answer = "()()()"

------------------------------------------------------------
Key Observation

Outer parentheses always occur when:

Opening:
level == 0 before increment

Closing:
level == 0 after decrement

Hence, only append parentheses when
the current nesting level is greater than zero.

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(1)(Excluding the output string)

------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {

        string result = "";
        int level = 0;

        for (char ch : s) {

            if (ch == '(') {

                if (level > 0) {
                    result += ch;
                }

                level++;
            }
            else {

                level--;

                if (level > 0) {
                    result += ch;
                }
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s = "(()())(())";

    cout << "Original String : " << s << endl;
    cout << "Result          : "
         << obj.removeOuterParentheses(s)
         << endl;

    return 0;
}