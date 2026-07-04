/*
------------------------------------------------------------
Problem: Sum of Beauty of All Substrings
Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

Pattern Used:
Enumerate All Substrings + Frequency Counting

Definition:
Beauty of a substring =

Maximum character frequency
-
Minimum character frequency

(Considering only characters present in the
substring.)

The answer is the sum of beauty values of all
possible substrings.

------------------------------------------------------------
Idea

Generate every possible substring.

Maintain the frequency of characters while
extending the substring.

For every new substring:

1. Find maximum frequency.
2. Find minimum frequency.
3. Add (maxi - mini) to the answer.

------------------------------------------------------------
Algorithm

For every starting index:

Create an empty frequency map.

For every ending index:

Increase frequency of current character.

Traverse the frequency map:

Find:

maxi = maximum frequency
mini = minimum frequency

Beauty = maxi - mini

Add it to the answer.

------------------------------------------------------------
Dry Run

s = "aab"

Substrings:

"a"

Frequency:

a = 1

Beauty = 1 - 1 = 0

--------------------

"aa"

Frequency:

a = 2

Beauty = 2 - 2 = 0

--------------------

"aab"

Frequency:

a = 2
b = 1

Beauty = 2 - 1 = 1

--------------------

"ab"

Frequency:

a = 1
b = 1

Beauty = 1 - 1 = 0

--------------------

"b"

Frequency:

b = 1

Beauty = 1 - 1 = 0

Total Beauty = 1

------------------------------------------------------------
Key Observation

Instead of rebuilding frequencies for every
substring,

maintain a frequency map while extending the
ending index.

Only the maximum and minimum frequencies need
to be computed for every substring.

------------------------------------------------------------
Time Complexity

Outer Loop:
O(n)

Inner Loop:
O(n)

Finding maximum and minimum frequency:
O(26)

Overall:

O(26 × n²)

Since the number of lowercase English letters
is fixed (26),

this is effectively:

O(n²)

------------------------------------------------------------
Space Complexity

O(26)

Frequency map stores at most 26 lowercase
characters.

Equivalent to:

O(1)

------------------------------------------------------------
Similar Problems

1. Longest Substring Without Repeating Characters
2. Number of Wonderful Substrings
3. Count Number of Homogenous Substrings
4. Substrings of Size Three with Distinct Characters
5. Minimum Window Substring
------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:

    int beautySum(string s) {

        int n = s.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {

            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {

                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for (auto it : freq) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

int main() {

    Solution obj;

    string s = "aabcb";

    cout << "String      : " << s << endl;
    cout << "Beauty Sum  : "
         << obj.beautySum(s)
         << endl;

    return 0;
}