/*
------------------------------------------------------------
Problem: Reverse Words in a String
Link: https://leetcode.com/problems/reverse-words-in-a-string/

Pattern Used:
String Parsing + Reverse Traversal

Idea:
Extract every word from the string while ignoring
multiple spaces.

Store all words in a vector.

Reverse the vector.

Join all words with a single space.

------------------------------------------------------------
Algorithm

1. Traverse the string.

2. Build the current word.

3. Whenever a space is encountered:
   - If the current word is not empty,
     store it in the vector.
   - Clear the current word.

4. Store the last word (if any).

5. Reverse the vector of words.

6. Join all words separated by one space.

------------------------------------------------------------
Dry Run

s = "  the sky   is blue  "

Extracted Words:

["the", "sky", "is", "blue"]

Reverse:

["blue", "is", "sky", "the"]

Join:

"blue is sky the"

------------------------------------------------------------
Key Observation

Multiple consecutive spaces are ignored because
a word is pushed only when it is non-empty.

Leading and trailing spaces are also skipped
automatically.

------------------------------------------------------------
Time Complexity

O(n)

Explanation:

- Traverse the string once      -> O(n)
- Reverse the vector of words   -> O(k)
- Construct the answer string   -> O(n)

Overall:
O(n)

------------------------------------------------------------
Space Complexity

Auxiliary Space:
O(n)

Reason:
- Vector stores all extracted words.
- Result string stores the final answer.

------------------------------------------------------------

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {

        int ind = -1;

        for (int i = num.length() - 1; i >= 0; i--) {

            if (num[i] % 2 == 1) {
                ind = i;
                break;
            }
        }

        if (ind == -1) {
            return "";
        }

        int j = 0;

        while (j <= ind && num[j] == '0') {
            j++;
        }

        return num.substr(j, ind - j + 1);
    }
};

int main() {

    Solution obj;

    string num = "05247";

    cout << "Number              : " << num << endl;
    cout << "Largest Odd Number  : "
         << obj.largestOddNumber(num)
         << endl;

    return 0;
}
