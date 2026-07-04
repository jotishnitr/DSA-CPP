/*
------------------------------------------------------------
Problem: String to Integer (atoi)
Link: https://leetcode.com/problems/string-to-integer-atoi/

Pattern Used:
String Parsing + Recursion

Idea:
Simulate the behavior of the C/C++ atoi()
function.

Steps:
1. Ignore leading whitespaces.
2. Determine the sign (+/-).
3. Parse consecutive digits.
4. Stop at the first non-digit character.
5. Handle integer overflow and underflow.

------------------------------------------------------------
Algorithm

1. Skip all leading spaces.

2. Check for an optional '+' or '-'
   to determine the sign.

3. Recursively process digits.

For every digit:

num = num * 10 + currentDigit

If number exceeds INT_MAX
or INT_MIN,

return the corresponding limit.

Stop recursion when:
- End of string is reached.
- Current character is not a digit.

Return:

num × sign

------------------------------------------------------------
Recursive Helper

helper(string s, int i, long long num, int sign)

Parameters:

i    -> Current index
num  -> Number formed so far
sign -> Positive or Negative

Returns the final integer after
processing all valid digits.

------------------------------------------------------------
Dry Run

Input:

"   -42"

Skip spaces

Current string:

"-42"

Sign = -1

Read:

4

num = 4

Read:

2

num = 42

End of string

Return:

-42

------------------------------------------------------------
Overflow Example

Input:

"91283472332"

While forming the number,

num becomes larger than INT_MAX.

Return:

2147483647

Input:

"-91283472332"

Return:

-2147483648

------------------------------------------------------------
Key Observation

Parsing stops immediately after the first
non-digit character.

Only the continuous sequence of digits after
optional spaces and sign contributes to
the final answer.

Using long long while constructing the number
prevents intermediate overflow before checking
against integer limits.

------------------------------------------------------------
Time Complexity

O(n)

where n is the length of the input string.

------------------------------------------------------------
Space Complexity

Auxiliary Space:
O(n)

Reason:
Recursive calls can go as deep as the number
of digits processed.

(An iterative implementation would use O(1)
auxiliary space.)

------------------------------------------------------------
Similar Problems

1. Reverse Integer
2. Valid Number
3. Roman to Integer
4. Basic Calculator
5. Parse Integer from String
------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:

    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;

    int helper(string s, int i, long long num, int sign) {

        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(num * sign);
        }

        num = num * 10 + (s[i] - '0');

        if (sign * num <= INT_MIN_VAL) {
            return INT_MIN_VAL;
        }

        if (sign * num >= INT_MAX_VAL) {
            return INT_MAX_VAL;
        }

        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {

        int i = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        int sign = 1;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {

            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
};

int main() {

    Solution obj;

    string s = "   -42";

    cout << "Input  : \"" << s << "\"" << endl;
    cout << "Output : "
         << obj.myAtoi(s)
         << endl;

    return 0;
}