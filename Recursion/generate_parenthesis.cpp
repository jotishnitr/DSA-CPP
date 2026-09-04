/*
Practice Problem:
LeetCode: https://leetcode.com/problems/generate-parentheses/

Problem: Generate Parentheses

Given n pairs of parentheses, generate all combinations of well-formed
(valid) parentheses.

Approaches:
1. Brute Force
   - Generate every possible string of length 2n using '(' and ')'.
   - Validate each generated string.
   - Time Complexity: O(2^(2n) * n)
   - Space Complexity: O(2^(2n) * n)

2. Optimal (Backtracking)
   - Keep track of the number of opening and closing parentheses used.
   - Add '(' if open < n.
   - Add ')' only if close < open.
   - This prunes all invalid combinations during generation.
   - Time Complexity: O(4^n / √n)   // Catalan Number
   - Space Complexity: O(n)

Key Idea:
- A valid parenthesis string can never have more ')' than '(' at any point.
- Use backtracking to construct only valid prefixes.
- When the string length becomes 2*n, store the answer.

Algorithm:
1. Start with an empty string.
2. If open < n, append '(' and recurse.
3. If close < open, append ')' and recurse.
4. When the string length reaches 2*n, add it to the result.
5. Backtracking automatically explores all valid possibilities.

Example:
Input:
n = 3

Output:
((()))
(()())
(())()
()(())
()()()

Applications:
- Backtracking problems
- Recursive state-space search
- Expression generation
- Combinatorial generation
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //====================================================
    // Brute Force (Generate All + Validate)
    // Time: O(2^(2n) * n)
    // Space: O(2^(2n) * n)
    //====================================================

    bool valid(string curr) {

        int balance = 0;

        for (char c : curr) {

            if (c == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        return balance == 0;
    }

    void generateAllBrute(int n, string curr, vector<string>& result) {

        if (curr.length() == 2 * n) {

            if (valid(curr))
                result.push_back(curr);

            return;
        }

        generateAllBrute(n, curr + "(", result);
        generateAllBrute(n, curr + ")", result);
    }

    vector<string> generateParenthesisBrute(int n) {

        vector<string> result;
        generateAllBrute(n, "", result);

        return result;
    }

    //====================================================
    // Optimal (Backtracking)
    // Time: O(4^n / √n)
    // Space: O(n)
    //====================================================

    void generateAll(int n, string curr, int open, int close,
                     vector<string>& result) {

        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        if (open < n)
            generateAll(n, curr + "(", open + 1, close, result);

        if (close < open)
            generateAll(n, curr + ")", open, close + 1, result);
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        generateAll(n, "", 0, 0, result);

        return result;
    }
};

int main() {

    Solution obj;

    int n = 3;

    cout << "Brute Force:\n";
    vector<string> brute = obj.generateParenthesisBrute(n);

    for (string s : brute)
        cout << s << " ";
    cout << "\n\n";

    cout << "Optimal:\n";
    vector<string> optimal = obj.generateParenthesis(n);

    for (string s : optimal)
        cout << s << " ";

    return 0;
}