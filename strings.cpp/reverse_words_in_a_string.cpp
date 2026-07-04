/*
------------------------------------------------------------
Problem: Reverse Words in a String
Link: https://leetcode.com/problems/reverse-words-in-a-string/

Pattern Used:
1. String Parsing + Reverse
2. Reverse Traversal (Optimal)

------------------------------------------------------------
Approach 1: Vector + Reverse

Idea:
- Extract every word from the string while
  ignoring extra spaces.
- Store all words in a vector.
- Reverse the vector.
- Join the words with a single space.

Algorithm

1. Traverse the string.
2. Build the current word.
3. Whenever a space is encountered:
   - If the current word is not empty,
     store it.
   - Clear the current word.
4. Store the last word.
5. Reverse the vector.
6. Join all words with one space.

Time Complexity:
O(n)

Space Complexity:
O(n)

------------------------------------------------------------
Approach 2: Traverse from End (Optimal)

Idea:
Instead of storing every word in a vector,
traverse the string from right to left.

For every word found:
- Extract it using substr().
- Append it directly to the answer.

Extra spaces are skipped automatically.

------------------------------------------------------------
Algorithm

Start from the last character.

1. Skip trailing spaces.

2. Mark the end of the current word.

3. Move left until a space is found.

4. Extract the word using:

substr(i + 1, end - i)

5. Append the word to the answer.

6. Repeat until the entire string is processed.

------------------------------------------------------------
Dry Run

Input:

"  the sky   is blue  "

Start from end

Word = "blue"

Result:

"blue"

--------------------

Next word:

"is"

Result:

"blue is"

--------------------

Next word:

"sky"

Result:

"blue is sky"

--------------------

Next word:

"the"

Result:

"blue is sky the"

------------------------------------------------------------
Key Observation

Traversing from the end naturally produces
the words in reverse order.

Skipping consecutive spaces ensures that
only one space appears between words.

No extra vector or reverse operation is needed.

------------------------------------------------------------
Time Complexity

Approach 1:
O(n)

Approach 2:
O(n)

------------------------------------------------------------
Space Complexity

Approach 1:
O(n)

Approach 2:
O(n)

Reason:
Although no vector is used,
the output string itself requires O(n) space.

Auxiliary Space (excluding output):
O(1)

------------------------------------------------------------
Similar Problems

1. Reverse String
2. Reverse Words in a String III
3. Length of Last Word
4. Reverse Vowels of a String
5. Valid Palindrome
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Approach 1: Vector + Reverse
    string reverseWordsUsingVector(string s) {

        vector<string> words;
        string word = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != ' ') {
                word += s[i];
            }
            else if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }

        if (!word.empty()) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result = "";

        for (int i = 0; i < words.size(); i++) {

            result += words[i];

            if (i < words.size() - 1) {
                result += ' ';
            }
        }

        return result;
    }

    // Approach 2: Traverse from End (Optimal)
    string reverseWords(string s) {

        int i = s.size() - 1;
        string result;

        while (i >= 0) {

            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            if (i < 0) {
                break;
            }

            int end = i;

            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            string word = s.substr(i + 1, end - i);

            if (!result.empty()) {
                result += ' ';
            }

            result += word;
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s = "  the sky   is blue  ";

    cout << "Original String : \"" << s << "\"" << endl;

    cout << "Using Vector    : \""
         << obj.reverseWordsUsingVector(s)
         << "\"" << endl;

    cout << "Traverse from End: \""
         << obj.reverseWords(s)
         << "\"" << endl;

    return 0;
}