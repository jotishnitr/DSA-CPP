/*
------------------------------------------------------------
Problem:
Count Number of Substrings With Exactly K Distinct Characters

LeetCode Equivalent:
https://leetcode.com/problems/subarrays-with-k-different-integers/
(Same pattern; original problem is on arrays)

GeeksforGeeks Practice:
https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

Pattern:
Sliding Window + At Most K Trick


Idea:
Counting substrings with exactly K distinct
characters directly is difficult.

Instead,

Exactly(K) =
AtMost(K) - AtMost(K - 1)

where

AtMost(K)
= Number of substrings having at most
K distinct characters.

------------------------------------------------------------
Why Does This Work?

AtMost(K)

=

Exactly(1)
+
Exactly(2)
+
...
+
Exactly(K)

AtMost(K-1)

=

Exactly(1)
+
Exactly(2)
+
...
+
Exactly(K-1)

Subtracting,

Exactly(K)

=

AtMost(K)

-

AtMost(K-1)

------------------------------------------------------------
Helper Function

atMostKDistinct(s, k)

Returns the number of substrings having
at most K distinct characters.

------------------------------------------------------------
Sliding Window

Maintain

left
right
frequency map

Expand the window by moving right.

If distinct characters become greater
than K,

Shrink the window from the left until
it becomes valid again.

------------------------------------------------------------
Why

count += (right - left + 1)

?

After shrinking,

Window

[left .... right]

is the smallest valid window ending at right.

Every substring ending at right and
starting anywhere between

left ... right

is also valid.

Example

Window

abcdef

left = 2
right = 5

Valid substrings ending at right are

cdef
def
ef
f

Total

= right - left + 1

------------------------------------------------------------
Algorithm

For every right

Add current character.

If distinct characters > K

Shrink window.

After window becomes valid,

count += (right - left + 1)

Return count.

Final Answer

=

atMost(K)

-

atMost(K-1)

------------------------------------------------------------
Dry Run

s = "pqpqs"

k = 2

AtMost(2)

right=0

Window = "p"

Add = 1

-------------------

right=1

Window = "pq"

Add = 2

-------------------

right=2

Window = "pqp"

Add = 3

-------------------

right=3

Window = "pqpq"

Add = 4

-------------------

right=4

Window = "pqpqs"

Distinct = 3

Shrink

Remove p

Still 3 distinct

Remove q

Still 3 distinct

Remove p

Now Window = "qs"

Distinct = 2

Add = 2

Total

=

1+2+3+4+2

=

12

-------------------

AtMost(1)

=

5

-------------------

Exactly(2)

=

12 - 5

=

7

------------------------------------------------------------
Key Observation

Sliding Window efficiently counts
substrings with

At Most K

distinct characters.

Using

Exactly(K)
=
AtMost(K)
-
AtMost(K-1)

converts a difficult problem into two
easy Sliding Window problems.

------------------------------------------------------------
Time Complexity

atMostKDistinct()

O(n)

Both calls

O(n)

Overall

O(n)

------------------------------------------------------------
Space Complexity

O(k)

Frequency map stores at most
K distinct characters.

------------------------------------------------------------
Similar Problems

1. Longest Substring with At Most K Distinct Characters
2. Fruit Into Baskets
3. Longest Repeating Character Replacement
4. Minimum Window Substring
5. Subarrays with K Different Integers
------------------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

    // Returns the number of substrings with at most k distinct characters
    int atMostKDistinct(string s, int k) {

        int left = 0;
        int count = 0;

        unordered_map<char, int> freq;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            while (freq.size() > k) {

                freq[s[left]]--;

                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    // Returns the number of substrings with exactly k distinct characters
    int countSubstrings(string s, int k) {

        return atMostKDistinct(s, k) -
               atMostKDistinct(s, k - 1);
    }
};

int main() {

    Solution obj;

    string s = "pqpqs";
    int k = 2;

    cout << "String : " << s << endl;
    cout << "k      : " << k << endl;

    cout << "Answer : "
         << obj.countSubstrings(s, k)
         << endl;

    return 0;
}