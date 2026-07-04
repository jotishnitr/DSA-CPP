/*
------------------------------------------------------------
Problem: Valid Anagram
Link: https://leetcode.com/problems/valid-anagram/

Pattern Used:
Frequency Counting

Prerequisite:
Strings contain only lowercase English letters.

Idea:
Two strings are anagrams if they contain
the same characters with the same frequency.

Maintain a frequency array of size 26.

- Increment frequency for every character
  in the first string.
- Decrement frequency for every character
  in the second string.

If every frequency becomes zero,
both strings are anagrams.

------------------------------------------------------------
Algorithm

1. If lengths are different,
   return false.

2. Create frequency array:

freq[26] = {0}

3. Traverse first string:

freq[s[i] - 'a']++

4. Traverse second string:

freq[t[i] - 'a']--

5. Check frequency array.

If any frequency is not zero,
return false.

Otherwise,
return true.

------------------------------------------------------------
Dry Run

s = "anagram"
t = "nagaram"

After processing s:

a -> 3
n -> 1
g -> 1
r -> 1
m -> 1

After processing t:

Every frequency becomes 0.

Answer = true

------------------------------------------------------------
Example

s = "rat"
t = "car"

After updates:

r -> 0
a -> 0
t -> 1
c -> -1

Frequency array is not all zeros.

Answer = false

------------------------------------------------------------
Key Observation

If two strings have identical character
frequencies, then they are anagrams.

Using a fixed-size frequency array removes
the need for sorting or hash maps.

------------------------------------------------------------
Time Complexity

O(n)

where n is the length of the strings.

------------------------------------------------------------
Space Complexity

O(1)

Reason:
A fixed-size frequency array of size 26
is used, independent of input size.

------------------------------------------------------------
Similar Problems

1. Group Anagrams
2. Find All Anagrams in a String
3. Isomorphic Strings
4. Ransom Note
5. Determine if Two Strings Are Close
------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        int freq[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "anagram";
    string t = "nagaram";

    if (obj.isAnagram(s, t)) {
        cout << "Strings are Anagrams" << endl;
    }
    else {
        cout << "Strings are Not Anagrams" << endl;
    }

    return 0;
}