/*
------------------------------------------------------------
Problem: Isomorphic Strings
Link: https://leetcode.com/problems/isomorphic-strings/

Pattern Used:
Last Occurrence Mapping

Idea:
Two strings are isomorphic if every character
in one string maps to exactly one character
in the other string, and vice versa.

Instead of storing the actual mapping,
store the last index where each character
appeared.

If the last occurrence of the current characters
is different, the mapping is inconsistent.

------------------------------------------------------------
Algorithm

Maintain two arrays:

m1[256] -> Last occurrence of characters in s
m2[256] -> Last occurrence of characters in t

For every index i:

If

m1[s[i]] != m2[t[i]]

→ Mapping is invalid.
→ Return false.

Otherwise,

Update both arrays with (i + 1).

(i + 1) is used because arrays are initially
filled with 0, indicating "not seen yet".

------------------------------------------------------------
Dry Run

s = "egg"
t = "add"

i = 0

e ↔ a

m1['e'] = 0
m2['a'] = 0

Equal

Update:

m1['e'] = 1
m2['a'] = 1

--------------------

i = 1

g ↔ d

m1['g'] = 0
m2['d'] = 0

Equal

Update:

m1['g'] = 2
m2['d'] = 2

--------------------

i = 2

g ↔ d

m1['g'] = 2
m2['d'] = 2

Equal

Update:

m1['g'] = 3
m2['d'] = 3

Answer = true

------------------------------------------------------------
Key Observation

Two characters must always have identical
last occurrence positions.

If they don't,
the mapping is inconsistent.

Using two arrays guarantees a one-to-one mapping
without explicitly storing character pairs.

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(1)

Reason:
Two arrays of fixed size (256) are used,
independent of input size.

------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int m1[256] = {0};
        int m2[256] = {0};

        for (int i = 0; i < s.size(); i++) {

            if (m1[s[i]] != m2[t[i]]) {
                return false;
            }

            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "egg";
    string t = "add";

    if (obj.isIsomorphic(s, t)) {
        cout << "Strings are Isomorphic" << endl;
    }
    else {
        cout << "Strings are Not Isomorphic" << endl;
    }

    return 0;
}