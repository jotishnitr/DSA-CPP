/*
------------------------------------------------------------
Problem: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/

Pattern Used:
Greedy Traversal + Hash Mapping

Idea:
Roman numerals are generally written from
largest to smallest.

However, when a smaller numeral appears before
a larger numeral, it represents subtraction.

Examples:

IV = 4
IX = 9
XL = 40
XC = 90
CD = 400
CM = 900

Traverse the string from left to right.

For every character:

- If the current value is smaller than the
  next value,
  subtract it.

- Otherwise,
  add it.

------------------------------------------------------------
Algorithm

1. Store Roman numeral values in a hash map.

2. Traverse the string.

For every character:

If current value < next value

→ result -= current value

Else

→ result += current value

3. Return the final result.

------------------------------------------------------------
Dry Run

s = "MCMXCIV"

M = 1000

Next = C (100)

1000 > 100

Add

result = 1000

--------------------

C = 100

Next = M (1000)

100 < 1000

Subtract

result = 900

--------------------

M = 1000

Next = X (10)

Add

result = 1900

--------------------

X = 10

Next = C (100)

Subtract

result = 1890

--------------------

C = 100

Next = I (1)

Add

result = 1990

--------------------

I = 1

Next = V (5)

Subtract

result = 1989

--------------------

V = 5

Last character

Add

result = 1994

Answer = 1994

------------------------------------------------------------
Key Observation

Whenever a smaller Roman numeral appears
before a larger one,

Subtract it.

Otherwise,

Add it.

This greedy rule correctly handles all
Roman numeral combinations.

------------------------------------------------------------
Time Complexity

O(n)

where n is the length of the string.

------------------------------------------------------------
Space Complexity

O(1)

Reason:
The hash map stores only the seven Roman
numerals, which is constant space.

------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < s.size(); i++) {

            if (i + 1 < s.size() &&
                roman[s[i]] < roman[s[i + 1]]) {

                result -= roman[s[i]];
            }
            else {
                result += roman[s[i]];
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s = "MCMXCIV";

    cout << "Roman Number : " << s << endl;
    cout << "Integer      : "
         << obj.romanToInt(s)
         << endl;

    return 0;
}