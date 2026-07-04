/*
------------------------------------------------------------
Problem: Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/

Pattern Used:
Sorting + String Comparison

Idea:
Sort all strings lexicographically.

After sorting:
- The first string becomes the smallest.
- The last string becomes the largest.

The common prefix of these two strings is
guaranteed to be the common prefix of all strings.

Therefore, compare only the first and last strings.

------------------------------------------------------------
Algorithm

1. If the array is empty,
   return "".

2. Sort the array.

3. Take:
   first = strs[0]
   last  = strs[n-1]

4. Compare both strings character by character.

5. Stop when:
   - Characters differ, or
   - One string ends.

6. Return the matched prefix.

------------------------------------------------------------
Dry Run

Input:

["flower","flow","flight"]

After Sorting:

["flight","flow","flower"]

first = "flight"
last  = "flower"

Comparison:

f == f ✔
l == l ✔
i != o ✘

Answer:

"fl"

------------------------------------------------------------
Key Observation

After sorting,

the maximum possible difference occurs between
the first and last strings.

If these two strings share a prefix,
every string lying between them will also
share that prefix.

Hence comparing only the first and last strings
is sufficient.

------------------------------------------------------------
Time Complexity

Sorting:
O(n log n × m)

Comparing first and last strings:
O(m)

Overall:
O(n log n × m)

where

n = number of strings
m = average length of a string

------------------------------------------------------------
Space Complexity

Auxiliary Space:
O(1)

(Note: Ignoring the space used internally by the
sorting algorithm.)


------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.size() == 0) {
            return "";
        }

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        string ans = "";

        int mini = min(first.size(), last.size());

        for (int i = 0; i < mini; i++) {

            if (first[i] != last[i]) {
                break;
            }

            ans += first[i];
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<string> strs = {
        "flower",
        "flow",
        "flight"
    };

    cout << "Longest Common Prefix: "
         << obj.longestCommonPrefix(strs)
         << endl;

    return 0;
}